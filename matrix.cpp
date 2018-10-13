//
// Created by Nirajan on 2018-10-12.
//

#include "matrix.hpp"

matrix::matrix() {
    vectormatrix.resize(0);
    vectormatrix[0].resize(1, 0.0);

}

matrix::matrix(int n) {
    if (n <= 0) {
        throw "n cannot be zero or negative";
    }

    vectormatrix.resize(n);
    for(int i = 0; i < n; i++)
        vectormatrix[i].resize(n, 0.0);
}

matrix::matrix(int r, int c) {
    if(r<=0 || c<=0) {
        throw "r and c have to be positive values";
    }

    vectormatrix.resize(r);
    for(int i = 0; i < r; i++)
        vectormatrix[i].resize(c, 0.0);
}

matrix::matrix(vector<double> vector1){
    int size = vector1.size();
    double root = sqrt(size);

    if (floor(root) != root) {
        throw "received negative value";
    }

    vectormatrix.resize(root);
    for (int i = 0; i < root; i++)
        vectormatrix[i].resize(root);

    for (int j = 0; j < vectormatrix.size(); j++) {
        for (int k = 0, index = 0; k < vectormatrix[j].size(); k++, index++) {
            vectormatrix[j][k] = vector1[index];
        }
    }

}


void matrix::setvalue(int row, int column, double value) {
    if(row > vectormatrix.size() || column > vectormatrix[1].size() ||
        row <= 0 || column <= 0) {
        throw "Invalid Input for matrix(row, column, double";
    }

    vectormatrix[row][column] = value;
}

double matrix::getvalue(int row, int column) {
    return vectormatrix[row][column];
}

void matrix::clear(){
    for (int j = 0; j < vectormatrix.size();j++) {
        for (int k = 0, index = 0; k < vectormatrix[j].size(); k++, index++) {
            vectormatrix[j][k] = 0.0;
        }
    }
}

ostream& operator<<(ostream& out, const matrix& matrix) {


    for (int j = 0; j <  matrix.vectormatrix.size();j++) {
        size_t last = matrix.vectormatrix[j].size() - 1;
        out << "[";
        for (int k = 0, index = 0; k < matrix.vectormatrix[j].size(); k++, index++) {
            out << matrix.vectormatrix[k][j];
            if (k != last)
                out << ", ";
        }
        out << "]" << endl;
    }
    return out;
}

bool operator==( const matrix& lhs, const matrix& rhs ) {

    unsigned long loutersize = lhs.vectormatrix.size();
    unsigned long routersize = rhs.vectormatrix.size();

    unsigned long linnersize = lhs.vectormatrix[0].size();
    unsigned long rinnersize = rhs.vectormatrix[0].size();

    if(loutersize != routersize
    || linnersize != rinnersize){
        return false;
    }

    for (int j = 0; j < loutersize;j++) {
        for (int k = 0, index = 0; k < routersize; k++, index++) {
            double TOLERANCE = (lhs.vectormatrix[j][k]) - (rhs.vectormatrix[j][k]);
            if (TOLERANCE >= 0.1)
                return false;
        }
    }

    return true;
}

const matrix &matrix::operator++() {
    for (int j = 0; j < vectormatrix.size();j++) {
        for (int k = 0, index = 0; k < vectormatrix[j].size(); k++, index++) {
            vectormatrix[j][k] += 1;
        }
    }
    return *this;
}

const matrix matrix::operator++(int) {
    matrix tmp (*this);
    for (int j = 0; j < vectormatrix.size();j++) {
        for (int k = 0, index = 0; k < vectormatrix[j].size(); k++, index++) {
            vectormatrix[j][k] += 1;
        }
    }
    return tmp ;
}

const matrix &matrix::operator--() {
    for (int j = 0; j < vectormatrix.size();j++) {
        for (int k = 0, index = 0; k < vectormatrix[j].size(); k++, index++) {
            vectormatrix[j][k] -= 1;
        }
    }
    return *this;
}

const matrix matrix::operator--(int) {
    matrix tmp (*this);
    for (int j = 0; j < vectormatrix.size();j++) {
        for (int k = 0, index = 0; k < vectormatrix[j].size(); k++, index++) {
            vectormatrix[j][k] -= 1;
        }
    }
    return tmp ;
}













