#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include "rectangleSolver.h"

double sideLength(POINT a, POINT b) { //Function to return the length when 2 points (coordinates) are given as input

    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

bool isRectangle(double SIDES[], double DIAGONAL[]) { //bool function to check if the sides and diagonals make a rectangle

    if (SIDES[0] == SIDES[2] && SIDES[1] == SIDES[3] && DIAGONAL[0] == DIAGONAL[1]) {
        return true;
    }
    else {
        return false;
    }
}


void analyzeRectangle() { //Main function for the rectangle Feature

    double SIDES[NUMBEROFSIDES];
    double DIAGONAL[NUMBEROFDIAGONALS];
    double perimeter = 0;

    for (int i = 0; i < NUMBEROFSIDES; i++) { //getting all the sides

        SIDES[i] = sideLength(points[i], points[(i + 1) % 4]);
    }

    DIAGONAL[0] = sideLength(points[0], points[2]); //getting the diagonals
    DIAGONAL[1] = sideLength(points[1], points[3]);


    for (int i = 0; i < NUMBEROFSIDES; i++) { //Calculating the perimeter by adding all the sides

        perimeter += SIDES[i];
    }

    printf("Perimeter: %.2lf\n", perimeter);

    if (isRectangle(SIDES, DIAGONAL)) { //Printing the area if the shape is a rectangle

        double area = SIDES[0] * SIDES[1];
        printf("The shape is a rectangle.\n");
        printf("Area: %.2lf\n", area);
    }
    else {

        printf("The shape is not a rectangle.\n");
    }

}
