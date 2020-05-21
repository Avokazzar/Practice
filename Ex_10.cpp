#include <iostream>

int main()
{
	int N = 100;
	int m[5000];
	for (int i = 0; i < 5000; i++) {
		m[i] = 0;
		m[0] = 1;
	}
	for (int i = 1; i <= 100; i++) {
		for (int j = 0; j < 5000; j++) {
			m[j] *= i;
		}
		for (int j = 0; j < 5000; j++) {
			if (m[j] > 10) {
				m[j + 1] += m[j] / 10;
				m[j] = m[j] % 10;
			}
		}
	}
	
	int sum = 0;
	for (int i = 0; i < 5000; i++) {
		sum += m[i];
	}
	std::cout << "Output:\n" << sum;
}