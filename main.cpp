#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <string>

constexpr auto escape_characters = std::array{
'\'', '\"', '\?', '\\', '\a', '\b', '\f', '\n', '\r', '\t', '\v'
};

std::string text_to_c_string(std::string text) {
    std::vector<char> buf{};
    for (auto c : text) {
        if (std::ranges::contains(escape_characters, c)) {
            buf.emplace_back('\\');
        }
        buf.emplace_back(c);
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