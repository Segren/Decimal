#include "../s21_decimal.h"

s21_int256 mantissa_add(s21_int256 mantissa_1, s21_int256 mantissa_2) {
  s21_int256 result = {0x0};
  int carry = 0;

  for (int i = 0; i < 256; i++) {
    int res = (int)get_bit_from_int256(&mantissa_1, i) +
              (int)get_bit_from_int256(&mantissa_2, i) + carry;
    carry = res / 2;
    int256_set_bit(&result, res % 2, i);
  }
  return result;
}