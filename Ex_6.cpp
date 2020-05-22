#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

int IsPalindrom(std::string s)
{
    for (int i = 0; i <= s.length(); i++) {
        if (s[i] == ' ') {
            s.erase(i, 1);
        }
        s[i] = tolower(s[i]);
    }
    std::string s_new = s;
    std::reverse(s_new.begin(), s_new.end());
    bool res;
    if (s == s_new) {
        res = true;
    }
    else {
        res = false;
    }
    return res;
}

int main()
{
    std::string s;
    std::cout << "Input:\n";
    getline(std::cin, s);
    
    std::cout << "Output:\n" << IsPalindrom(s);
}