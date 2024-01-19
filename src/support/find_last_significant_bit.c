#include "../s21_decimal.h"

// Определение последнего индекса значащего бита в s21_int256
int find_last_significant_bit(const s21_int256 *man) {
  for (int i = 7; i >= 0; i--) {
    for (int j = 31; j >= 0; j--) {
      if ((man->bits[i] >> j) & 1) {
        return (i * 32) + j;
      }
    }
  }
  // Если все биты нулевые, возвращаем -1
  return -1;
}