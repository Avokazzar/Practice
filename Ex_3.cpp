#include <iostream>

int main()
{
    int a, b;
    std::cout << "Input:\n";
    std::cin >> a >> b;
    std::cout << "Output:\n";
    for (int i = a; i > 0; i--) {
        if (a % i == 0 && b % i == 0) {
            std::cout << i;
            break;
        }
    }
}