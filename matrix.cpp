//
// Created by Nirajan on 2018-10-12.
//

#include "matrix.hpp"

matrix::matrix() {
    vectormatrix.resize(0);
    vectormatrix[0].resize(1, 0.0);

}

matrix::matrix(int n) {
    try{
        if (n <= 0)
            throw invalid_argument("Error: n cannot be zero or negative");

    }catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
        exit(EXIT_FAILURE);
    }

    vectormatrix.resize((size_t)n);
    for (int i = 0; i < n; i++)
        vectormatrix[i].resize((size_t)n, 0.0);
}

matrix::matrix(int r, int c) {
    try{
        if (r < 0 || c < 0)
            throw invalid_argument("Error: r and c have to be positive values");

    }catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
        exit(EXIT_FAILURE);
    }

    vectormatrix.resize((size_t)r);
    for (int i = 0; i < r; i++) {
        vectormatrix[i].resize((size_t) c, 0.0);
    }
}

matrix::matrix(vector<double> vector1) {
    size_t size = vector1.size();
    double root = sqrt(size);

    try{
        if (floor(root) != root)
            throw invalid_argument("Error: Size of vector has to be square rootable.");

    }catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
        exit(EXIT_FAILURE);
    }

    vectormatrix.resize((size_t)root);
    for (int i = 0; i < root; i++)
        vectormatrix[i].resize((size_t)root);

    int index = 0;
    for (auto &j : vectormatrix) {
        for (int k = 0; k < j.size(); k++, index++) {
            j[k] = vector1[index];
        }
    }

}


void matrix::set_value(int row, int column, double value) {

    try{
        if (row > vectormatrix.size() || column > vectormatrix[1].size() ||
            row < 0 || column < 0)
            throw invalid_argument("Error: SetValue, Input out of range");

    }catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
        exit(EXIT_FAILURE);
    }

    vectormatrix[row][column] = value;
}

double matrix::get_value(int row, int column) const {
    try{
        if(row < 0 || column < 0 || row > vectormatrix.size() || column > vectormatrix[0].size())
            throw invalid_argument("Vector coordinates are invalid!");

    } catch (const std::exception& e){
        std::cerr << e.what() << '\n';
        exit(EXIT_FAILURE);
    }

    return vectormatrix[row][column];
}

void matrix::clear() {
    for (auto &j : vectormatrix) {
        for (int k = 0; k < j.size(); k++) {
            j[k] = 0.0;
        }
    }
}


ostream &operator<<(ostream &out, const matrix &matrix) {


    for (const auto &j : matrix.vectormatrix) {
        size_t last = j.size() - 1;
        out << "[";
        for (int k = 0; k < j.size(); k++) {
            out << j[k];
            if (k != last)
                out << ", ";
        }
        out << "]" << endl;
    }
    return out;
}

bool operator==(const matrix& lhs, const matrix& rhs) {

    unsigned long loutersize = lhs.vectormatrix.size();
    unsigned long routersize = rhs.vectormatrix.size();

    unsigned long linnersize = lhs.vectormatrix[0].size();
    unsigned long rinnersize = rhs.vectormatrix[0].size();

    if (loutersize != routersize
        || linnersize != rinnersize) {
        return false;
    }

    for (int j = 0; j < loutersize; j++) {
        for (int k = 0; k < routersize; k++) {
            double TOLERANCE = (lhs.vectormatrix[j][k]) - (rhs.vectormatrix[j][k]);
            if (TOLERANCE >= 0.00001)
                return false;
        }
    }

    return true;
}

bool operator!=(const matrix &lhs, const matrix &rhs) {
    return !operator==(lhs, rhs);
}

const matrix &matrix::operator++() {
    for (auto &j : vectormatrix) {
        for (int k = 0; k < j.size(); k++) {
            j[k] += 1;
        }
    }
    return *this;
}

const matrix matrix::operator++(int) {
    matrix tmp(*this);
    for (auto &j : vectormatrix) {
        for (int k = 0; k < j.size(); k++) {
            j[k] += 1;
        }
    }
    return tmp;
}

const matrix &matrix::operator--() {
    for (auto &j : vectormatrix) {
        for (int k = 0; k < j.size(); k++) {
            j[k] -= 1;
        }
    }
    return *this;
}

const matrix matrix::operator--(int) {
    matrix tmp(*this);
    for (auto &j : vectormatrix) {
        for (int k = 0; k < j.size(); k++) {
            j[k] -= 1;
        }
    }
    return tmp;
}

matrix::matrix(const matrix& matrix) {
    this->vectormatrix = matrix.vectormatrix;
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

    try{
        if (lhs != rhs || innerlhs != innerrhs)
            throw invalid_argument("Error: += Matrices are not the same size");

    }catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
        exit(EXIT_FAILURE);
    }


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

    try{
        if (outerlhs != outerrhs || innerlhs != innerrhs)
            throw invalid_argument("Error: + Matrices are not the same size");

    }catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
        exit(EXIT_FAILURE);
    }


    lhs += rhs;
    return lhs;
}

matrix &matrix::operator-=(matrix m) {

    unsigned long lhs = this->vectormatrix.size();
    unsigned long rhs = this->vectormatrix.size();

    unsigned long innerlhs = this->vectormatrix[0].size();
    unsigned long innerrhs = this->vectormatrix[0].size();

    try{
        if (lhs != rhs || innerlhs != innerrhs)
            throw invalid_argument("Error: -= Matrices are not the same size");

    }catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
        exit(EXIT_FAILURE);
    }

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

    try{
        if (outerlhs != outerrhs || innerlhs != innerrhs)
            throw invalid_argument("Error: - Matrices are not the same size");

    }catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
        exit(EXIT_FAILURE);
    }

    lhs -= rhs;
    return lhs;
}

matrix& matrix::operator*=(matrix m) {
    unsigned long colsfirst = this->vectormatrix[0].size();
    unsigned long rowssecond = this->vectormatrix.size();

    try{
        if (colsfirst != rowssecond)
            throw invalid_argument("Error: *= Matrices are not compatible sizes");

    }catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
        exit(EXIT_FAILURE);
    }

    matrix temp((int) this->vectormatrix.size(), (int) m.vectormatrix[0].size());

    for (int j = 0; j < this->vectormatrix.size(); j++) {
        for (int k = 0; k < m.vectormatrix[0].size(); k++) {
            double sum = 0;
            for(int l = 0; l < this->vectormatrix[0].size(); l++) {
                sum += this->vectormatrix[j][l] * m.vectormatrix[l][k];
            }
            temp.set_value(j,k,sum);
        }
    }

    this->vectormatrix = temp.vectormatrix;

    return *this;
}

matrix operator*(matrix lhs, const matrix &rhs) {
    lhs *= rhs;
    return lhs;
}


































