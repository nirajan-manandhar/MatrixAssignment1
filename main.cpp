
#include "matrix.hpp"

using namespace std;

int main() {

    matrix* mat = new matrix(6,7);

    mat->setvalue(0,2,9.7);

    cout << *mat << endl;

    cout << "Hello, World!" << endl;
    return 0;
}