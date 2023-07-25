#include <regex>
#include <string>
#include <iostream>
#include <algorithm>

std::string
minify(std::string str) {
    // Remove newlines
    std::erase(str, '\n');

    // Remove spacing around special characters
    str = std::regex_replace(str, std::regex("\\s*([{},:;^|$~>()/\\[\\]])\\s*"), "$1");

    // Remove comments
    str = std::regex_replace(str, std::regex("/\\*.*?\\*/"), "");
    
    // Remove unnecessary trailing semicolons
    str = std::regex_replace(str, std::regex(":}"), "}");
    //replace(&str, ";}", "}");

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