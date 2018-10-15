
#include "matrix.hpp"
#include <fstream>


using namespace std;


int main() {
    //Populate the matrix
    vector<double> v;
    int currVal;

    ifstream input;
    input.open("connectivity.txt");

    while(input >> currVal) {
        v.push_back(currVal);
    }

    matrix* matrix1 = new matrix(v);
    cout << *matrix1 << endl;


    matrix* importance = matrix1;






    //Making the importance matrix

    //Number of rows
    int rows = importance->vectormatrix.size();

    //Number of columns
    int cols = importance->vectormatrix[0].size();

    //Column Number
    for(int i = 0; i < cols; i++){
        int n = 0;
        //Row Number
        for(int j = 0; j < rows; j++) {
            if(importance->vectormatrix[j][i]){
                n++;
            }
        }

        if(n != 0){
            for(int k = 0; k < rows; k++) {

                if(importance->getvalue(k,i))
                importance->vectormatrix[k][i] /= n;

            }
        }
     }

     cout << *importance << endl;

     matrix* stochastic = importance;

    //Column Number
    for(int i = 0; i < cols; i++){
        int n = 0;
        //Row Number
        for(int j = 0; j < rows; j++) {
            if(stochastic->getvalue(j,i)){
                n++;
            }
        }

        if(n == 0){
            for(int k = 0; k < rows; k++) {
                stochastic->setvalue(k, i, (double) 1.0/stochastic->vectormatrix.size());
            }
        }
    }

    cout << *stochastic << endl;

    matrix* Q = new matrix(stochastic->vectormatrix.size());

    for(int x = 0; x < stochastic->vectormatrix.size(); x++){
        for(int y = 0; y < stochastic->vectormatrix[0].size(); y++){
            Q->setvalue(x,y,(double) 1/stochastic->vectormatrix.size());
        }
    }

    cout << *Q << endl;

    const double P = 0.85;

    matrix* S = stochastic;

    for(int x = 0; x < S->vectormatrix.size(); x++){
        for(int y = 0; y < S->vectormatrix[0].size(); y++){
            double value = stochastic->getvalue(x,y);
            S->setvalue(x,y,(P)*(value));
        }
    }

    cout << *S << endl;

    matrix* Q1 = Q;

    for(int x = 0; x < Q->vectormatrix.size(); x++){
        for(int y = 0; y < Q->vectormatrix[0].size(); y++){
            double value = Q->getvalue(x,y);
            Q1->setvalue(x,y,(1-P)*(value));
        }
    }

    cout << *Q1 << endl;

    matrix M(Q->vectormatrix.size());

    M = *S + *Q1;

    cout << M << endl;

    matrix rank(M.vectormatrix.size(), 1);


    for(int x = 0; x < rank.vectormatrix.size(); x++){
        for(int y = 0; y < rank.vectormatrix[0].size(); y++){
            rank.setvalue(x,y,1.0);
        }
    }

    for(int i = 0; i < 10; i++)
        rank = M * rank;

    cout << rank << endl;

    //Column Number
    double sum = 0;
    for(int r = 0; r < rank.vectormatrix.size(); r++) {
        sum += rank.getvalue(r, 0);
    }
    for(int j = 0; j < rank.vectormatrix.size(); j++) {
        rank.setvalue(j, 0, rank.vectormatrix[j][0] / sum);
    }

    cout << rank << endl;

    cout << "Hello, World!" << endl;

    return 0;
}