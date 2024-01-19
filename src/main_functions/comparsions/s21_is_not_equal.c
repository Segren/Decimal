#include "../../s21_decimal.h"

int s21_is_not_equal(s21_decimal dec1, s21_decimal dec2) {
  int flag = FALSE;
  if (is_decimal_valid(&dec1) && is_decimal_valid(&dec2)) {
    flag = !s21_is_equal(dec1, dec2);
  }
  return flag;
}
