#include "../../s21_decimal.h"

int s21_is_equal(s21_decimal dec1, s21_decimal dec2) {
  int flag = FALSE;
  if (is_decimal_valid(&dec1) && is_decimal_valid(&dec2)) {
    s21_int256 m1 = {0x0};
    s21_int256 m2 = {0x0};
    align_exp(&dec1, &dec2, &m1, &m2);

    if (get_sign(&dec1) == get_sign(&dec2)) {
      flag = TRUE;
      for (int i = 7; flag && i >= 0; --i) {
        if (m1.bits[i] != m2.bits[i]) {
          flag = FALSE;
        }
      }
    }
  }
  return flag;
}
