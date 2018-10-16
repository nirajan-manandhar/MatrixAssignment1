//
// Created by Nirajan on 2018-10-15.
//

#ifndef MATRIXASSIGNMENT1_PAGERANK_HPP
#define MATRIXASSIGNMENT1_PAGERANK_HPP


#include "matrix.hpp"

class pagerank : public matrix{

public:
    pagerank();
    pagerank(vector<double>);
    pagerank(int r, int c);

    void make_importance();

    void make_stochastic();

    void make_transition(matrix& m);

    void make_rank();

    void markov(matrix& m, matrix& rank);

    void printRank(matrix& rank);



};


#endif //MATRIXASSIGNMENT1_PAGERANK_HPP
