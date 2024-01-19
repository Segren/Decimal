#include "../../s21_decimal.h"

uint8_t get_dec_bit(const s21_decimal *dec, int index) {
  int array_index = index / 32;
  int bit_offset = index % 32;
  uint8_t bit_value = (dec->bits[array_index] >> bit_offset) & 1;
  return bit_value;
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int result_conv = OK;
  if (dst && is_decimal_valid(&src)) {
    *dst = 0.0f;
    double temp = 0.0;
    for (int i = 0; i < 96; i++) {
      temp += get_dec_bit(&src, i) * pow(2, i);
    }
    temp = temp * pow(10, -get_exponent(&src));
    if (get_sign(&src)) {
      temp = -temp;
    }
    *dst = (float)temp;
  } else {
    result_conv = 1;
  }
  return result_conv;
}