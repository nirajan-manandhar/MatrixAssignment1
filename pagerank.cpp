//
// Created by Nirajan on 2018-10-15.
//

#include "pagerank.hpp"
#include <fstream>
#include <iomanip>


pagerank::pagerank() : matrix() {}
pagerank::pagerank(vector<double> v) : matrix(v) {}
pagerank::pagerank(int r, int c) : matrix(r,c) {}


void pagerank::make_importance() {
    //Number of rows
    int rows = (int)vectormatrix.size();

    //Number of columns
    int cols = (int)vectormatrix[0].size();

    //Column Number
    for(int i = 0; i < cols; i++){
        int n = 0;
        //Row Number
        for(int j = 0; j < rows; j++) {
            if(vectormatrix[j][i] == 1){
                n++;
            }
        }

        if(n != 0){
            for(int k = 0; k < rows; k++) {

                if(get_value(k,i)==1)
                    vectormatrix[k][i] /= n;

            }
        }
    }

}

void pagerank::make_stochastic() {
    //Number of rows
    int rows = (int)vectormatrix.size();

    //Number of columns
    int cols = (int)vectormatrix[0].size();

    //Column Number
    for(int i = 0; i < cols; i++){
        int n = 0;
        //Row Number
        for(int j = 0; j < rows; j++) {
            if((bool)get_value(j,i)){
                n++;
            }
        }

        if(n == 0){
            for(int k = 0; k < rows; k++) {
                set_value(k, i, (double) 1.0/vectormatrix.size());
            }
        }
    }
}

void pagerank::make_transition(matrix& m) {
    matrix* Q = new matrix(vectormatrix.size());

    for(int x = 0; x < vectormatrix.size(); x++){
        for(int y = 0; y < vectormatrix[0].size(); y++){
            Q->set_value(x,y,(double) 1/vectormatrix.size());
        }
    }
    const double P = 0.85;
    matrix* S = this;

    for(int x = 0; x < S->vectormatrix.size(); x++){
        for(int y = 0; y < S->vectormatrix[0].size(); y++){
            double value = get_value(x,y);
            S->set_value(x,y,(P)*(value));
        }
    }

    matrix* Q1 = Q;

    for(int x = 0; x < Q->vectormatrix.size(); x++){
        for(int y = 0; y < Q->vectormatrix[0].size(); y++){
            double value = Q->get_value(x,y);
            Q1->set_value(x,y,(1-P)*(value));
        }
    }

    matrix M(Q->vectormatrix.size());

    M = *S + *Q1;

    m = M;
}

void pagerank::make_rank() {

    for(int x = 0; x < vectormatrix.size(); x++){
        for(int y = 0; y < vectormatrix[0].size(); y++){
            this->set_value(x,y,1);
        }
    }
}

void pagerank::markov(matrix& M, matrix& r) {

    matrix rank = *this;

    while(rank != M * rank)
        rank = M * rank;


    //Column Number
    double sum = 0;
    for(int i = 0; i < rank.vectormatrix.size(); i++) {
        sum += get_value(i, 0);
    }
    for(int j = 0; j < rank.vectormatrix.size(); j++) {
        rank.set_value(j, 0, rank.get_value(j,0)/ sum);
    }

    r = rank;
}


void pagerank::printRank(matrix& rank) {
    char page = 'A';

    for (auto &i : rank.vectormatrix) {
        cout << "Page " << page << ": " << std::fixed << std::setprecision(2) << i[0] * 100 << "%" << std::endl;
        page++;
    }




}
