# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = caterina

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = no  # Enable Bootmagic Lite
MOUSEKEY_ENABLE  = no  # Mouse keys
EXTRAKEY_ENABLE  = yes  # Audio control and System control
CONSOLE_ENABLE   = yes # Console for debug
COMMAND_ENABLE   = no # Commands for debug and configuration
NKRO_ENABLE      = no  # Enable N-Key Rollover
BACKLIGHT_ENABLE = no  # Enable keyboard backlight functionality
AUDIO_ENABLE     = no
RGBLIGHT_ENABLE  = no
OLED_ENABLE      = no
DEFERRED_EXEC_ENABLE = yes

DEFAULT_FOLDER = keypad_six

# SRC += keypad_six_lcd.c
