#include <iostream>
#include <cmath>
using namespace std;

double F(double x, double y) {
  return 2.*x*x + 2.*y;
}

int main() {

const int N = 10;
double x = 0, y = 1, h = 0.1;
double  y0, x0, k1, k2, k3, k4, y1, y2, y3, y4;

y0 = y, x0 = 0;

  for (size_t i = 1; i <= N; i++) {

    y1 = y;
    k1 = F(x, y1);
    x = x + 0.5 * h;

    y2 = y1 + 0.5 * h * k1;
    k2 = F(x, y2);

    y3 = y1 + 0.5 * h * k2;
    k3 = F(x, y3);
    x = x + 0.5 * h;

    y4 = y1 + h * k3;
    k4 = F(x, y4);
    y = y1 + h * (k1 + 2. * k2 + 2. * k3 + k4) / 6.;

    cout << i <<"     " << y << endl;
    cout << endl;
  }

return 0;
}
