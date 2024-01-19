#include "../s21_decimal.h"

// функция для сдвига влево (увеличения)
s21_int256 shift_left(s21_int256 number) {
  s21_int256 result = {0x0};
  for (int i = 0; i < 8; i++) {
    result.bits[i] = number.bits[i] << 1;
  }
  for (int i = 1; i < 8; i++) {
    uint32_t mask = 0x80000000U;
    uint32_t previous_element = number.bits[i - 1];
    uint32_t carry = previous_element & mask;
    carry = carry >> 31;
    result.bits[i] |= carry;
  }
  return result;
}
