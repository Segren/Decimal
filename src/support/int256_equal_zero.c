#include "../s21_decimal.h"

bool int256_equal_zero(s21_int256 res) {
  bool flag = true;
  for (int i = 0; i < 8 && flag; i++) {
    if (res.bits[i] != 0x0) {
      flag = false;
    }
  }
  return flag;
}
