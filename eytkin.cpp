#include<iostream>
#include<cmath>
using namespace std;

double function(double X);
double trapezoid_method(double N);
double integral_eytkin(double N, double M, double L);
double error_trapezoid_method(double N, double M, double L);
double error_integral_eytkin(double N, double M, double L, double I);
double P(double N, double M, double L);


double trapezoid_method(double N) {
	double H = 1. / N;
	double S = 0.;
	const int l = 1.;
	for (double i = 0.; i < l; i += H)	{
		S += (function(i + H) + function(i)) / 2. * H;
	}
	return S;
}



double P(double N, double M, double L) {
	double alpha = 0.5;
	double P = log((trapezoid_method(N) - trapezoid_method(M)) / (trapezoid_method(M) - trapezoid_method(L))) / log(alpha);
	return P;
}


double function(double X) {
	double f;
	f = sqrt(1-pow(X,2));
	return f;
}



double error_trapezoid_method(double N, double M, double L) {
	double alpha = 0.5;
	double er = pow(alpha, P(N, M, L)) / (1 - pow(alpha, P(N, M, L)))*abs(trapezoid_method(N) - trapezoid_method(M));
	return er;
}


double integral_eytkin(double N, double M, double L) {
	double alpha = 0.5;
	double integral;
	integral = (pow(trapezoid_method(M), 2) - trapezoid_method(L)*trapezoid_method(N)) / (2 * trapezoid_method(M) - trapezoid_method(L) - trapezoid_method(N));
	return integral;
}


double error_integral_eytkin(double N, double M, double L, double I) {
	double er = abs((integral_eytkin(N, M, L) - integral_eytkin(M, L, I)) / integral_eytkin(M, L, I));
	return er;
}




int main() {

	cout << trapezoid_method(1) << "  " << "        " << "   " << "       " << endl;
	cout << trapezoid_method(2) << "  " << P(4, 2, 1) << "   " <<error_trapezoid_method(4, 2, 1) << "       " << integral_eytkin(4, 2, 1) << "   " << endl;
	cout << trapezoid_method(4) << "  " << "        " << "   " << "       " << endl;
	cout << trapezoid_method(8) << "  " << P(8, 4, 2) << "   " << error_trapezoid_method(8, 4, 2) << "       " << integral_eytkin(8, 4, 2) << "   " << endl;
	cout<<error_integral_eytkin(8, 4, 2, 1) << endl;
	cout<<endl;
	cout << trapezoid_method(16) << "  " << "        " << "   " << "       " << endl;
	cout << trapezoid_method(32) << "  " << P(64, 32, 16) << "   " << error_trapezoid_method(64, 32, 16) << "       " <<integral_eytkin(64, 32, 16) << "   " << endl;
	cout << trapezoid_method(64) << "  " << "        " << "   " << "       " << endl;
	cout << trapezoid_method(128) << "  " << P(128, 64, 32) << "   " <<error_trapezoid_method(128, 64, 32) << "       " << integral_eytkin(128, 64, 32) << "   " <<endl;
	cout<<error_integral_eytkin(128, 64, 32, 16) << endl;
	cout<<endl;
	cout << trapezoid_method(256) << "  " << "        " << "   " << "   " << endl;
	cout << trapezoid_method(512) << "  " << P(1024., 512., 256) << "   " << error_trapezoid_method(1024, 512, 256) << "       " << integral_eytkin(1024, 512, 256) << "   " << endl;
	cout << trapezoid_method(1024) << "  " << "        " << "   " << "   " << endl;
	cout << trapezoid_method(2048) << "  " << P(2048, 1024, 512) << "   " << error_trapezoid_method(2048, 1024, 512) << "       " << integral_eytkin(2048, 1024, 512) << "   " <<endl;
  cout<<error_integral_eytkin(2048, 1024, 512, 256) << endl;
  cout<<endl;

  return 0;
}
