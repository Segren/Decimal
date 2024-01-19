#include "../s21_decimal.h"

s21_int256 int256_pow_ten(uint32_t pow) {
  s21_int256 result = {0x0};
  s21_int256 ten = {{0x000000A, 0x0, 0x0, 0x0}};
  result.bits[0] = 1U;

  for (uint32_t i = 0; i < pow; i++) {
    result = int256_mantissa_mul(&result, &ten);
  }
  return result;
}