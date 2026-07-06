#  	    Makefile
# ---------------------------
# 	 by: NopAngel - angel¿
#

ARCH       ?= x86_64
CC         := gcc
AR         := ar
STRIP      := strip

GCC_INC    := $(shell $(CC) -print-file-name=include)
CFLAGS     := -Wall -Wextra -Wpedantic -Wshadow -Wpointer-arith -Wcast-align \
              -O2 -g3 -nostdinc -isystem $(GCC_INC) -ffreestanding \
              -fno-stack-protector -fno-pic -fno-pie -no-pie \
              -mno-red-zone -Iinclude

ARFLAGS    := rcs

SRC_DIR    := src
ARCH_DIR   := arch/$(ARCH)
OBJ_DIR    := obj
BIN_DIR    := bin

SRCS_C     := $(shell find $(SRC_DIR) -name "*.c")
SRCS_ASM   := $(shell find $(SRC_DIR) -name "*.S")

OBJS_C     := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS_C))
OBJS_ASM   := $(patsubst $(SRC_DIR)/%.S, $(OBJ_DIR)/%.o, $(SRCS_ASM))

OBJ_SYSCALL:= $(OBJ_DIR)/syscall.o

ALL_OBJS   := $(OBJS_C) $(OBJS_ASM) $(OBJ_SYSCALL)

ifeq ($(V),1)
  Q :=
else
  Q := @
endif

.PHONY: all default test clean install strip static-analysis

default: all
all: $(BIN_DIR)/libuclite.a

$(BIN_DIR)/libuclite.a: $(ALL_OBJS)
	$(Q)mkdir -p $(BIN_DIR)
	@echo "    AR        Static: $@$(RESET)"
	$(Q)$(AR) $(ARFLAGS) $@ $(ALL_OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(Q)mkdir -p $(dir $@)
	@echo "    CC         Compile: $<$(RESET)"
	$(Q)$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.S
	$(Q)mkdir -p $(dir $@)
	@echo "    AS         ASM: $<$(RESET)"
	$(Q)$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_SYSCALL): $(ARCH_DIR)/syscall.S
	$(Q)mkdir -p $(OBJ_DIR)
	$(Q)$(CC) $(CFLAGS) -c $< -o $@
clean:
	@echo "    CLEAN       Done..."
	$(Q)rm -rf $(OBJ_DIR) $(BIN_DIR)

strip: all
	@echo "    STRIP       Removing test symbol table..."
	$(Q)$(STRIP) --strip-unneeded $(BIN_DIR)/test_uclite

install: all
	@mkdir -p /usr/local/include/uclite /usr/local/lib
	@cp -r include/* /usr/local/include/uclite/
	@cp $(BIN_DIR)/libuclite.a /usr/local/lib/
	@echo "    INSTALL     Done"
