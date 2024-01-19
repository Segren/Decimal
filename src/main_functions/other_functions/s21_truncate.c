#include "../../s21_decimal.h"

int s21_truncate(s21_decimal value, s21_decimal *result) {
  int flag = ERROR;
  if (is_decimal_valid(&value)) {
    int expn = get_exponent(&value);
    s21_decimal temp = value;
    for (int i = 0; i < expn; i++) {
      divide_by_integer(temp, 10, &temp);
      set_exponent(&temp, expn - i - 1);
    }
    *result = temp;
    flag = OK;
  }
  return flag;
}
