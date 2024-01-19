#include "../support/s21_support.h"

void init_with_zero_decimal(s21_decimal *dec) {
  if (dec) {
    dec->bits[0] = 0;
    dec->bits[1] = 0;
    dec->bits[2] = 0;
    dec->bits[3] = 0;
  }
}

uint8_t get_sign(s21_decimal *dec) { return (dec->bits[3] & 1u << 31) != 0; }

void set_sign(s21_decimal *dec, uint8_t sign) {
  // clear 31 bit with mask 0x7FFFFFFF, without changes in other bits
  dec->bits[3] &= 0x7FFFFFFF;
  // set new value in 31 bit
  dec->bits[3] |= (sign & 1u) << 31;
}

uint8_t get_exponent(const s21_decimal *dec) {
  // get bits from 16 to 23 in four int
  uint8_t exponent = (dec->bits[3] >> 16) & 0xFF;
  return exponent;
}

bool set_exponent(s21_decimal *dec, uint8_t exponent) {
  bool result = true;
  if (dec && exponent < 29) {
    // shift to 16 bit and clear next bits with mask 0xFF
    dec->bits[3] &= ~(0xFF << 16);
    // set new exponent in bits from 16 to 23
    dec->bits[3] |= exponent << 16;
  } else {
    result = false;
  }
  return result;
}

bool is_decimal_valid(const s21_decimal *dec) {
  bool result = true;

  if (dec) {
    // check zero value in unused bits (from 0 to 15 and from 24 to 30)
    if ((dec->bits[3] & 0xFFFF) != 0 || (dec->bits[3] >> 24 & 0x7F) != 0) {
      result = false;
    }
    // check exponent value
    if (get_exponent(dec) > 28) {
      result = false;
    }
  } else {
    result = false;
  }

  return result;
}

uint8_t get_bit(uint32_t number, uint8_t index) {
  uint8_t result = 0;
  if (index < 32) {
    result = (number >> index) & 1u;
  }
  return result;
}

uint8_t get_bit_from_int256(s21_int256 *man, uint8_t index) {
  // Находим индекс слова (32-битного блока)
  uint8_t word_index = index / 32;
  // Находим индекс бита внутри слова
  uint8_t bit_index = index % 32;
  uint8_t result = (man->bits[word_index] >> bit_index) & 1u;
  return result;
}

int divide_by_integer(s21_decimal value, int num, s21_decimal *result) {
  uint64_t buffer = 0ull;
  for (int i = 2; i >= 0; i--) {
    uint32_t div = (buffer + value.bits[i]) % num;
    uint64_t div_buffer = (buffer + value.bits[i]) / num;
    result->bits[i] = (unsigned)div_buffer;
    buffer = div;
    buffer = buffer << 32;
  }
  return 0;
}

int add_integer(s21_decimal value, int num, s21_decimal *result) {
  int flag = OK;
  uint64_t buffer = 0ull + num;
  for (int i = 0; i < 3; i++) {
    buffer += value.bits[i];
    value.bits[i] = (unsigned)buffer;
    buffer >>= 32;
  }
  if (!buffer) {
    for (int i = 0; i < 4; i++) {
      result->bits[i] = value.bits[i];
    }
  } else {
    flag = 1;
  }
  return flag;
}

// остаток от деления decimal на целое число
int div_by_integer(s21_decimal value, int num) {
  uint64_t buffer = 0ull;
  uint64_t div = 0;
  for (int i = 2; i >= 0; i--) {
    div = (buffer + value.bits[i]) % num;
    buffer = div << 32;
  }
  return div;
}
