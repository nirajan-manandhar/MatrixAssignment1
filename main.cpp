
#include "matrix.hpp"
#include "pagerank.hpp"
#include <fstream>


using namespace std;


int main() {
    //Populate the matrix
    vector<double> v;
    int currVal;

    ifstream input;
    input.open("../connectivity.txt");

    while(input >> currVal) {
        v.push_back(currVal);
    }


    pagerank pg(v);
    pg.make_importance();//Create importance matrix
    pg.make_stochastic();//Create stochastic matrix
    pg.make_transition(pg);//Create transition matrix
    pagerank rank((int)pg.vectormatrix.size(), 1);//Create rank matrix
    rank.make_rank();//Populate Rank matrix
    rank.markov(pg, rank);//Run markov
    rank.printRank(rank);//Print out results

    return 0;
}