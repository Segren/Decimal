#include "../s21_decimal.h"

int sub_decimal(s21_decimal *dec_1, s21_decimal *dec_2, s21_decimal *result) {
  int status = OK;
  s21_int256 mantissa_1 = {0};
  s21_int256 mantissa_2 = {0};
  align_exp(dec_1, dec_2, &mantissa_1, &mantissa_2);

  // общая мантисса
  s21_int256 res = mantissa_sub(mantissa_1, mantissa_2);
  // общая экспонента
  uint8_t mul_exp = get_exponent(dec_1);

  // рассмотрим насколько надо поделить результат, чтобы вписать его в decimal
  int align_div = int256_div_to_decimal(res);

  // общая экспонента результата
  int aligned_exp = (int)mul_exp - align_div;

  // оценка экспоненты результата
  if (aligned_exp < 0) {
    status = TOO_LARGE_OR_POS_INF;
    *result = get_inf_result();
  } else {
    s21_int256 ten = {{0x000000A, 0x0, 0x0, 0x0}};
    // если число надо делить на больше чем 10^28, то уменьшаем его
    while (align_div > 28) {
      res = mantissa_div(&res, &ten, NULL);
      --align_div;
    }

    // если слишком много цифр после запятой
    if (aligned_exp > 28) {
      int temp_exp = 28;
      align_div = aligned_exp - temp_exp + align_div;
      aligned_exp = 28;
    }

    s21_int256 remainder = {{0x0}};
    s21_int256 ten_pow = int256_pow_ten(align_div);

    // округляем результат чтобы он поместился в decimal
    res = mantissa_div(&res, &ten_pow, &remainder);
    // устанавливаем степень для остатка, чтобы провести банковское округление
    s21_decimal dec_remainder = {{0x0}};
    int256_to_decimal(&remainder, &dec_remainder);
    set_exponent(&dec_remainder, align_div);
    // выполняем банковское округление
    round_uint256_bankers(&res, &dec_remainder);

    // смотрим верен ли результат и ставим мантиссу
    int last_bit_index = find_last_significant_bit(&res);
    if (last_bit_index >= 96) {
      status = TOO_LARGE_OR_POS_INF;
      *result = get_inf_result();
    } else {
      for (int i = 0; i < 3; i++) {
        result->bits[i] = res.bits[i];
      }
    }
    // ставим экспоненту
    set_exponent(result, aligned_exp);
    // знак всегда положительный: sign=0
    set_sign(result, 0);
  }
  return status;
}