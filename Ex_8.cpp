#include <iostream>
#include <math.h>

int main()
{
    int a, b, c, step = 100;
    for (int n = 1; n < step; n++) {
        for (int m = 2; m < (step + 1); m++) {
            if (m > n) {
                a = 2 * m * n;
                b = pow(m, 2) - pow(n, 2);
                c = pow(m, 2) + pow(n, 2);

                if (a + b + c == 1000) {
                    std::cout << "Output:\n" << a * b * c;
                }
            }
        }
    }
}