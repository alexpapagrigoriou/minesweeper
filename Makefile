TARGET := minesweeper

CC := gcc

SRC_DIR := src

BUILD_DIR := build
BIN_DIR := bin

DEBUG_BUILD_DIR := $(BUILD_DIR)/debug
RELEASE_BUILD_DIR := $(BUILD_DIR)/release

DEBUG_BIN_DIR := $(BIN_DIR)/debug
RELEASE_BIN_DIR := $(BIN_DIR)/release

SRCS := $(shell find $(SRC_DIR) -name '*.c')

DEBUG_OBJS := $(SRCS:$(SRC_DIR)/%.c=$(DEBUG_BUILD_DIR)/%.o)
RELEASE_OBJS := $(SRCS:$(SRC_DIR)/%.c=$(RELEASE_BUILD_DIR)/%.o)

DEPS := $(shell find $(BUILD_DIR) -name '*.d' 2>/dev/null)
-include $(DEPS)

STD_FLAGS := -std=c11
WARN_FLAGS := -Wall -Wextra -Wpedantic -Werror
DEP_FLAGS := -MMD -MP

COMMON_FLAGS := $(STD_FLAGS) $(WARN_FLAGS) $(DEP_FLAGS)

CFLAGS_DEBUG := $(COMMON_FLAGS) -g -O0 -DDEBUG
CFLAGS_RELEASE := $(COMMON_FLAGS) -O2 -DNDEBUG

LDLIBS := -lncurses -lpthread -lm

LDFLAGS_DEBUG := $(LDLIBS)
LDFLAGS_RELEASE := -flto $(LDLIBS)

.DEFAULT_GOAL := debug

run: run-debug

debug: $(DEBUG_BIN_DIR)/$(TARGET)

run-debug: debug
	@./$(DEBUG_BIN_DIR)/$(TARGET)

$(DEBUG_BIN_DIR)/$(TARGET): $(DEBUG_OBJS) | $(DEBUG_BIN_DIR)
	$(CC) $^ -o $@ $(LDFLAGS_DEBUG)

$(DEBUG_BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(DEBUG_BUILD_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS_DEBUG) -c $< -o $@

release: $(RELEASE_BIN_DIR)/$(TARGET)

run-release: release
	@./$(RELEASE_BIN_DIR)/$(TARGET)

$(RELEASE_BIN_DIR)/$(TARGET): $(RELEASE_OBJS) | $(RELEASE_BIN_DIR)
	$(CC) $^ -o $@ $(LDFLAGS_RELEASE)
	@strip $@

$(RELEASE_BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(RELEASE_BUILD_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS_RELEASE) -c $< -o $@

$(DEBUG_BUILD_DIR) $(RELEASE_BUILD_DIR) $(DEBUG_BIN_DIR) $(RELEASE_BIN_DIR):
	@mkdir -p $@

gdb: debug
	@gdb ./$(DEBUG_BIN_DIR)/$(TARGET)

clean:
	@rm -rf $(BUILD_DIR) $(BIN_DIR)

compile-db:
	@bear -- make -B debug

.PHONY: run debug run-debug release run-release gdb clean compile-db
