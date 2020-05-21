#include <iostream>

int main()
{
    long int f1 = 1, f2 = 2, f = 0;
    long long sum = 2;
    do {
        f = f1 + f2;
        if (f % 2 == 0) {
            sum += f;
        }
        f1 = f2;
        f2 = f;
    } while (f <= 4000000);

    std::cout << "Output:\n" << sum;
}