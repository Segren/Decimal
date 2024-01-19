#include "../../s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  int flag = ERROR;
  if (is_decimal_valid(&value)) {
    for (int i = 0; i < 4; i++) {
      result->bits[i] = value.bits[i];
    }
    if (get_sign(&value) == 1) {
      set_sign(result, 0);
    } else {
      set_sign(result, 1);
    }
    flag = OK;
  }
  return flag;
}
