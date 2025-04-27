typedef struct {
    uint16_t keycode;
    char* output;
} leader_single_lookup_t;

const leader_single_lookup_t leader_single_lookup[] = {
    { KC_Q, SS_LALT(SS_TAP(X_F4)) },
    { KC_S, SS_LCTL(SS_TAP(X_S)) },
    { KC_C, SS_LCTL(SS_TAP(X_C)) },
    { KC_V, SS_LCTL(SS_TAP(X_V)) },
};

typedef struct {
    uint16_t keycode;
    uint16_t s_keycode;
    char* output;
} leader_double_lookup_t;

const leader_double_lookup_t leader_double_lookup[] = {
    { KC_P, KC_S, SS_TAP(X_PSCR) },
};

typedef struct {
    uint16_t keycode;
    uint16_t s_keycode;
    uint16_t t_keycode;
    char* output;
} leader_triple_lookup_t;

const leader_triple_lookup_t leader_triple_lookup[] = {
};

typedef struct {
    uint16_t keycode;
    uint16_t s_keycode;
    uint16_t t_keycode;
    uint16_t q_keycode;
    char* output;
} leader_quadruple_lookup_t;

const leader_quadruple_lookup_t leader_quadruple_lookup[] = {
};

typedef struct {
    uint16_t keycode;
    uint16_t s_keycode;
    uint16_t t_keycode;
    uint16_t q_keycode;
    uint16_t qq_keycode;
    char* output;
} leader_quintuple_lookup_t;

const leader_quintuple_lookup_t leader_quintuple_lookup[] = {
};

void leader_start_user(void) {}

void leader_end_user(void) {
    int quintuple_lookup_size = sizeof(leader_quintuple_lookup) / sizeof(leader_quintuple_lookup[0]);
    for(size_t i = 0; i < quintuple_lookup_size; i++) {
        leader_quintuple_lookup_t code = leader_quintuple_lookup[i];

        if(leader_sequence_five_keys(code.keycode, code.s_keycode, code.t_keycode, code.q_keycode, code.qq_keycode)) {
            SEND_STRING(code.output);
        }
    }

    int quadruple_lookup_size = sizeof(leader_quadruple_lookup) / sizeof(leader_quadruple_lookup[0]);
    for(size_t i = 0; i < quadruple_lookup_size; i++) {
        leader_quadruple_lookup_t code = leader_quadruple_lookup[i];

        if(leader_sequence_four_keys(code.keycode, code.s_keycode, code.t_keycode, code.q_keycode)) {
            SEND_STRING(code.output);
        }
    }

    int triple_lookup_size = sizeof(leader_triple_lookup) / sizeof(leader_triple_lookup[0]);
    for(size_t i = 0; i < triple_lookup_size; i++) {
        leader_triple_lookup_t code = leader_triple_lookup[i];

        if(leader_sequence_three_keys(code.keycode, code.s_keycode, code.t_keycode)) {
            SEND_STRING(code.output);
        }
    }

    int double_lookup_size = sizeof(leader_double_lookup) / sizeof(leader_double_lookup[0]);
    for(size_t i = 0; i < double_lookup_size; i++) {
        leader_double_lookup_t code = leader_double_lookup[i];

        if(leader_sequence_two_keys(code.keycode, code.s_keycode)) {
            SEND_STRING(code.output);
        }
    }

    int single_lookup_size = sizeof(leader_single_lookup) / sizeof(leader_single_lookup[0]);
    for(size_t i = 0; i < single_lookup_size; i++) {
        leader_single_lookup_t code = leader_single_lookup[i];

        if(leader_sequence_one_key(code.keycode)) {
            SEND_STRING(code.output);
        }
    }
}
