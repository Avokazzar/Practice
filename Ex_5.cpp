#include <iostream>

int  Factorial(int num)
{
    if (num <= 0) {
        return 1;
    }
    int res = num;
    for (int i = 1; i < num; i++) {
        res *= i;
    }
    return res;
}

int main()
{
    int num;
    std::cout << "Input:\n";
    std::cin >> num;
    std::cout << "Output:\n" << Factorial(num);
}