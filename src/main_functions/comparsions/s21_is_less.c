#include "../../s21_decimal.h"

int s21_is_less(s21_decimal dec1, s21_decimal dec2) {
  int flag = FALSE;
  if (is_decimal_valid(&dec1) && is_decimal_valid(&dec2)) {
    s21_int256 m1 = {0x0};
    s21_int256 m2 = {0x0};
    align_exp(&dec1, &dec2, &m1, &m2);

    if (get_sign(&dec1) == get_sign(&dec2)) {
      int sign = get_sign(&dec1);
      int should_break = FALSE;
      for (int j = 7; j >= 0 && !should_break; --j) {
        for (int i = 31; i >= 0 && !should_break; --i) {
          if ((sign == 0 && get_bit(m1.bits[j], i) < get_bit(m2.bits[j], i)) ||
              (sign == 1 && get_bit(m1.bits[j], i) > get_bit(m2.bits[j], i))) {
            flag = TRUE;
            should_break = TRUE;
          } else if (get_bit(m1.bits[j], i) != get_bit(m2.bits[j], i)) {
            should_break = TRUE;
          }
        }
      }
    } else if (get_sign(&dec1) > get_sign(&dec2)) {
      flag = TRUE;
    }
  }
  return flag;
}
