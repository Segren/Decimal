#include "../../s21_decimal.h"

int check_valid_dec_for_conv_to_int(s21_decimal *dec) {
  return (dec->bits[1] == 0 && dec->bits[2] == 0 &&
          ((get_sign(dec) && dec->bits[0] <= 2147483648) ||
           (!get_sign(dec) && dec->bits[0] <= 2147483647)));
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int result_conv = OK;
  if (dst && is_decimal_valid(&src)) {
    s21_decimal trunc;
    init_with_zero_decimal(&trunc);
    result_conv = s21_truncate(src, &trunc);
    if (!result_conv && check_valid_dec_for_conv_to_int(&trunc)) {
      *dst = (int)trunc.bits[0];
      if (get_sign(&src)) {
        *dst = -(*dst);
      }
    } else {
      result_conv = ERROR;
    }
  } else {
    result_conv = ERROR;
  }
  return result_conv;
}