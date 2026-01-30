#include <string>
#include <vector>
#include "json_token.h"
#include "json_token_type.h"

class Json_scanner
{
public:
    Json_scanner(std::string source)
    {
        source = source;
    }

private:
    std::string source;
    std::vector<Json_token> list;
    int start = 0;
    int current = 0;
    int line = 1;

    void scan_tokens()
    {
        while (!is_at_end())
        {
            start = current;
            scan_token();
        }
    }

    void scan_token()
    {
        char c = advance();
        switch (c)
        {
        case '[':
            add_token(token_left_square_bracket);
            break;
        case ']':
            add_token(token_right_square_bracket);
            break;
        case '{':
            add_token(token_left_curly_bracket);
            break;
        case '}':
            add_token(token_right_curly_bracket);
            break;
        case ':':
            add_token(token_colon);
            break;
        case ',':
            add_token(token_comma);
            break;
        case ' ':
        case '\r':
        case '\t':
            break;
        case '\n':
            line++;
            break;

        default:
            break;
        }
    }

    char advance()
    {
        return source[current++];
    }

    bool is_at_end()
    {
        return current >= source.length();
    }

    void add_token(json_token_type token)
    {
        add_token(token, NULL);
    }

    void add_token(json_token_type token, std::string lexeme)
    {
        list.push_back(Json_token(token, lexeme, line));
    }
};
