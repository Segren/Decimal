#include "../s21_decimal.h"

bool int256_is_greater(s21_int256 i1, s21_int256 i2) {
  int flag = false;
  int should_break = false;
  for (int j = 7; j >= 0 && !should_break; --j) {
    for (int i = 31; i >= 0 && !should_break; --i) {
      if (get_bit(i1.bits[j], i) > get_bit(i2.bits[j], i)) {
        flag = true;
        should_break = true;
      } else if (get_bit(i1.bits[j], i) != get_bit(i2.bits[j], i)) {
        should_break = true;
      }
    }
  }
  return flag;
}