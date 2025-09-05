#include <csignal>
#include <iostream>
#include <math.h>

using namespace std;

double fdx (double a){
  return -0.5*pow(a,2)+2.5*a+4.5;
  //return 5*pow(a,3)-5*pow(a,2)+6*a-2;
  //return -25+82*a-90*pow(a,2)+44*pow(a,3)-8*pow(a,4)+0.7*pow(a,5);
  //return sin(a)-pow(a,3);
  // return log(a*pow(a,4))-0.7;
}

void bis (double a, double b){
  int n=0;
  double xi=a, xs=b, xpast=0, xnow=0;
  double err=0;
  const double tol=0.001;
  do{
    if(fdx(xi)*fdx(xs) < 0){
      xnow= 0.5*(xi+xs);
      err=abs(xnow-xpast)/xnow;
      xpast=xnow;
      if(fdx(xi)*fdx(xnow)<0) xs=xnow;
      else if (fdx(xnow)*fdx(xs)<0) xi=xnow;
    }else {cout<< "Não existe raiz neste intervalo"<< endl; break;}
    n++;
    cout<< n<< ": "<< xnow<< " ; "<< err<<  endl;
  }while (err >= tol);
}

void falsaPos (double a, double b){
  int n=0;
  double xi=a, xs=b, xpast=0, xnow=0;
  double err=0;
  const double tol=0.001;
  do{
    if(fdx(xi)*fdx(xs) < 0){
      xnow= xs-((fdx(xs)*(xi-xs))/(fdx(xi)-fdx(xs)));
      err=abs(xnow-xpast)/xnow;
      xpast=xnow;
      if(fdx(xi)*fdx(xnow)<0) xs=xnow;
      else if (fdx(xnow)*fdx(xs)<0) xi=xnow;
    }else {cout<< "Não existe raiz neste intervalo"<< endl; break;}
    n++;
    cout<< n<< ": "<< xnow<< " ; "<< err<<  endl;
  }while (err >= tol);
}


int main(){
    bis(5,10);
    falsaPos(5,10);
  return 0;
}
