#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "triangleSolver.h"

#define Pi 3.14

char* analyzeTriangle(int side1, int side2, int side3) {
	char* result = "";
	if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
		result = "Not a triangle";
	}
	else if (side1 == side2 && side1 == side3) {
		result = "Equilateral triangle";
	}
	else if ((side1 == side2 && side1 != side3) || 
		(side1 == side3 && side1 != side2))
	{
		result = "Isosceles triangle";
	}
	else {
		result = "Scalene triangle";
	}

	return result;
}


void TriangleInsideAngles(double a, double b, double c)
{

	double angleA, angleB, angleC;
	if (!(a + b > c && a + c > b && b + c > a && a > 0 && b > 0 && c > 0))
	{
		printf("The triangle cannot be made");
	}
	else
	{
		angleA = acos((b * b + c * c - a * a) / (2 * b * c));
		angleB = acos((a * a + c * c - b * b) / (2 * a * c));
		angleC = acos((a * a + b * b - c * c) / (2 * a * b));
		printf("This triangle's angles are %lf ,%lf and %lf", angleA * 180 / Pi, angleB * 180 / Pi, angleC * 180 / Pi);
	}
}