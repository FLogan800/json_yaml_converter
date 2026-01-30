#ifndef JSON_TOKEN_TYPE
#define JSON_TOKEN_TYPE

enum json_token_type
{
    // Structural tokens
    token_left_square_bracket,
    token_right_square_bracket,
    token_left_curly_bracket,
    token_right_curly_bracket,
    token_colon,
    token_comma,

    // Literal name tokens
    token_true,
    token_false,
    token_null,

    // Value tokens
    token_object,
    token_array,
    token_number,
    token_string,
};

#endif