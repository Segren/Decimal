#include "../../s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
  int flag = ERROR;
  if (is_decimal_valid(&value)) {
    flag = OK;
    if (value.bits[3] & 0x80000000) {
      flag = s21_truncate(value, result);
      uint8_t expn = get_exponent(&value);
      if ((value.bits[0] != 0 || value.bits[1] != 0 || value.bits[2] != 0) &&
          expn) {
        add_integer(*result, 1, result);
      }
    } else {
      flag = s21_truncate(value, result);
    }
  }
  return flag;
}
