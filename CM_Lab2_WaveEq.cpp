# include <iostream>
# include <cmath>
# include <vector>

using namespace std;

double fZero(double t, double x);
double fOne(double t, double x);
double signal(double x);
double forward(double x);
double backward(double x);


int main()
{
	double start{-40}, end{40}, NumberOfX{100};
	double dX{(endX-startX)/numberOfX},dT{0.8} U{1};
	double solution[100][100];
	double AnSolution[100][100];
	
	for (int i=0; i<100; i++){
		solution[i][0] = 0;
	}

	for (int i=0; i<100; i++){
		solution[0][i] = fZero(0, (-40+i*dX)); 
	}

	for (int n = 0; n < 99; i++){
		for (int i = 1; i < 100; i++){
			solution[n+1][i] = solution[n][i] + (U*(solution[n][i] - solution[n][i-1])/dX)*dT
		} 
	}

	return 0;
}

double signal(double x)
{
	if (x > 0.00001){
		return 1;
	}else if (x < 0.00001){
		return 1;
	}else{
		return 0;
	}
}

double fZero(double t, double x)
{
	return (signal(x-t) + 1)/2; 
}

double fOne(double t, double x)
{
	return (exp(-(x-t)^2)/2;
}

double 
