#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "main.h"
#include "triangleSolver.h"
#include "rectangleSolver.h"

int side = 0;

int main() 
{
    bool continueProgram = true;
    double triangleSides[3] = { 0.0, 0.0, 0.0 };
    double* triangleSidesPtr;
    char result[60] = "";

    while (continueProgram) { //while loop to run the program until the user exits the program
        printWelcome();
        int shapeChoice = printShapeMenu();
        switch (shapeChoice) //switch case to select the option that user has inputted
        {
        case 3:
            printf_s("Rectangle analysis selected.\n");
            getRectangleCoordinates();
            analyzeRectangle();
            
            break;
        case 2:
            printf_s("Triangle inside angles selected\n");
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



void printWelcome() { //Function to print welcome message

    printf_s("\n");
    printf_s(" **********************\n");
    printf_s("**     Welcome to     **\n");
    printf_s("**   Polygon Checker  **\n");
    printf_s(" **********************\n");
}


int printShapeMenu() { //Function to print Shape Menu to display options

    printf_s("1. Triangle Analysis\n");
    printf_s("2. Triangle Inside angles\n");
    printf_s("3. Rectangle Analysis\n");
    printf_s("0. Exit\n");

    int shapeChoice;

    printf_s("Enter number: ");
    if (scanf_s("%d", &shapeChoice) == 0) {
        printf("Invalid Input!");
        exit(1);
    }

    return shapeChoice;
}


double* getTriangleSides(double* triangleSides) { //Function to get the triangle sides from the user

    printf_s("Enter the three sides of the triangle: \n");
    for (int i = 0; i < 3; i++)
    {
        scanf_s("%lf", &triangleSides[i]);
    }
    return triangleSides;
}

void getRectangleCoordinates() { //Function to get Rectangle coordinates from the user

    printf("Enter the coordinates of the four points.\n");
    for (int i = 0; i < NUMBEROFPOINTS; i++) {

        printf("Enter x%d,y%d: ", i + 1, i + 1);
        if (scanf_s("%lf,%lf", &points[i].x, &points[i].y) == 0) {

            printf("Invalid Input!\n");
            exit(1);
        }
    }

}