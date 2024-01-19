#include "../s21_decimal.h"

bool is_zero(s21_int256 number) {
  bool result_check = true;
  for (int i = 0; i < 8 && result_check; i++) {
    if (number.bits[i] != 0) {
      result_check = false;
    }
  }
  return result_check;
}

bool is_dec_zero(s21_decimal number) {
  bool result_check = true;
  for (int i = 0; i < 3 && result_check; i++) {
    if (number.bits[i] != 0) {
      result_check = false;
    }
  }
  return result_check;
}