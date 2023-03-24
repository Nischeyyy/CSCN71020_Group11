#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "main.h"
#include "triangleSolver.h"

int side = 0;

int main() {
    bool continueProgram = true;
    double triangleSides[3] = { 0.0, 0.0, 0.0 };
    double* triangleSidesPtr;
    char result[60] = "";

    while (continueProgram) {
        printWelcome();
        int shapeChoice = printShapeMenu();
        switch (shapeChoice)
        {
        case 2:
            printf_s("Triangle inside angles slected");
            triangleSidesPtr = getTriangleSides(triangleSides);
            TriangleInsideAngles(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2], result);
            printf_s("%s\n", result);
            break;
        case 1:
            printf_s("Triangle analysis selected.\n");
            triangleSidesPtr = getTriangleSides(triangleSides);
            //printf_s("! %d\n", triangleSidesPtr[0]);
            analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2], result);
            printf_s("%s\n", result);
            break;
        case 0:
            continueProgram = false;
            break;
        default:
            printf_s("Invalid value entered.\n");
            break;
        }
    }
    return 0;
}



void printWelcome() {
    printf_s("\n");
    printf_s(" **********************\n");
    printf_s("**     Welcome to     **\n");
    printf_s("**   Polygon Checker  **\n");
    printf_s(" **********************\n");
}


int printShapeMenu() {
    printf_s("1. Triangle Analysis\n");
    printf_s("2. Triangle Inside angles\n");
    printf_s("0. Exit\n");

    int shapeChoice;

    printf_s("Enter number: ");
    scanf_s("%1o", &shapeChoice);
    
    return shapeChoice;
}


double* getTriangleSides(double* triangleSides) {
    printf_s("Enter the three sides of the triangle: \n");
    for (int i = 0; i < 3; i++)
    {
        scanf_s("%lf", &triangleSides[i]);
    }
    return triangleSides;
}