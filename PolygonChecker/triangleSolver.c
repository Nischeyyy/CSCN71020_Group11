#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#include "triangleSolver.h"

#define Pi 3.141592653589

void analyzeTriangle(double side1, double side2, double side3, char result[]) { //Function to analyze triangle

    if (side1 + side2 > side3 && side1 + side3 > side2 && side2 + side3 > side1 && side1 > 0 && side2 > 0 && side3 > 0) //Condition to check if sides can make a triangle
    {
        if (side1 == side2 && side2 == side3) //conditions to tell the type of triangle
        {
            strcpy(result, "Equilateral triangle");
        }
        else if (side1 == side2 || side2 == side3 || side1 == side3)
        {
            strcpy(result, "Isosceles triangle");
        }
        else
        {
            strcpy(result, "Scalene triangle");
        }
    }
    else
    {
        strcpy(result, "Not a triangle");
    }
}



void TriangleInsideAngles(double a, double b, double c, char result[]) //function to get inside angles of triangle
{
    double angleA, angleB, angleC;
    if (!(a + b > c && a + c > b && b + c > a && a > 0 && b > 0 && c > 0)) //Condition to check if sides can make a triangle
    {
        strcpy(result, "The triangle cannot be made");
    }
    else
    {
        angleA = acos((b * b + c * c - a * a) / (2 * b * c)) * 180 / Pi; //Mathematical logic to get the angles
        angleB = acos((a * a + c * c - b * b) / (2 * a * c)) * 180 / Pi;
        angleC = acos((a * a + b * b - c * c) / (2 * a * b)) * 180 / Pi;
        sprintf(result, "This triangle's angles are %3.2lf, %3.2lf, %3.2lf", angleA, angleB, angleC);
    }
}