#include "../s21_decimal.h"

s21_int256 decimal_to_int256(s21_decimal *dec) {
  s21_int256 mantissa = {0x0};
  for (int i = 0; i < 3; i++) {
    mantissa.bits[i] = dec->bits[i];
  }
  return mantissa;
}