
#include <iostream>
#include <cmath>
using namespace std;

double Function(double x, double y) {
  return 2*x*x+2*y;
}

int main() {

 double a = 0;
 double b = 1;
 double h = 0.1;
 double N = (b-a) / h;
 double X[(int)N];
 double Y[(int)N];
 X[0]=a;
 Y[0]=1;

cout<<endl;

for(size_t i = 1; i <= N; i++) {
    X[i] = a + i * h;
    Y[i] = Y[i-1] + h * Function(X[i-1], Y[i-1]);
}

for(size_t i = 0; i <= N; i++) {
    cout << "X["<<i<<"]="<<X[i] <<" "<<endl;
}
cout << endl;

for(size_t i = 0; i <= N; i++){
    cout << "Y["<<i<<"]="<<Y[i] << " "<<endl;
}

return 0;
}
