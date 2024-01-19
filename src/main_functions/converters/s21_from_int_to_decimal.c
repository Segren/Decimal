#include "../../s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int result_conv = OK;
  if (is_decimal_valid(dst)) {
    init_with_zero_decimal(dst);
    if (src < 0) {
      set_sign(dst, 1);
      src = -src;
    }
    dst->bits[0] = src;
  } else {
    result_conv = ERROR;
  }

  return result_conv;
}