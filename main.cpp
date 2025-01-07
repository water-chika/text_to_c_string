#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

auto escape_map = std::map{
    std::pair{'\'', '\''},
    {'\"', '\"'},
    {'\?', '\?'},
    {'\\', '\\'},
    {'\a', 'a'},
    {'\b', 'b'},
    {'\f', 'f'},
    {'\n', 'n'},
    {'\r', 'r'},
    {'\t', 't'},
    {'\v', 'v'},
};

constexpr auto escape_characters = std::array{
'\'', '\"', '\?', '\\', '\a', '\b', '\f', '\n', '\r', '\t', '\v'
};
constexpr auto escape_control_characters = std::array{
'\a', '\b', '\f', '\n', '\r', '\t', '\v'
};

std::string text_to_c_string(std::string text) {
    std::vector<char> buf{};
    for (auto c : text) {
        if (escape_map.contains(c)) {
            buf.emplace_back('\\');
            buf.emplace_back(escape_map[c]);
        }
        else {
            buf.emplace_back(c);
        }
    }

    return std::string{buf.begin(), buf.end()};
}

int main() {
    auto& in = std::cin;
    auto& out = std::cout;

    std::string line;
    while (std::getline(in, line)) {
        auto c_str = text_to_c_string(line);
        std::cout << "\"" << c_str << "\"" << std::endl;
    }
}