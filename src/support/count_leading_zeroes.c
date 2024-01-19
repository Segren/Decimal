#include "../s21_decimal.h"

int count_leading_zeroes(s21_int256 value) {
  int count = 0;

  // Перебор всех 32-битных сегментов
  bool should_break = false;
  for (int i = 7; i >= 0 && !should_break; i--) {
    uint32_t part = value.bits[i];

    // Если текущий сегмент равен 0, все его биты - нули
    if (part == 0) {
      count += 32;
    } else {
      // Подсчет нулей в ненулевом сегменте

      for (int j = 31; j >= 0 && !should_break; j--) {
        if ((part & (1u << j)) == 0) {
          count++;
        } else {
          should_break = true;
        }
      }
    }
  }

  return count;
}
