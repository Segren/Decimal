#include "../s21_decimal.h"

// функция для трансформации остатка
// умножаем остаток на 10 и делим на value_2 и так по кругу
uint8_t remainder_transform(s21_int256 *res, const s21_int256 *eq_value_2,
                            s21_int256 *remainder) {
  uint8_t exp = 0;
  s21_int256 bin_res = *res;
  s21_int256 bin_remainder = *remainder;

  bool should_break = false;
  while (exp < 28 && !is_zero(bin_remainder) && !should_break) {
    // сохраняем значения, чтобы вернуть в случае переполнения
    s21_int256 save_bin_res = bin_res;
    s21_int256 save_bin_remainder = bin_remainder;
    // расчеты
    s21_int256 ten = {{0x000000A, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}};
    bin_res = int256_mantissa_mul(&bin_res, &ten);
    bin_remainder = int256_mantissa_mul(&bin_remainder, &ten);
    s21_int256 bin = mantissa_div(&bin_remainder, eq_value_2, &bin_remainder);
    bin_res = mantissa_add(bin_res, bin);
    // случай с переполнением
    int l_bit = find_last_significant_bit(&bin_res);
    if (l_bit >= 96) {
      bin_res = save_bin_res;
      bin_remainder = save_bin_remainder;
      should_break = true;
    }
    if (!should_break) {
      exp++;
    }
  }

  *res = bin_res;
  *remainder = bin_remainder;

  return exp;
}