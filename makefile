CFLAGS  = -g3 -ffreestanding
LDFLAGS = -specs=nosys.specs
CC 		= arm-none-eabi-gcc
CC_DBG 	= arm-none-eabi-gdb
CC_COPY = arm-none-eabi-objcopy
ECHO 	= echo
RM 		= rmdir /s /q
MKDIR 	= mkdir

# Define serial mC
SERIES_CPU  = cortex-m3
SERIES_ARCH = armv7-m

CFLAGS += -ffunction-sections
CFLAGS += -fdata-sections
CFLAGS += -fno-strict-aliasing
CFLAGS += -Wall -Werror
CFLAGS += -Wextra
CFLAGS += -D STM32F103xB

BUILD_FOLDER		= .\build
OBJECT_FOLDER 		= .\build\obj
BIN_FOLDER 			= .\build\bin
SOURCE_FOLDER 		= .\src
SOURCE_FILES 		= .\src\main.c
BASE_LINKER 		= linker
BASE_STARTUP		= startup
STARTUP_CODE 		= .\src\startup
include $(SOURCE_FOLDER)\\source.mk


# Startup file
DEVICE_STARTUP = $(BASE_STARTUP)\\startup_STM32F1xx.s
STARTUP_OBJECT = $(OBJECT_FOLDER)\\startup_STM32F1xx.o

VPATH += $(SOURCE_FOLDER):
VPATH += $(foreach d, $(INCLUDE_FOLDER), $d:)

# Flags - Linker Options
LDFLAGS += -Wl,-L$(BASE_LINKER),-T$(BASE_LINKER)\\stm32f1xx_linker.ld
LDFLAGS +=  -Xlinker -Map=$(BIN_FOLDER)\output.map 

CFLAGS += -mcpu=$(SERIES_CPU)
CFLAGS += -march=$(SERIES_ARCH)
CFLAGS += -mlittle-endian
CFLAGS += -mthumb
CFLAGS += -masm-syntax-unified

# Flags - Directory Options
CFLAGS += $(foreach d, $(INCLUDE_FOLDER), -I$d)
CFLAGS += -I$(BASE_STARTUP)

# Output files
ELF_FILE_NAME ?= stm32_executable.elf
BIN_FILE_NAME ?= stm32_bin_image.bin

ELF_FILE_PATH = $(BIN_FOLDER)\$(ELF_FILE_NAME)
BIN_FILE_PATH = $(BIN_FOLDER)\$(BIN_FILE_NAME)

OBJECTS = $(patsubst %.c, $(OBJECT_FOLDER)\\%.o, $(notdir $(SOURCE_FILES)))

.PHONY: all clean debug

all:  $(BUILD_FOLDER) $(BIN_FILE_PATH) 

$(BIN_FILE_PATH): $(ELF_FILE_PATH)
	$(CC_COPY) -O binary $^ $@

$(ELF_FILE_PATH): $(OBJECTS) $(STARTUP_OBJECT)
	$(CC)  $(LDFLAGS) $(CFLAGS) $^ -o $@

$(OBJECT_FOLDER)\\%.o: %.c
	@echo creating object $@ from $<...
	$(CC) $(CFLAGS) -c $< -o $@

$(STARTUP_OBJECT): $(DEVICE_STARTUP)
	$(CC) $(CFLAGS) $^ -c -o $@

$(BUILD_FOLDER):
	$(MKDIR) $(OBJECT_FOLDER) $(BIN_FOLDER)

clean:
	if exist $(BUILD_FOLDER) $(RM) $(BUILD_FOLDER)
	@echo Remove done !

distclean: clean

debug:
	$(CC_DBG) -q $(ELF_FILE_PATH)

help:
	@$(ECHO) "Targets:"
	@$(ECHO) "all     - buildcompile what is necessary"
	@$(ECHO) "clean   - cleanup old .o and .bin"
