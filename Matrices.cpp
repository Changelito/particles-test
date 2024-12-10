#include "Matrices.h"

namespace Matrices {

    Matrix::Matrix(int _rows, int _cols) : rows(_rows), cols(_cols) {
        a.resize(rows, vector<double>(cols, 0));
    }

    TranslationMatrix::TranslationMatrix(double xShift, double yShift, int nCols)
        : Matrix(2, nCols) {
        for (int j = 0; j < nCols; ++j) {
            a[0][j] = xShift;
            a[1][j] = yShift;
        }
    }

    ScalingMatrix::ScalingMatrix(double scale)
        : Matrix(2, 2) {
        a[0][0] = scale;
        a[1][1] = scale;
    }

    RotationMatrix::RotationMatrix(double theta)
        : Matrix(2, 2) {
        a[0][0] = cos(theta);
        a[0][1] = -sin(theta);
        a[1][0] = sin(theta);
        a[1][1] = cos(theta);
    }

}  // namespace Matrices
﻿
