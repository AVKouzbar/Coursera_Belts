#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;

class Matrix {
public:
    vector<vector<int>> data_matrix;
    int rows = 0;
    int cols = 0;

    Matrix () {
        rows = 0;
        cols = 0;
         }

    Matrix(int num_rows, int num_cols) {
        if (num_rows >= 0 && num_cols >= 0) {
            Reset(num_rows, num_cols);
        } else throw out_of_range("");
        }

    void Reset ( int new_rows_num, int new_cols_num) {
        if (new_rows_num >= 0 && new_cols_num >= 0) {
            if (new_rows_num == 0 || new_cols_num == 0 ) {
                new_rows_num = new_cols_num = 0;
            }
            rows = new_rows_num;
            cols = new_cols_num;
            data_matrix.assign(new_rows_num, vector<int> (new_cols_num));

        } else throw out_of_range("");
    }

    int At (int row, int col) const {  // Need exception
        return data_matrix.at(row).at(col);
    }

    int& At ( int row, int col) {
            return data_matrix.at(row).at(col);
            }

    int GetNumRows () const {
        return  rows;
    }

    int GetNumColumns () const {
        return cols;
    };


private:


};

istream& operator >>(istream& stream, Matrix& matrix) {
    int rows = 0, cols = 0;
    stream >> rows >> cols;
    matrix.Reset(rows, cols);
    for (int row = 0; row < rows; ++row) {
        for (int column = 0; column < cols; ++column) {
            stream >> matrix.At(row, column);
        }
    }

    return stream;
}

ostream& operator <<(ostream& stream, const Matrix& data ) {
    stream << data.GetNumRows() << " " << data.GetNumColumns() << endl;
    for (auto i : data.data_matrix) {
        for (auto j : i) {
            stream  <<  j  << " ";
        }
        stream << endl;
    }
    return stream;
}

bool operator ==(const Matrix& one, const Matrix& two) {
    if (one.GetNumRows() != two.GetNumRows()) {
        return false;
    }

    if (one.GetNumColumns() != two.GetNumColumns()) {
        return false;
    }

    for (int row = 0; row < one.GetNumRows(); ++row) {
        for (int column = 0; column < one.GetNumColumns(); ++column) {
            if (one.At(row, column) != two.At(row, column)) {
                return false;
            }
        }
    }

    return true;
}

Matrix operator+(const Matrix& one, const Matrix& two){
    if (one.GetNumRows() != two.GetNumRows()) {
        throw invalid_argument("");
    }

    if (one.GetNumColumns() != two.GetNumColumns()) {
        throw invalid_argument("");
    }
    Matrix result(one.GetNumRows(), one.GetNumColumns());

    for (int row = 0; row < result.GetNumRows(); ++row) {
        for (int column = 0; column < result.GetNumColumns(); ++column) {
            result.At(row, column) = one.At(row, column) + two.At(row, column);
        }
    }

    return result;
}

// Реализуйте здесь
// * класс Matrix
// * оператор ввода для класса Matrix из потока istream
// * оператор вывода класса Matrix в поток ostream
// * оператор проверки на равенство двух объектов класса Matrix
// * оператор сложения двух объектов класса Matrix

int main() {
    Matrix one;
    Matrix two;
    Matrix three;
    cin >> one >> two;
    three = one + two;
    cout << three  << endl;
    return 0;
}
