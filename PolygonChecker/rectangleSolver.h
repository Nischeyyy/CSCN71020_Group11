#pragma once
#define NUMBEROFPOINTS 4
#define NUMBEROFSIDES 4
#define NUMBEROFDIAGONALS 2


typedef struct { //Making a struct (POINT) for the coordinates of the rectangle
    double x;
    double y;
} POINT;

POINT points[NUMBEROFPOINTS]; //defining 4 points

void analyzeRectangle();
double sideLength(POINT a, POINT b);
bool isRectangle(double SIDES[], double DIAGONAL[]);


