#include <iostream>
#include <math.h>

using namespace std;

double fdx (double a){
    return -0.5*pow(a,2)+2.5*a+4.5;
}


int main(){
    double xi=5, xs=10, xm=0;
    double tol=0;

    if(fdx(xi)*fdx(xs) < 0){
        xm=0.5*(xi+xs);
    }

    cout<< xm<< endl;
    return 0;
}
