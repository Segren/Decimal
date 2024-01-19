#include "../../s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int status = OK;

  if (result && is_decimal_valid(&value_1) && is_decimal_valid(&value_2)) {
    s21_decimal res;
    init_with_zero_decimal(result);
    init_with_zero_decimal(&res);

    uint8_t sign1 = get_sign(&value_1);
    uint8_t sign2 = get_sign(&value_2);

    if (sign1 == POSITIVE && sign2 == POSITIVE) {
      status = add_positive_decimal(&value_1, &value_2, &res);
    } else if (sign1 == POSITIVE && sign2 == NEGATIVE) {
      set_sign(&value_2, 0);
      status = s21_sub(value_1, value_2, &res);
    } else if (sign1 == NEGATIVE && sign2 == POSITIVE) {
      set_sign(&value_1, 0);
      status = s21_sub(value_2, value_1, &res);
    } else if (sign1 == NEGATIVE && sign2 == NEGATIVE) {
      status = add_positive_decimal(&value_1, &value_2, &res);
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