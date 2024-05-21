#include "classes.h"
#include <iostream>

int main() {
    Mat m1(2,2), m2(2,2);
    m1.Value(0,0,1.0); m1.Value(0,1,2.0); m1.Value(1,0,3.0); m1.Value(1,1,4.0);
    m2.Value(0,0,1.0); m2.Value(0,1,2.0); m2.Value(1,0,3.0); m2.Value(1,1,4.0);

    Vect v1(3,new double[3]{1,2,3}), v2(3,new double[3]{1,2,3}), v3(3,new double[3]);
    double s=2;

    m1=m2; Mat m3=m1+m2; m3=m1-m2; m3=m1*m2; m3=m1*s; v3=v1*m1; v3.printV(); m3=m1.negativeMatrix(m1);
    v3=v1; v3=v1+v2; v3=v1-v2; v3=v1*v2; v3=v1/v2; v3=v1*s; v3=v1.negativeVect(v1); v3.printV();

    return 0;
}
