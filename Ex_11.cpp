#include <iostream>

using std::cout;
using std::endl;

int main() {
const unsigned short n = 20;
unsigned long long m[n][n];
for (unsigned short i = 2; i <= n; i++)
m[n - i][n - 1] = i + 1;
for (unsigned short i = n - 2; i >= 1; i--) {
m[i][i] = 2 * m[i][i + 1];
for (unsigned short k = i; k >= 1; k--)
m[k - 1][i] = m[k][i] + m[k - 1][i + 1];
}
cout<<"Result: " << 2 * m[0][1] << endl;

system("pause");
}
