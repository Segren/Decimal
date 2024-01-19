#include "../../s21_decimal.h"

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int status = OK;

  if (result && is_decimal_valid(&value_1) && is_decimal_valid(&value_2)) {
    s21_decimal res = {{0x0}};

    uint8_t sign1 = get_sign(&value_1);
    uint8_t sign2 = get_sign(&value_2);

    if ((sign1 == POSITIVE && sign2 == POSITIVE) ||
        (sign1 == NEGATIVE && sign2 == NEGATIVE)) {
      if (is_dec_zero(value_1) || is_dec_zero(value_2)) {
        *result = res;
      } else {
        status = mul_decimal(&value_1, &value_2, &res);
      }
      set_sign(&res, 0);
    } else if ((sign1 == POSITIVE && sign2 == NEGATIVE) ||
               (sign1 == NEGATIVE && sign2 == POSITIVE)) {
      if (is_dec_zero(value_1) || is_dec_zero(value_2)) {
        *result = res;
      } else {
        status = mul_decimal(&value_1, &value_2, &res);
      }
      set_sign(&res, 1);
    }

    if (get_sign(&res) == NEGATIVE && status == TOO_LARGE_OR_POS_INF) {
      status = TOO_SMALL_OR_NEG_INF;
    }

    *result = res;
  } else {
    status = ERROR;
  }
  return status;
}