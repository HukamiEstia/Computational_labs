#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;

double fZero(double t, double x);
double fOne(double t, double x);
double signal(double x);
double upwind(double curX, double prevX, double dx, double dt);
double central(double curX, double prevX, double nextX, double dx, double dt);


int main()
{
	int numberOfX{200}, numberOfT;
	double startX{-40}, endX{40}, endT{20};
	double dX{(endX-startX)/(numberOfX-1)},dT{0.01}, U{1};
	numberOfT = (int)round(endT/dT);
	double solution[numberOfT][numberOfX];
	double AnSolution[numberOfT][numberOfX];
	
	for (int i=0; i<numberOfT; i++){
		solution[i][0] = 0;
	}
	/*
	for (int i=0; i<numberOfT; i++){
                solution[i][numberOfX-1] = 0;
        }*/


	for (int i=0; i<numberOfX; i++){
		solution[0][i] = fZero(0, (startX+i*dX)); 
	}

	for (int n = 0; n < numberOfT-1 ; n++){
		for (int i = 1; i < numberOfX-1; i++){
			solution[n+1][i] = upwind(solution[n][i], solution[n][i-1],dX, dT);
			/*solution[n+1][i] = central(solution[n][i], solution[n][i-1], solution[n][i+1], dX, dT);*/
		} 
	}
	
	for (int n = 0; n < numberOfT; n++){
                for (int i = 1; i < numberOfX; i++){
			AnSolution[n][i] = fZero(n*dT, i*dX + startX);
		}
	}

	ofstream results ("results.csv");
	if (results.is_open()){
		for (int i = 0; i < numberOfT; i++){
                	for (int j = 0; j < numberOfX; j++){
				results << solution[i][j] << "," ;
			}
			results << "\n";
		} 
	}
	
	ofstream AnResults ("anResults.csv");
        if (AnResults.is_open()){ 
                for (int i = 0; i < 20; i++){
                        for (int j = 0; j < numberOfX; j++){
                                AnResults << AnSolution[i][j] << "," ;
                        }
                        AnResults << "\n";
                }
        }

	return 0;
}

double signal(double x)
{
	if (x > 0.00001){
		return 1;
	}else if (x < 0.00001){
		return -1;
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
	return exp(-pow(x-t,2)/2);
} 

double upwind(double curX, double prevX, double dx, double dt){
	return curX + ((curX - prevX)/dx)*dt;
}

double central(double curX, double prevX, double nextX, double dx, double dt){
	return curX + ((nextX - prevX)/(2*dx))/dt;
}
