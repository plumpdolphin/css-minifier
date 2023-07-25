#include <regex>
#include <string>
#include <iostream>

void
replace(std::string* str, std::string a, std::string b) {
    size_t pos = 0;
    do
    {
        pos = str->find(a, pos);
        if (pos == std::string::npos)
            break;
 
        str->erase(pos, a.length());
        str->insert(pos, b);
    }
    while (pos += a.length());
}

std::string
minify(std::string str) {
    // Remove newlines
    replace(&str, "\n", "");

    // Remove spacing around special characters
    str = std::regex_replace(str, std::regex("\\s*([{},:;^|$~>()/\\[\\]])\\s*"), "$1");

    // Remove comments
    str = std::regex_replace(str, std::regex("/\\*.*?\\*/"), "");
    
    // Remove unnecessary trailing semicolons
    replace(&str, ";}", "}");

    // Shorten relative URIs
    str = std::regex_replace(str, std::regex("[^\\.]\\./"), "");

    return str;
}

int 
main(void) {
    std::string str, buffer;
    while (std::getline(std::cin, buffer)) {
        str += buffer;
    }
    std::cout << minify(str);
    return 0;
}