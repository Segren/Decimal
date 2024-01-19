CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11 -g
#V_COMMAND = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=RESULT_VALGRIND.txt
V_COMMAND = valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all -s
L_COMMAND = leaks -atExit --

PATH_TO_OBJ = objects/
PATH_TO_TESTS = test/
PATH_TO_SUP = support/
PATH_TO_MAIN = main_functions/
COV_REPORT = report/
LIB_NAME = s21_decimal.a
EXEC_T = unit_tests

SRC = $(wildcard $(PATH_TO_SUP)*.c) $(shell find $(PATH_TO_MAIN) -name '*.c')
OBJ = $(patsubst %.c, $(PATH_TO_OBJ)%.o, $(SRC))
SRC_T = $(wildcard $(PATH_TO_TESTS)*.c)
OBJ_T = $(patsubst %.c, $(PATH_TO_OBJ)%.o, $(SRC_T))

OS := $(shell uname -s)

ifeq ($(OS), Darwin)
	CFLAGS+=$(shell pkg-config --cflags check) 
	LIBS+=$(shell pkg-config --libs check)
endif

all: $(LIB_NAME)

s21_decimal.a: $(OBJ)
	@ar rc $@ $(OBJ)
	@ranlib $@

test: coverage_flag $(OBJ_T) $(LIB_NAME)
ifeq ($(OS), Darwin)
	$(CC) $(CFLAGS) $(OBJ_T) $(LIB_NAME) $(LIBS) -o $(PATH_TO_TESTS)$(EXEC_T)
	$(PATH_TO_TESTS)./$(EXEC_T)
else
	$(CC) $(CFLAGS) $(OBJ_T) $(LIB_NAME) -o $(PATH_TO_TESTS)$(EXEC_T) -lcheck -lsubunit -lrt -lpthread -lm
	$(PATH_TO_TESTS)./$(EXEC_T)
endif

$(PATH_TO_OBJ)%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

format-check:
	@cp ../materials/linters/.clang-format ./
	@find . -name '*.c' -o -name '*.h' | xargs clang-format -n
	@rm .clang-format

format:
	@cp ../materials/linters/.clang-format ./
	@find . -name '*.c' -o -name '*.h' | xargs clang-format -i
	@rm .clang-format

cppcheck:
	@find . -name '*.c' -o -name '*.h' | xargs cppcheck --enable=all --suppress=missingIncludeSystem

valgrind:
	@if [ -f "$(PATH_TO_TESTS)$(EXEC_T)" ]; then \
        $(V_COMMAND) ./$(PATH_TO_TESTS)$(EXEC_T); \
    else \
        echo "Test executable not found."; \
    fi

leaks:
	@if [ -f "$(PATH_TO_TESTS)$(EXEC_T)" ]; then \
        $(L_COMMAND) ./$(PATH_TO_TESTS)$(EXEC_T); \
    else \
        echo "Test executable not found."; \
    fi

coverage_flag:
	$(eval CFLAGS += --coverage)

sanitize_flag:
	$(eval CFLAGS += -fsanitize=address -fsanitize=leak)

sanitize: sanitize_flag test
	./$(PATH_TO_TESTS)$(EXEC_T)

gcov_report: coverage_flag test
	rm -rf $(PATH_TO_OBJ)$(PATH_TO_TESTS)*.gcno
	rm -rf $(PATH_TO_OBJ)$(PATH_TO_TESTS)*.gcda
	gcov -b -l -p -c $(OBJ)
	gcovr -o $(COV_REPORT)gcov_report.html --html --html-details
	rm -rf *.info && rm -rf *.gcov
	@if command -v xdg-open > /dev/null; then \
        xdg-open $(COV_REPORT)gcov_report.html; \
    elif command -v open > /dev/null; then \
        open $(COV_REPORT)gcov_report.html; \
    else \
        echo "Cannot open browser. Please open '$(COV_REPORT)gcov_report.html' manually."; \
    fi

clean:
	find $(PATH_TO_OBJ) -name '*.o' -exec rm {} +
	find $(PATH_TO_OBJ) -name '*.gcno' -exec rm {} +
	find $(PATH_TO_OBJ) -name '*.gcda' -exec rm {} +
	rm -rf $(LIB_NAME) && rm -rf $(PATH_TO_TESTS)$(EXEC_T)
	rm -rf $(COV_REPORT)*.css && rm -rf $(COV_REPORT)*.html
	rm -rf *.info && rm -rf *.gcov
	rm -rf RESULT_VALGRIND.txt gcov_*

.PHONY: all cppcheck format format-check test valgrind leaks clean gcov_report
