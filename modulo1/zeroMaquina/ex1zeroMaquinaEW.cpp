#include <ios>
#include <iostream>

using namespace std;

int main(){
    double epsilon=1;
    while (epsilon+1 > 1) epsilon=epsilon / 2;
    cout << scientific << epsilon * 2 << endl;
    return 0;
}
