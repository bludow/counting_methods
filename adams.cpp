#include <iostream>
#include <cmath>
using namespace std;

double function1(double x, double y) {
	return 2 * x * x + 2 * y;
}

double function2(double x, double y) {
	return (y + x) * (y + x);
}

double method_runge_cutta(double(*function1)(double, double), double x0, double y0, double x) {
	double P1, P2, P3, P4;
	double h = 0.1;
	double y = y0;
	double y1 = 0;
	double y2;
	double n = (x - x0) / h;

	static_cast<int>(n);

	for (size_t i = 0; i < n; ++i) {
		P1 = function1(x0 + i * h, y);
		P2 = function1(x0 + i * h + h / 2, y + h * P1 / 2);
		P3 = function1(x0 + i * h + h / 2, y + h * P2 / 2);
		P4 = function1(x0 + i * h + h, y + h * P3);
		y1 = y + (h / 6) * (P1 + 2 * P2 + 2 * P3 + P4);
		y = y1;
	}
	return y1;
  }

int main() {

	double x[11];
	for (size_t i = 0; i < 11; ++i) {
		x[i] = i * 0.1;
	}

	double y[11];
	double h = 0.1;
	for (size_t i = 0; i < 4; ++i) {
		y[i] = method_runge_cutta(function1, 0., 1., x[i]);
	}

	for (size_t i = 4; i < 11; ++i) {
		y[i] = y[i - 1] + h / 24 * (55 * function1(x[i - 1], y[i - 1]) - 59 * function1(x[i - 2], y[i - 2]) + 37 * function1(x[i - 3], y[i - 3]) - 9 * function1(x[i - 4], y[i - 4]));
	}

	for (size_t i = 0; i < 11; ++i) {
		cout << x[i] << "\t\t" << y[i] << endl;
	}
	cout << endl;

}

