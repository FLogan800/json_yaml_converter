#ifndef JSON_TOKEN
#define JSON_TOKEN

#include "json_token_type.h"

class Json_token
{
public:
    Json_token(json_token_type token_type, std::string lexeme, unsigned int line)
    {
        token_type = token_type;
        lexeme = lexeme;
        line = line;
    }

private:
    json_token_type token_type;
    std::string lexeme;
    unsigned int line;
};

#endif