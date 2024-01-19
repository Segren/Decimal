#include "../s21_decimal.h"

s21_int256 mantissa_sub(s21_int256 mantissa_1, s21_int256 mantissa_2) {
  s21_int256 result = {0x0};
  uint32_t borrow = 0;

  for (int i = 0; i < 256; i++) {
    int sub = get_bit_from_int256(&mantissa_1, i) -
              get_bit_from_int256(&mantissa_2, i) - borrow;
    borrow = sub < 0;
    sub = abs(sub);
    int256_set_bit(&result, sub % 2, i);
  }
  return result;
}
