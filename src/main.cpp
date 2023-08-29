#include "coin/OsiClpSolverInterface.hpp"

int main (int argc, const char *argv[])
{
    // CLP
    OsiClpSolverInterface model;

    CoinBigIndex start[] = { 0, 1, 2 };
    int index[] = { 0, 0 };
    double values[] = { 1.0, 2.0 };
    double collb[] = { 0.0, 0.0 };
    double colub[] = { 10.0, 10.0 };
    double obj[] = { 1.0, 1.0 };
    double rowlb[] = { 0.0 };
    double rowub[] = { 3.9 };

    // obj: Max x0 + x1
    //  st. x0 + 2 x1 <= 3.9
    //          0 <= x0 <= 10 and integer
    //          0 <= x1 <= 10
    model.loadProblem(2, 1, start, index, values, collb, colub, obj, rowlb, rowub);
    model.setInteger(0);
    model.setObjSense(-1.0);
    

    return 0;
}

