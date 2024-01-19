#include "../s21_decimal.h"

int int256_to_decimal(s21_int256 *man, s21_decimal *dst) {
  int status = OK;
  int last_bit_index = find_last_significant_bit(man);
  if (last_bit_index < 96) {
    for (int i = 0; i < 3; i++) {
      dst->bits[i] = man->bits[i];
    }
  } else {
    status = ERROR;
  }
  return status;
}
