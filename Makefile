##########################################################################################################################
# File automatically-generated by tool: [projectgenerator] version: [3.4.0] date: [Thu Apr 09 15:54:26 PDT 2020]
##########################################################################################################################

# ------------------------------------------------
# Generic Makefile (based on gcc)
#
# ChangeLog :
#	2017-02-10 - Several enhancements + project update mode
#   2015-07-22 - first version
# ------------------------------------------------

######################################
# target
######################################
TARGET = STM32F746_Disc


######################################
# building variables
######################################
# debug build?
DEBUG = 1
# optimization
OPT = -Og


#######################################
# paths
#######################################
# Build path
BUILD_DIR = build

######################################
# source
######################################
# C sources
C_SOURCES =  \
src/app/main.c \
src/hw/hw_init.c \
src/hw/hw_config.c \
src/hw/stm32f7xx_it.c \
src/hw/system_stm32f7xx.c \
src/target/TargetGPIO.c \
src/drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_hcd.c \
src/drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_usb.c \
src/drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_adc.c \
src/drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_adc_ex.c \
src/drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_cortex.c \
src/drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_crc.c \
src/drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_crc_ex.c \
src/drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dcmi.c \
src/drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dcmi_ex.c \
src/drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dma2d.c \
src/drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_eth.c \
src/drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_fmc.c \
src/drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_sdram.c \
src/drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_i2c.c \
src/drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_i2c_ex.c \
src/drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_ltdc.c \
src/drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_ltdc_ex.c \
src/drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dsi.c \
src/drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_qspi.c \
src/drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_rtc.c \
src/drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_rtc_ex.c \
src/drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_sai.c \
src/drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_sai_ex.c \
src/drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_sdmmc.c \
src/drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_sd.c \
src/drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_spdifrx.c \
src/drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_spi.c \
src/drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_spi_ex.c \
src/drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_tim.c \
src/drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_tim_ex.c \
src/drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_uart.c \
src/drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_uart_ex.c \
src/drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_rcc.c \
src/drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_rcc_ex.c \
src/drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_flash.c \
src/drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_flash_ex.c \
src/drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_gpio.c \
src/drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dma.c \
src/drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dma_ex.c \
src/drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_pwr.c \
src/drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_pwr_ex.c \
src/drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal.c \
src/drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_exti.c \



# ASM sources
ASM_SOURCES =  \
src/hw/startup_stm32f746xx.s


#######################################
# binaries
#######################################
PREFIX = arm-none-eabi-
# The gcc compiler bin path can be either defined in make command via GCC_PATH variable (> make GCC_PATH=xxx)
# either it can be added to the PATH environment variable.
ifdef GCC_PATH
CC = $(GCC_PATH)/$(PREFIX)gcc
AS = $(GCC_PATH)/$(PREFIX)gcc -x assembler-with-cpp
CP = $(GCC_PATH)/$(PREFIX)objcopy
SZ = $(GCC_PATH)/$(PREFIX)size
else
CC = $(PREFIX)gcc
AS = $(PREFIX)gcc -x assembler-with-cpp
CP = $(PREFIX)objcopy
SZ = $(PREFIX)size
endif
HEX = $(CP) -O ihex
BIN = $(CP) -O binary -S
 
#######################################
# CFLAGS
#######################################
# cpu
CPU = -mcpu=cortex-m7

# fpu
FPU = -mfpu=fpv5-sp-d16

# float-abi
FLOAT-ABI = -mfloat-abi=hard

# mcu
MCU = $(CPU) -mthumb $(FPU) $(FLOAT-ABI)

# macros for gcc
# AS defines
AS_DEFS = 

# C defines
C_DEFS =  \
-DUSE_HAL_DRIVER \
-DSTM32F746xx \

# AS includes
AS_INCLUDES =  \
-Isrc/hw/include

# C includes
C_INCLUDES =  \
-Isrc/app/include \
-Isrc/hw/include \
-Isrc/target/include \
-Isrc/drivers/STM32F7xx_HAL_Driver/Inc \
-Isrc/drivers/STM32F7xx_HAL_Driver/Inc/Legacy \
-Isrc/drivers/CMSIS/Device/ST/STM32F7xx/Include \
-Isrc/drivers/CMSIS/Include 


# compile gcc flags
ASFLAGS = $(MCU) $(AS_DEFS) $(AS_INCLUDES) $(OPT) -Wall -fdata-sections -ffunction-sections

CFLAGS = $(MCU) $(C_DEFS) $(C_INCLUDES) $(OPT) -Wall -fdata-sections -ffunction-sections

ifeq ($(DEBUG), 1)
CFLAGS += -g -gdwarf-2
endif


# Generate dependency information
CFLAGS += -MMD -MP -MF"$(@:%.o=%.d)"


#######################################
# LDFLAGS
#######################################
# link script
LDSCRIPT = scripts/STM32F746NGHx_FLASH.ld

# libraries
LIBS = -lc -lm -lnosys 
LIBDIR = 
LDFLAGS = $(MCU) -specs=nosys.specs -T$(LDSCRIPT) $(LIBDIR) $(LIBS) -Wl,-Map=$(BUILD_DIR)/$(TARGET).map,--cref -Wl,--gc-sections

# default action: build all
all: $(BUILD_DIR)/$(TARGET).elf $(BUILD_DIR)/$(TARGET).hex $(BUILD_DIR)/$(TARGET).bin


#######################################
# build the application
#######################################
# list of objects
OBJECTS = $(addprefix $(BUILD_DIR)/,$(notdir $(C_SOURCES:.c=.o)))
vpath %.c $(sort $(dir $(C_SOURCES)))
# list of ASM program objects
OBJECTS += $(addprefix $(BUILD_DIR)/,$(notdir $(ASM_SOURCES:.s=.o)))
vpath %.s $(sort $(dir $(ASM_SOURCES)))

$(BUILD_DIR)/%.o: %.c Makefile | $(BUILD_DIR) 
	$(CC) -c $(CFLAGS) -Wa,-a,-ad,-alms=$(BUILD_DIR)/$(notdir $(<:.c=.lst)) $< -o $@

$(BUILD_DIR)/%.o: %.s Makefile | $(BUILD_DIR)
	$(AS) -c $(CFLAGS) $< -o $@

$(BUILD_DIR)/$(TARGET).elf: $(OBJECTS) Makefile
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@
	$(SZ) $@

$(BUILD_DIR)/%.hex: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
	$(HEX) $< $@
	
$(BUILD_DIR)/%.bin: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
	$(BIN) $< $@	
	
$(BUILD_DIR):
	mkdir $@		

#######################################
# clean up
#######################################
clean:
	-rm -fR $(BUILD_DIR)
  
#######################################
# dependencies
#######################################
-include $(wildcard $(BUILD_DIR)/*.d)

# *** EOF ***