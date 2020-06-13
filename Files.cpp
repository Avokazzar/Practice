#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using std::cout;
using std::cin;
using std::endl;
using std::stoi;
using std::string;
using std::ifstream;
using std::ofstream;



int main()
{
    int num_1, num_2, ** array_row, ** array_col, temp;
    double mean, sum = 0;

    string line;
    ifstream in("D:\\input.txt"); 
    ofstream out_row("D:\\out_row.txt", std::ios::out);
    ofstream out_col("D:\\out_col.txt", std::ios::out);

    if (in.is_open() && out_row.is_open())
    {
        in >> num_1 >> num_2;

        array_row = new int* [num_1];
        array_col = new int* [num_1];
        for (int i = 0; i < num_1; i++) {
            array_row[i] = new int[num_2];
            array_col[i] = new int[num_2];
        }
        
        for (int i = 0; i < num_1; i++) {
            for (int k = 0; k < num_2; k++) {
                if (k == num_2 - 1) {
                    getline(in, line, '\n');
                }
                else {
                    getline(in, line, ',');
                }
                array_row[i][k] = stoi(line);
                array_col[i][k] = stoi(line);
            }
        }
        for (int i = 0; i < num_1; i++) {
            for (int k = 0; k < num_2; k++) {
                for (int j = num_2 - 1; j > k; j--) {
                    if (array_row[i][j] < array_row[i][j - 1]) {
                        temp = array_row[i][j];
                        array_row[i][j] = array_row[i][j - 1];
                        array_row[i][j - 1] = temp;
                    }
                }
            }
        }
        for (int j = 0; j < num_2; j++) {
            for (int k = 0; k < num_1 - 1; k++) {
                for (int i = 0; i < num_1 - k - 1; i++) {
                    if (array_col[i][j] < array_col[i + 1][j]) {
                        temp = array_col[i][j];
                        array_col[i][j] = array_col[i + 1][j];
                        array_col[i + 1][j] = temp;
                    }
                }
            }
        }
        int max = array_row[0][0], min = array_row[0][0];

        for (int i = 0; i < num_1; i++) {
            for (int k = 0; k < num_2; k++) {
                sum += array_row[i][k];
                if (array_row[i][k] > max) {
                    max = array_row[i][k];
                }
                if (array_row[i][k] < min) {
                    min = array_row[i][k];
                }
            }
        }
        mean = sum / (num_1 * num_2);
        out_row << "mean = " << mean << endl;
        out_col << "mean = " << mean << endl;
        out_row << "max = " << max << endl;
        out_col << "max = " << max << endl;
        out_row << "min = " << min << endl;
        out_col << "min = " << min << endl;

        for (int i = 0; i < num_1; i++) {
            for (int k = 0; k < num_2; k++) {
                out_row << array_row[i][k] << " ";
                out_col << array_col[i][k] << " ";
            }
            out_row << endl;
            out_col << endl;
        }
        cout << "Completed!" << endl;
        for (int i = 0; i < num_1; i++) {
            delete[] array_row[i], array_col[i];
        }
        delete[] array_row, array_col;
    }
    
    in.close();
    out_row.close();
    out_col.close();

    return 0;
}