#include "../s21_decimal.h"

s21_int256 mantissa_div(const s21_int256 *mantissa_1,
                        const s21_int256 *mantissa_2, s21_int256 *remainder) {
  s21_int256 result = {0x0};
  s21_int256 divisor = *mantissa_2;
  s21_int256 dividend = *mantissa_1;
  // частичный остаток
  s21_int256 bin_remainder = {0x0};
  // частное
  s21_int256 quotient = {0x0};

  // cлучай если divisor больше dividend
  if (int256_is_greater(divisor, dividend)) {
    if (remainder != NULL) {
      bin_remainder = *mantissa_1;
    }
  } else if (!is_zero(dividend)) {
    // если делимое равно нулю - то результат и остаток остаются равны нулю

    // определение кол-ва сдвигов
    int shift = count_leading_zeroes(divisor) - count_leading_zeroes(dividend);
    int shift_copy =
        count_leading_zeroes(divisor) - count_leading_zeroes(dividend);

    // сдвиг делителя
    for (int i = 0; i < shift; i++) {
      divisor = shift_left(divisor);
    }

    // нужно ли проводить вычитание. (на первой итерации всегда)
    int sub_required = 1;
    // деление столбиком
    while (shift >= 0) {
      if (sub_required) {
        bin_remainder = mantissa_sub(dividend, divisor);
      } else {
        bin_remainder = mantissa_add(dividend, divisor);
      }

      quotient = shift_left(quotient);
      if (get_bit_from_int256(&bin_remainder, INT256_MAX_BITS - 1) == 0) {
        int256_set_bit(&quotient, 1, 0);
      }
      // сдвигаем делимое для следующей итерации цикла
      dividend = shift_left(bin_remainder);

      if (get_bit_from_int256(&bin_remainder, INT256_MAX_BITS - 1) == 0) {
        sub_required = 1;
      } else {
        sub_required = 0;
      }
      shift--;
    }
    // смотрим, требуется ли коррекция остатка
    if (get_bit_from_int256(&bin_remainder, INT256_MAX_BITS - 1)) {
      bin_remainder = mantissa_add(bin_remainder, divisor);
    }
    // возвращаем частичный остаток
    for (int j = 0; j < shift_copy; j++) {
      bin_remainder = shift_right(bin_remainder);
    }

    result = quotient;
  }
  // Установка остатка
  if (remainder != NULL) {
    *remainder = bin_remainder;
  }
  return result;
}
