//
// Created by Nirajan on 2018-10-12.
//

#ifndef MATRIXASSIGNMENT1_MATRIX_HPP
#define MATRIXASSIGNMENT1_MATRIX_HPP

#include <iostream>
#include <vector>
#include <cmath>


using namespace std;

class matrix {

private:
    vector< vector<double> > vectormatrix;
public:
    //Default constructor
    matrix();

    //constructor that accepts a positive integer n and creates a
    // square n x n matrix that contains 0.0s.
    matrix(int);

    //constructor that accepts two positive integers r and c and
    //creates a matrix with r rows and c columns that contains 0.0s.
    matrix(int, int);

    //constructor that accepts an array of double. The size of the
    //array must have an integer square root
    matrix(vector<double>);

    //3-parameter mutator called set value that accepts two integers
    //representing row and column and a double representing the new value
    //for the specified location.
    void setvalue(int, int, double);

    //2-parameter accessor that accepts two integers
    //representing row and column and returns the value in the matrix from
    //the specified location.
    double getvalue(int, int);

    //sets all values in the matrix to 0.0
    void clear();

    //Destructor
    ~matrix()= default;

    friend ostream& operator<<(ostream& out, const vector<vector<double>>& matrix);


};


#endif //MATRIXASSIGNMENT1_MATRIX_HPP
