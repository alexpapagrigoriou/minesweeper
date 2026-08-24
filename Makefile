TARGET := minesweeper

CC := gcc

SRC_DIR := src
THIRD_PARTY_DIR = third_party

BUILD_DIR := build
BIN_DIR := bin

DEBUG_BUILD_DIR := $(BUILD_DIR)/debug
RELEASE_BUILD_DIR := $(BUILD_DIR)/release

DEBUG_BIN_DIR := $(BIN_DIR)/debug
RELEASE_BIN_DIR := $(BIN_DIR)/release

SRCS := $(shell find $(SRC_DIR) -name '*.c')

DEBUG_OBJS := $(SRCS:$(SRC_DIR)/%.c=$(DEBUG_BUILD_DIR)/%.o)
RELEASE_OBJS := $(SRCS:$(SRC_DIR)/%.c=$(RELEASE_BUILD_DIR)/%.o)

THIRD_PARTY_SRCS := $(shell find $(THIRD_PARTY_DIR) -name '*.c')
DEBUG_OBJS += $(THIRD_PARTY_SRCS:$(THIRD_PARTY_DIR)/%.c=$(DEBUG_BUILD_DIR)/%.o)
RELEASE_OBJS += $(THIRD_PARTY_SRCS:$(THIRD_PARTY_DIR)/%.c=$(RELEASE_BUILD_DIR)/%.o)

DEPS := $(DEBUG_OBJS:.o=.d) $(RELEASE_OBJS:.o=.d)
-include $(DEPS)

STD_FLAGS := -std=c11
WARN_FLAGS := -Wall -Wextra -Wpedantic -Werror
DEP_FLAGS := -MMD -MP

COMMON_FLAGS := $(STD_FLAGS) $(WARN_FLAGS) $(DEP_FLAGS)
THIRD_PARTY_FLAGS := $(STD_FLAGS) $(DEP_FLAGS)

DEBUG_MODE_FLAGS := -g -O0 -DDEBUG
RELEASE_MODE_FLAGS := -O2 -DNDEBUG

CFLAGS_DEBUG := $(COMMON_FLAGS) $(DEBUG_MODE_FLAGS)
CFLAGS_RELEASE := $(COMMON_FLAGS) $(RELEASE_MODE_FLAGS)

THIRD_PARTY_CFLAGS_DEBUG := $(THIRD_PARTY_FLAGS) $(DEBUG_MODE_FLAGS)
THIRD_PARTY_CFLAGS_RELEASE := $(THIRD_PARTY_FLAGS) $(RELEASE_MODE_FLAGS)

LDLIBS := -lncurses -lpthread -lm

LDFLAGS_DEBUG :=
LDFLAGS_RELEASE :=

.DEFAULT_GOAL := debug

run: run-debug

debug: $(DEBUG_BIN_DIR)/$(TARGET)

run-debug: debug
	@./$(DEBUG_BIN_DIR)/$(TARGET)

$(DEBUG_BIN_DIR)/$(TARGET): $(DEBUG_OBJS) | $(DEBUG_BIN_DIR)
	$(CC) $(LDFLAGS_DEBUG) $^ -o $@ $(LDLIBS)

$(DEBUG_BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(DEBUG_BUILD_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS_DEBUG) -c $< -o $@

$(DEBUG_BUILD_DIR)/%.o: $(THIRD_PARTY_DIR)/%.c | $(DEBUG_BUILD_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(THIRD_PARTY_CFLAGS_DEBUG) -c $< -o $@

release: $(RELEASE_BIN_DIR)/$(TARGET)

run-release: release
	@./$(RELEASE_BIN_DIR)/$(TARGET)

$(RELEASE_BIN_DIR)/$(TARGET): $(RELEASE_OBJS) | $(RELEASE_BIN_DIR)
	$(CC) $(LDFLAGS_RELEASE) $^ -o $@ $(LDLIBS)
	@strip $@

$(RELEASE_BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(RELEASE_BUILD_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS_RELEASE) -c $< -o $@

$(RELEASE_BUILD_DIR)/%.o: $(THIRD_PARTY_DIR)/%.c | $(RELEASE_BUILD_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(THIRD_PARTY_CFLAGS_RELEASE) -c $< -o $@

$(DEBUG_BUILD_DIR) $(RELEASE_BUILD_DIR) $(DEBUG_BIN_DIR) $(RELEASE_BIN_DIR):
	@mkdir -p $@

gdb: debug
	@gdb ./$(DEBUG_BIN_DIR)/$(TARGET)

clean:
	@rm -rf $(BUILD_DIR) $(BIN_DIR)

compile-db:
	@bear -- make -B debug

.PHONY: run debug run-debug release run-release gdb clean compile-db
