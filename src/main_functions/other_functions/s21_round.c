#include "../../s21_decimal.h"

int s21_round(s21_decimal value, s21_decimal *result) {
  int flag = ERROR;
  if (is_decimal_valid(&value)) {
    flag = OK;
    for (int i = 0; i < 4; i++) {
      result->bits[i] = value.bits[i];
    }
    int expm = get_exponent(&value);
    if (expm) {
      result->bits[3] = value.bits[3] & 0x80000000;
      for (; expm > 1; expm--) {
        divide_by_integer(*result, 10, result);
      }
      int div = div_by_integer(*result, 10);
      int tmp = (div >= 5) ? 1 : 0;

      flag = s21_truncate(value, result);
      if (tmp && !flag) {
        add_integer(*result, 1, result);
      }
    }
  }
  return flag;
}
