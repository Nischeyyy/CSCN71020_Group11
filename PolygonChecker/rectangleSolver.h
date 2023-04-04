#pragma once
#define NUMBEROFPOINTS 4
#define NUMBEROFSIDES 4
#define NUMBEROFDIAGONALS 2


typedef struct {
    double x;
    double y;
} POINT;

POINT points[NUMBEROFPOINTS];

void analyzeRectangle();
double sideLength(POINT a, POINT b);
bool isRectangle(double SIDES[], double DIAGONAL[]);


