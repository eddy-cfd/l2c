#include <iostream>
#include <math.h>
using namespace std;

int main() {
    double erroRelPerc= 0.0;
    double deltaT= 0.01;
    double st= 0.5;
    double yTrue= 0.0;
    double y= 0.0;
    double yExato= 0.0;
    double t= 0.0;
    double k1= 0.0;
    double k2= 0.0;
    double k3= 0.0;
    double k4= 0.0;

    cout<< "Entre com passo de tempo: "<< endl;
    cin>> deltaT;
    for (int i= 1; i<= 1/deltaT; i++){
        k1= (1-y)/st;
        k2= (1-(y+k1*deltaT/2))/st;
        k3= (1-(y+k2*deltaT/2))/st;
        k4= (1-(y+k3*deltaT))/st;
        y= y+((k1+2*k2+2*k3+k4)*deltaT)/6;
        t= t+deltaT;
        yExato= 1-exp(-t/st);
        erroRelPerc= 100*(yExato-y)/yExato;
        cout<< "y("<< t<< ") = "<< y<< " | yExato("<< t<< ") = "<< yExato<< " | erTrue% = "<< erroRelPerc<< endl;
    }
    return 0;
}
