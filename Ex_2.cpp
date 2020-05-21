#include <iostream>
#include <string>

int main()
{
    std::string s;
    std::cout << "Input:\n";
    getline(std::cin, s);
    int count = 0, temp;
    for (int i = 0; i <= s.length(); i++) {
        if (s[i] == 'f') {
            count++;
            temp = i;
        }
    }
    std::cout << "Output:\n";
    if (count == 1) {
        std::cout << "-1\n";
    }
    else if (count == 0) {
        std::cout << "-2\n";
    }
    else {
        std::cout << temp;
    }
}