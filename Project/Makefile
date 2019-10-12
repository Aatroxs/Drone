PROJECT :=Stm32

DIR_BUILD   := ../Project/build/
DIR_DRIVERS += ../Drivers/
DIR_DEVICES += ../Devices/

DIR_INCLUDE += -I../Libraries/ \
               -I../Libraries/Stm32F10x_Fwlib/ \
               -I../Libraries/Stm32F10x_Fwlib/CMSIS/ \
			   -I../Libraries/Stm32F10x_Fwlib/STM32F10x_StdPeriph_Driver/inc/ \
			   $(addprefix -I,$(DIR_DRIVERS)) \
			   $(addprefix -I,$(DIR_DEVICES)) \
			   -I../User/

SRC_C       += $(wildcard ../Libraries/Stm32F10x_Fwlib/CMSIS/*.c)
SRC_C       += $(wildcard ../Libraries/Stm32F10x_Fwlib/STM32F10x_StdPeriph_Driver/src/*.c)
SRC_C       += $(wildcard $(addsuffix *.c,$(DIR_DRIVERS)))
SRC_C       += $(wildcard $(addsuffix *.c,$(DIR_DEVICES)))
SRC_C       += $(wildcard ../User/*.c)

SRC_ASM     := ../Libraries/Stm32F10x_Fwlib/startup/startup_stm32f10x_md.s

OBJS        := $(filter %.o,$(SRC_ASM:.s=.o)) $(filter %.o,$(SRC_C:.c=.o))


LINK_SCRIPT := ../Libraries/Stm32F10x_Fwlib/stm32f10x_flash.lds

CC_PREFIX := arm-none-eabi-

CC        := $(CC_PREFIX)gcc
CXX       := $(CC_PREFIX)g++
CP        := $(CC_PREFIX)objcopy
GDB       := $(CC_PREFIX)gdb
SIZE      := $(CC_PREFIX)size
AS        := $(CC) -x assembler-with-cpp
HEX       := $(CP) -O ihex
BIN       := $(CP) -O binary -S

DDEFS += -DSTM32F10X_MD
DDEFS += -DHSE_VALUE=8000000 -DUSE_STDPERIPH_DRIVER

DEFS  := $(DDEFS) -DRUN_FROM_FLASH=1

MCU   := cortex-m3

OPT   += -Os
OPT   += -fsingle-precision-constant
OPT   += -fno-common
OPT   += -ffunction-sections
OPT   += -fdata-sections

SPECS := --specs=rdimon.specs -u _printf_float

FLAGS_MCU := -mcpu=$(MCU)
FLAGS_AS  := $(SPECS) $(FLAGS_MCU) $(OPT) -c -g -gdwarf-2 -mthumb
FLAGS_C   := $(SPECS) $(FLAGS_MCU) $(OPT) -c -g -gdwarf-2 -mthumb \
             -fomit-frame-pointer -Wall -fverbose-asm $(DEFS)
FLAGS_CXX := $(SPECS) $(FLAGS_MCU) $(OPT) -c -g -gdwarf-2 -mthumb \
             -fomit-frame-pointer -Wall -fverbose-asm -fno-exceptions \
             -fno-rtti -fno-threadsafe-statics -fvisibility=hidden -std=c++11 \
             $(DEFS)
FLAGS_LD  := $(SPECS) $(FLAGS_MCU) $(OPT) -lm -g -gdwarf-2 -mthumb \
             -nostartfiles -Xlinker --gc-sections -T$(LINK_SCRIPT) \
             -Wl,-Map=$(PROJECT).map,--cref,--no-warn-mismatch

.PHONY: all clean

all: $(OBJS) $(PROJECT).elf $(PROJECT).hex $(PROJECT).bin
	$(SIZE) $(PROJECT).elf

%.o: %.c
	$(CC) $(FLAGS_C) $(DIR_INCLUDE) $< -o  $(@)

%.o: %.s
	$(AS) $(FLAGS_AS) $< -o $(@)

%.elf: $(OBJS)
	$(CC) $(OBJS) $(FLAGS_LD) -o $@

%.hex: %.elf
	$(HEX) $< $@

%.bin: %.elf
	$(BIN) $< $@