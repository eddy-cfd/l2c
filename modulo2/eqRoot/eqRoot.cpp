#include <csignal>
#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

double fdx (double a){
//return -0.5*pow(a,2)+2.5*a+4.5;
//return 5*pow(a,3)-5*pow(a,2)+6*a-2;
//return -25+82*a-90*pow(a,2)+44*pow(a,3)-8*pow(a,4)+0.7*pow(a,5);
//return sin(a)-pow(a,3);
//return log(a*pow(a,4))-0.7;
  return pow(a,10)-1;
}

void bis (double a, double b){
  int n=0;
  double xi=a, xs=b, xpast=0, xnow=0;
  double err=0;
  const double tol=0.001;
  //
  //arquivo de saída de dados
  ofstream bis ("bissecao.dat");
  bis<<"#Raízes pelo método da bisseção \n"
     <<"#iteração raiz erAprox\n";
  //
  cout<< "\n"<< "#bisseção"<< endl;
  do{
    if(fdx(xi)*fdx(xs) < 0){
      xnow= 0.5*(xi+xs);
      err=abs(xnow-xpast)/xnow;
      xpast=xnow;
      if(fdx(xi)*fdx(xnow)<0) xs=xnow;
      else if (fdx(xnow)*fdx(xs)<0) xi=xnow;
    }else {cout<< "Não existe raiz neste intervalo"<< endl; break;}
    n++;
    cout<< n<< " "<< xnow<< " "<< err<<  endl;
    bis<< n<< " "<< xnow<< " "<< err<<  endl;
  }while (err >= tol);
}

void falsaPos (double a, double b){
  int n=0;
  double xi=a, xs=b, xpast=0, xnow=0;
  double err=0;
  const double tol=0.001;
  //
  //arquivo de saída de dados
  ofstream falsaPos ("falsaPos.dat");
  falsaPos<<"#Raízes pelo método da falsa posição \n"
     <<"#iteração raiz erAprox\n";
  //
  cout<< "\n"<< "#falsaPosição"<< endl;
  do{
    if(fdx(xi)*fdx(xs) < 0){
      xnow= xs-((fdx(xs)*(xi-xs))/(fdx(xi)-fdx(xs)));
      err=abs(xnow-xpast)/xnow;
      xpast=xnow;
      if(fdx(xi)*fdx(xnow)<0) xs=xnow;
      else if (fdx(xnow)*fdx(xs)<0) xi=xnow;
    }else {cout<< "Não existe raiz neste intervalo"<< endl; break;}
    n++;
    cout<< n<< " "<< xnow<< " "<< err<<  endl;
    falsaPos<< n<< " "<< xnow<< " "<< err<<  endl;
  }while (err >= tol);
}

void hybrid (double a, double b){
  int n=0;
  double xi=a, xs=b, xpast=0, xnow=0;
  double err=0;
  const double tol=0.001;
  //
  //arquivo de saída de dados
  ofstream hybrid ("hibrido.dat");
  hybrid<<"#Raízes pelo método híbrido \n"
     <<"#iteração raiz erAprox\n";
  //
  cout<< "\n"<< "#híbrido"<< endl;
  do{
    if(fdx(xi)*fdx(xs) < 0){
      if (n<2) xnow= 0.5*(xi+xs);
      else xnow= xs-((fdx(xs)*(xi-xs))/(fdx(xi)-fdx(xs)));
      err=abs(xnow-xpast)/xnow;
      xpast=xnow;
      if(fdx(xi)*fdx(xnow)<0) xs=xnow;
      else if (fdx(xnow)*fdx(xs)<0) xi=xnow;
    }else {cout<< "Não existe raiz neste intervalo"<< endl; break;}
    n++;
    cout<< n<< " "<< xnow<< " "<< err<<  endl;
    hybrid<< n<< " "<< xnow<< " "<< err<<  endl;
  }while (err >= tol);
}

int main(){
    bis(0.9,1.5);
    falsaPos(0.9,1.5);
    hybrid(0.9,1.5);
  return 0;
}
