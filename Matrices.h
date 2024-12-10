#pragma once
#include <vector>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdexcept>

using namespace std;

namespace Matrices {

    class Matrix {
    protected:
        int rows;
        int cols;
        vector<vector<double>> a;

    public:
        Matrix(int _rows, int _cols);

        inline int getRows() const { return rows; }
        inline int getCols() const { return cols; }

        inline double& operator()(int row, int col) { return a[row][col]; }
        inline const double& operator()(int row, int col) const { return a[row][col]; }

        friend Matrix operator+(const Matrix& a, const Matrix& b);
        friend Matrix operator*(const Matrix& a, const Matrix& b);
        friend bool operator==(const Matrix& a, const Matrix& b);
        friend bool operator!=(const Matrix& a, const Matrix& b);
        friend ostream& operator<<(ostream& os, const Matrix& a);
    };

    class TranslationMatrix : public Matrix {
    public:
        TranslationMatrix(double xShift, double yShift, int nCols);
    };

    class ScalingMatrix : public Matrix {
    public:
        ScalingMatrix(double scale);
    };

    class RotationMatrix : public Matrix {
    public:
        RotationMatrix(double theta);
    };

}  // namespace Matrices
