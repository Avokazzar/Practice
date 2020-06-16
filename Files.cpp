#include <iostream>
#include <fstream>
#include <algorithm> 
#include <vector>
#include <string>
#include <stdlib.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::min_element;

int main()
{
    int num_1, num_2, temp;
    double mean, sum = 0;

    std::string line;
    std::ifstream in("D:\\input.txt");
    std::ofstream out_row("D:\\out_row.txt", std::ios::out);
    std::ofstream out_col("D:\\out_col.txt", std::ios::out);

    if (in.is_open() && out_row.is_open())
    {
        in >> num_1 >> num_2;

        std::vector<std::vector<int>> matrix_row(num_1, std::vector<int>(num_2));
        std::vector<std::vector<int>> matrix_col(num_1, std::vector<int>(num_2));
        std::vector<int> minmax_str;
        for (int i = 0; i < num_1; i++) {
            for (int k = 0; k < num_2; k++) {
                if (k == num_2 - 1) {
                    getline(in, line, '\n');
                }
                else {
                    getline(in, line, ',');
                }
                matrix_row[i][k] = stoi(line);
                matrix_col[i][k] = stoi(line);
                sum += matrix_row[i][k];
                minmax_str.push_back(matrix_row[i][k]);
            }
        }
        auto minmax = std::minmax_element(minmax_str.begin(), minmax_str.end());
        mean = sum / (num_1 * num_2);
        
        out_row << "mean = " << mean << endl;
        out_col << "mean = " << mean << endl;
        out_row << "max = " << *minmax.second << endl;
        out_col << "max = " << *minmax.second << endl;
        out_row << "min = " << *minmax.first << endl;
        out_col << "min = " << *minmax.first << endl;
 
        for (int i = 0; i < num_1; i++) {
            sort(matrix_row[i].begin(), matrix_row[i].end());
            for (int k = 0; k < num_2; k++) {
                out_row << matrix_row[i][k] << " ";
            }
            out_row << endl;
        }
        for (int j = 0; j < num_2; j++) {
            for (int k = 0; k < num_1 - 1; k++) {
                for (int i = 0; i < num_1 - k - 1; i++) {
                    if (matrix_col[i][j] < matrix_col[i + 1][j]) {
                        temp = matrix_col[i][j];
                        matrix_col[i][j] = matrix_col[i + 1][j];
                        matrix_col[i + 1][j] = temp;
                    }
                }
            }
        }
        for (int i = 0; i < num_1; i++) {
            for (int k = 0; k < num_2; k++) {
                out_col << matrix_col[i][k] << " ";
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
