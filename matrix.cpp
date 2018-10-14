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

    vectormatrix.resize((size_t)n);
    for (int i = 0; i < n; i++)
        vectormatrix[i].resize((size_t)n, 0.0);
}

matrix::matrix(int r, int c) {
    if (r <= 0 || c <= 0) {
        cout << "exception";
        throw "r and c have to be positive values";
    }

    vectormatrix.resize((size_t)r);
    for (int i = 0; i < r; i++) {
        vectormatrix[i].resize((size_t) c, 0.0);
    }
}

matrix::matrix(vector<double> vector1) {
    int size = vector1.size();
    double root = sqrt(size);

    if (floor(root) != root) {
        throw "received negative value";
    }

    vectormatrix.resize((size_t)root);
    for (int i = 0; i < root; i++)
        vectormatrix[i].resize((size_t)root);

    for (auto &j : vectormatrix) {
        for (int k = 0, index = 0; k < j.size(); k++, index++) {
            j[k] = vector1[index];
        }
    }

}


void matrix::setvalue(int row, int column, double value) {
    if (row > vectormatrix.size() || column > vectormatrix[1].size() ||
        row < 0 || column < 0) {

        throw "Input out of range";
    }

    vectormatrix[row][column] = value;
}

double matrix::getvalue(int row, int column) {
    return vectormatrix[row][column];
}

void matrix::clear() {
    for (auto &j : vectormatrix) {
        for (int k = 0, index = 0; k < j.size(); k++, index++) {
            j[k] = 0.0;
        }
    }
}


ostream &operator<<(ostream &out, const matrix &matrix) {


    for (const auto &j : matrix.vectormatrix) {
        size_t last = j.size() - 1;
        out << "[";
        for (int k = 0, index = 0; k < j.size(); k++, index++) {
            out << j[k];
            if (k != last)
                out << ", ";
        }
        out << "]" << endl;
    }
    return out;
}

bool operator==(const matrix &lhs, const matrix &rhs) {

    unsigned long loutersize = lhs.vectormatrix.size();
    unsigned long routersize = rhs.vectormatrix.size();

    unsigned long linnersize = lhs.vectormatrix[0].size();
    unsigned long rinnersize = rhs.vectormatrix[0].size();

    if (loutersize != routersize
        || linnersize != rinnersize) {
        return false;
    }

    for (int j = 0; j < loutersize; j++) {
        for (int k = 0, index = 0; k < routersize; k++, index++) {
            double TOLERANCE = (lhs.vectormatrix[j][k]) - (rhs.vectormatrix[j][k]);
            if (TOLERANCE >= 0.1)
                return false;
        }
    }

    return true;
}

const matrix &matrix::operator++() {
    for (auto &j : vectormatrix) {
        for (int k = 0, index = 0; k < j.size(); k++, index++) {
            j[k] += 1;
        }
    }
    return *this;
}

const matrix matrix::operator++(int) {
    matrix tmp(*this);
    for (auto &j : vectormatrix) {
        for (int k = 0, index = 0; k < j.size(); k++, index++) {
            j[k] += 1;
        }
    }
    return tmp;
}

const matrix &matrix::operator--() {
    for (auto &j : vectormatrix) {
        for (int k = 0, index = 0; k < j.size(); k++, index++) {
            j[k] -= 1;
        }
    }
    return *this;
}

const matrix matrix::operator--(int) {
    matrix tmp(*this);
    for (auto &j : vectormatrix) {
        for (int k = 0, index = 0; k < j.size(); k++, index++) {
            j[k] -= 1;
        }
    }
    return tmp;
}

matrix::matrix(const matrix &matrix) {
    for (int j = 0; j < vectormatrix.size(); j++) {
        for (int k = 0, index = 0; k < vectormatrix[j].size(); k++, index++) {
            vectormatrix[j][k] = matrix.vectormatrix[j][k];
        }
    }
}

void swap(matrix &first, matrix &second) {
    using std::swap;
    swap(first.vectormatrix, second.vectormatrix);
}

matrix &matrix::operator=(matrix m) {
    swap(*this, m);
    return *this;
}

matrix &matrix::operator+=(matrix m) {
    unsigned long lhs = this->vectormatrix.size();
    unsigned long rhs = this->vectormatrix.size();

    unsigned long innerlhs = this->vectormatrix[0].size();
    unsigned long innerrhs = this->vectormatrix[0].size();

    if (lhs != rhs || innerlhs != innerrhs)
        throw "error";

    for (int j = 0; j < this->vectormatrix.size(); j++) {
        for (int k = 0; k < vectormatrix[j].size(); k++) {
            this->vectormatrix[j][k] += m.vectormatrix[j][k];
        }
    }

    return *this;
}

matrix operator+(matrix lhs, const matrix &rhs) {
    unsigned long outerlhs = lhs.vectormatrix.size();
    unsigned long outerrhs = rhs.vectormatrix.size();

    unsigned long innerlhs = lhs.vectormatrix[0].size();
    unsigned long innerrhs = rhs.vectormatrix[0].size();

    if (outerlhs != outerrhs || innerlhs != innerrhs)
        throw "error";


    lhs += rhs;
    return lhs;
}

matrix &matrix::operator-=(matrix m) {

    unsigned long lhs = this->vectormatrix.size();
    unsigned long rhs = this->vectormatrix.size();

    unsigned long innerlhs = this->vectormatrix[0].size();
    unsigned long innerrhs = this->vectormatrix[0].size();

    if (lhs != rhs || innerlhs != innerrhs)
        throw "error";

    if (lhs != rhs || innerlhs != innerrhs)
        throw "error";

    for (int j = 0; j < this->vectormatrix.size(); j++) {
        for (int k = 0; k < vectormatrix[j].size(); k++) {
            this->vectormatrix[j][k] -= m.vectormatrix[j][k];
        }
    }

    return *this;
}

matrix operator-(matrix lhs, const matrix &rhs) {

    unsigned long outerlhs = lhs.vectormatrix.size();
    unsigned long outerrhs = rhs.vectormatrix.size();

    unsigned long innerlhs = lhs.vectormatrix[0].size();
    unsigned long innerrhs = rhs.vectormatrix[0].size();

    if (outerlhs != outerrhs || innerlhs != innerrhs)
        throw "error";

    lhs -= rhs;
    return lhs;
}

matrix &matrix::operator*=(matrix m) {
    unsigned long colsfirst = this->vectormatrix[0].size();
    unsigned long rowssecond = this->vectormatrix.size();

    if (colsfirst != rowssecond)
        throw "error";

    matrix temp((int) this->vectormatrix.size(), (int) m.vectormatrix[0].size());

    for (int j = 0; j < this->vectormatrix.size(); j++) {
        for (int k = 0; k < m.vectormatrix[0].size(); k++) {
            double sum = 0;
            for(int l = 0; l < this->vectormatrix[0].size(); l++) {
                sum += this->vectormatrix[j][l] * m.vectormatrix[l][k];
            }
            temp.setvalue(j,k,sum);
        }
    }

    this->vectormatrix = temp.vectormatrix;

    return *this;
}

matrix operator*(matrix lhs, const matrix &rhs) {
    lhs *= rhs;
    return lhs;
}


































