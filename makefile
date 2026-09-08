CC      := cc
CFLAGS  := -std=c23 -Wall -Wextra -Wpedantic -O2 -g -MMD -MP
LDFLAGS :=
TARGET  := main
BUILD_DIR := build

CFLAGS += -Werror

SRCS := main.c mem_arena.c
OBJS := $(addprefix $(BUILD_DIR)/,$(SRCS:.c=.o))
DEPS := $(OBJS:.o=.d)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf $(BUILD_DIR) $(TARGET)

-include $(DEPS)

.PHONY: all run clean
