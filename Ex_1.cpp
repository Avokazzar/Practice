#include <iostream>
#include <math.h>

int main()
{
    setlocale(LC_ALL, "Russian");

    double a, b, c, d, x1, x2;
    std::cout << "Вход:\n";
    std::cin >> a >> b >> c;
    std::cout << "Выход:\n";
    d = (pow(b, 2)) - (4 * a * c);
    if (d > 0) {
        x1 = (-b + sqrt(d)) / (2 * a);
        x2 = (-b - sqrt(d)) / (2 * a);
        std::cout << x1 << " " << x2 << "\n";
    }
    else if (d == 0) {
        x1 = -b / (2 * a);
        std::cout << x1 << "\n";
    }
    else {
        std::cout << "\n";
    }
}
