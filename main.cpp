#include <assert.h>
#include <iostream>
#include <string>

int find(std::string const &text, std::string const &pattern) {
    if (text.empty())
        return -1;

    if (pattern.empty())
        return 0;

    if (pattern.length() > text.length())
        return -1;

    for (int i = 0; i <= text.length() - pattern.length(); i++) {
        int j = 0;
        while (j < pattern.length() && pattern[j] == text[i+j]) {
            j++;
        }
        if (j == pattern.length()) {
            return i;
        }
    }
    return -1;
}

int find(std::string const &text, char const &pattern) {
    if (text.empty())
        return -1;

    for (int i = 0; i < text.length(); i++) {
        if (text[i] == pattern)
            return i;
    }
    return -1;
}

int main() {
    assert(find("hello world", "hello world") == 0);
    assert(find("hello world", "bye") == -1);
    assert(find("hi", "hihowareyou") == -1);
    assert(find("qtywertyuqwertyuqwerzghjasdffghjasdasdfghj", 'z') == 20);
    assert(find("hi",'i') == 1);
    assert(find("hello world", ' ') == 5);
    std::cout << "tests passed!" << std::endl;
}