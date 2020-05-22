#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    long long n;
    std::cout << "Input N:\n";
    std::cin >> n;
    std::vector<long long> rem;
    int end;
    do {
        end = n % 2;
        n /= 2;
        rem.push_back(end);
    } while (n >= 1);
    std::cout << "Output:\n";
    std::reverse(rem.begin(), rem.end());
    for (int i = 0; i < rem.size(); i++) {
        std::cout << rem[i];
    }
}