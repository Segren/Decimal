#include "test_runner.h"

int main(void) {
  Suite *array_tests[] = {s21_equal_cases(),
                          s21_not_equal_cases(),
                          s21_is_less_cases(),
                          s21_is_greater_cases(),
                          s21_is_less_or_equal_cases(),
                          s21_is_greater_or_equal_cases(),
                          s21_negate_cases(),
                          s21_truncate_cases(),
                          s21_floor_cases(),
                          s21_round_cases(),
                          s21_mul_cases(),
                          s21_div_cases(),
                          s21_add_cases(),
                          s21_sub_cases(),
                          s21_from_int_to_decimal_cases(),
                          s21_from_decimal_to_int_cases(),
                          s21_from_float_to_decimal_cases(),
                          s21_from_decimal_to_float_cases()};

  size_t size = 18;

  for (size_t i = 0; i < size; i++) {
    printf("%s\n", SEP);
    printf("TEST NUMBER: %zu \n", i + 1);

    SRunner *runner = srunner_create(array_tests[i]);

    srunner_set_fork_status(runner, CK_NOFORK);
    srunner_run_all(runner, CK_NORMAL);
    srunner_free(runner);
  }

  return 0;
}
