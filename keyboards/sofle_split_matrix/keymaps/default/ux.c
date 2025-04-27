
void keyboard_post_init_user(void) {
    rgb_matrix_enable();
    rgb_matrix_mode(RGB_MATRIX_RAINBOW_MOVING_CHEVRON);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if(!is_keyboard_master()) {
        return OLED_ROTATION_180;
    }

    return rotation;
}