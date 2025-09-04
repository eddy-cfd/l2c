#include <csignal>
#include <iostream>
#include <math.h>

using namespace std;

double fdx (double a){
  return -0.5*pow(a,2)+2.5*a+4.5;
}

int main(){
  int n=0;
  double xi=5, xs=10, xm=0;
  double err=0;
  const double tol=0.0001;
  do{
    err=abs((xs-xi))/xi;
    if(fdx(xi)*fdx(xs) < 0){
      xm= 0.5*(xi+xs);
      if(fdx(xi)*fdx(xm)<0) xs=xm;
      else if (fdx(xm)*fdx(xs)<0) xi=xm;
    }else {cout<< "Não existe raiz neste intervalo"<< endl; break;}
    n++;
    cout<< n<< ": "<< xm<< " ; "<< err<<  endl;
  }while (err >= tol);
  return 0;
}
