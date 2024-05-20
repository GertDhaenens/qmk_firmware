# Enable the OLED displays
OLED_ENABLE = yes

# Disables the use of one or more encoders
ENCODER_ENABLE = no

# Disable keyboard RGB matrix, as it is enabled by default on rev3
RGB_MATRIX_ENABLE = no

# Enable keyboard RGB underglow
RGBLIGHT_ENABLE = yes

# Use the liatris .uf2 format
CONVERT_TO = liatris

# Enable Caps Word
# https://github.com/qmk/qmk_firmware/blob/master/docs/feature_caps_word.md
CAPS_WORD_ENABLE = yes

# Enable the WPM feature for our spinning cube
WPM_ENABLE = yes

# Enable the tap dance feature for multi-tap keys
TAP_DANCE_ENABLE = yes

# Add our extra source files
SRC += render_display.c \
	   math/math.c
