#include "../../s21_decimal.h"

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int status = OK;
  if (result && is_decimal_valid(&value_1) && is_decimal_valid(&value_2) &&
      !is_dec_zero(value_2)) {
    s21_decimal res = {{0x0}};
    init_with_zero_decimal(result);

    uint8_t sign1 = get_sign(&value_1);
    uint8_t sign2 = get_sign(&value_2);

    if ((sign1 == POSITIVE && sign2 == POSITIVE) ||
        (sign1 == NEGATIVE && sign2 == NEGATIVE)) {
      if (!is_dec_zero(value_1)) status = div_decimal(&value_1, &value_2, &res);
      *result = res;
      set_sign(result, 0);
    } else if ((sign1 == POSITIVE && sign2 == NEGATIVE) ||
               (sign1 == NEGATIVE && sign2 == POSITIVE)) {
      if (!is_dec_zero(value_1)) status = div_decimal(&value_1, &value_2, &res);
      *result = res;
      set_sign(result, 1);
    }

    if (get_sign(result) == NEGATIVE && status == TOO_LARGE_OR_POS_INF) {
      status = TOO_SMALL_OR_NEG_INF;
    }
  } else if (is_dec_zero(value_2)) {
    status = DIV_BY_ZERO;
  } else {
    status = ERROR;
  }
  return status;
}