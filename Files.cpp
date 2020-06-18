#include <iostream>
#include <fstream>
#include <algorithm> 
#include <vector>
#include <stdlib.h>

using std::cin;
using std::cout;
using std::endl;
using std::min_element;

bool comp1(double a, double b) {
    return a > b;
}
int main()
{
    int num_1, num_2;
    double mean, sum = 0;

    std::ifstream in("input.txt");
    std::ofstream out_row("out_row.txt", std::ios::out);
    std::ofstream out_col("out_col.txt", std::ios::out);

    if (in.is_open() && out_row.is_open())
    {
        in >> num_1 >> num_2;

        std::vector<double> matrix(num_1 * num_2);
        for (int i = 0; i < matrix.size(); i++) {
                in >> matrix[i];
                in.ignore(1, ',');
                sum += matrix[i];
        }
        std::vector<double> matrix_buff(num_1 * num_2);
        
        auto minmax = std::minmax_element(matrix.begin(), matrix.end());
        mean = sum / (matrix.size());

        out_row << "mean = " << mean << endl;
        out_col << "mean = " << mean << endl;
        out_row << "max = " << *minmax.second << endl;
        out_col << "max = " << *minmax.second << endl;
        out_row << "min = " << *minmax.first << endl;
        out_col << "min = " << *minmax.first << endl;

        for (int i = 0; i < num_1; ++i) {
            for (int j = 0; j < num_2; ++j) {
                matrix_buff[j * num_1 + i] = matrix[i * num_2 + j];
            }
        }
        
        for (int i = 0; i < num_1; ++i) {
            sort(matrix.begin() + num_2 * i, matrix.begin() + num_2 * i + num_2);
        }
        for (int i = 0; i < num_1; ++i) {
            for (int j = 0; j < num_2; ++j) {
                out_row << matrix[i * num_2 + j] << " ";
            }
            out_row << endl;
        }
        //---------------------------------------
        for (int i = 0; i < num_2; ++i) {
            sort(matrix_buff.begin() + num_1 * i, matrix_buff.begin() + num_1 * i + num_1, comp1);
        }
        for (int i = 0; i < num_1; ++i) {
            for (int j = 0; j < num_2; ++j) {
                matrix[i * num_2 + j] = matrix_buff[j * num_1 + i];
            }
        }
        for (int i = 0; i < num_1; ++i) {
            for (int j = 0; j < num_2; ++j) {
                out_col << matrix[i * num_2 + j] << " ";
            }
            out_col << endl;
        }
        cout << "Completed!" << endl;
    }

    in.close();
    out_row.close();
    out_col.close();

    return 0;
}
