#include "../s21_decimal.h"

bool int256_set_bit(s21_int256 *dec, uint8_t number, uint8_t index) {
  bool result = true;
  if (dec) {
    int mask = 1u << (index % 32);
    if (number == 0) {
      dec->bits[index / 32] = dec->bits[index / 32] & ~mask;
    } else {
      dec->bits[index / 32] = dec->bits[index / 32] | mask;
    }
  } else {
    result = false;
  }
  return result;
}
