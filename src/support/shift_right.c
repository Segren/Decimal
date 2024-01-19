#include "../s21_decimal.h"

// функция для сдвига вправо (уменьшения)
s21_int256 shift_right(s21_int256 number) {
  s21_int256 result = {0};
  for (int i = 0; i < 8; i++) {
    result.bits[i] = number.bits[i] >> 1;
  }
  for (int i = 6; i >= 0; i--) {
    uint32_t mask = 0x00000001U;
    uint32_t next_element = number.bits[i + 1];
    uint32_t carry = next_element & mask;
    carry = carry << 31;
    result.bits[i] |= carry;
  }
  return result;
}