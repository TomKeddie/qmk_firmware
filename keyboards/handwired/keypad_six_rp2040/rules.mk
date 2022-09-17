# MCU name
MCU = RP2040
BOOTLOADER = rp2040

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no        # Mouse keys
EXTRAKEY_ENABLE = no        # Audio control and System control
CONSOLE_ENABLE = yes        # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = no            # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output

DEFERRED_EXEC_ENABLE = yes

# QUANTUM_PAINTER_ENABLE = yes
# QUANTUM_PAINTER_DRIVERS = st7735_spi
# QUANTUM_PAINTER_DEBUG = yes

DEFAULT_FOLDER = handwired/keypad_six_rp2040

BOARD = GENERIC_RP_RP2040

# OPT_DEFS += -DHAL_USE_SPI=TRUE
