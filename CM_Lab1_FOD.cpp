#include <iostream>
#include <array>

using namespace std;

const double dX = 0.01;

double func(double x);
double forward(double x, double dx);
double backward(double x, double dx);
double central(double x, double dx);
double analytical(double x);

int main()
{
	double range {1}, start {0};
	

	cout << "the analytical solution gives: " << "\n";
	for (int i = 0; i < range/dX; i++){
		cout << analytical(i*dX) << " ";
	}
	cout << "\n";

	cout << "the forward scheme gives: " << "\n";
	for (int i = 0; i < range/dX; i++){
		cout << forward(i*dX, dX) << " ";
	}
	cout << "\n";
	
	cout << "the backward scheme gives: " << "\n";
	for (int i = 0; i < range/dX; i++){
		cout << backward(i*dX, dX) << " ";
	}
	cout << "\n";

	cout << "the central scheme gives: " << "\n";
	for (int i = 0; i < range/dX; i++){
		cout << central(i*dX, dX) << " ";
	}

	return 0;
}

double analytical(double x)
{
	return (9*x*x + 2);
}

double func(double x)
{
	return (2 + 3*x*x)*x +1;
}

double forward(double x, double dx)
{
	return (func(x + dx) - func(x))/dx;
}

double backward(double x, double dx)
{
	return (func(x) - func(x - dx))/dx;
}

double central(double x, double dx)
{
	return (func(x + dx) - func(x - dx))/(2*dx);
}
