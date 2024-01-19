#include "../s21_decimal.h"

s21_int256 mantissa_mul(s21_decimal *mantissa_1, s21_decimal *mantissa_2) {
  s21_int256 m1 = decimal_to_int256(mantissa_1);
  s21_int256 m2 = decimal_to_int256(mantissa_2);
  s21_int256 result = {0x0};
  int count = 0;
  for (int i = 0; i < 256; i++) {
    if (get_bit_from_int256(&m2, i)) {
      for (int j = 0; j < i - count; j++) m1 = shift_left(m1);
      result = mantissa_add(m1, result);
      count = i;
    }
  }
  return result;
}

s21_int256 int256_mantissa_mul(const s21_int256 *m1, const s21_int256 *m2) {
  s21_int256 bin_m1 = *m1;
  s21_int256 bin_m2 = *m2;
  s21_int256 result = {0x0};
  int count = 0;
  for (int i = 0; i < 256; i++) {
    if (get_bit_from_int256(&bin_m2, i)) {
      for (int j = 0; j < i - count; j++) bin_m1 = shift_left(bin_m1);
      result = mantissa_add(bin_m1, result);
      count = i;
    }
  }
  return result;
}