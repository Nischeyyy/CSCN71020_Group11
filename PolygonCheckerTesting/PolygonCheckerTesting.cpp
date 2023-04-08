#include "pch.h"
#include "CppUnitTest.h"

#define NUMBEROFPOINTS 4
#define NUMBEROFSIDES 4
#define NUMBEROFDIAGONALS 2

typedef struct { 
	double x;
	double y;
} POINT;

double SIDES[NUMBEROFSIDES];
double DIAGONAL[NUMBEROFDIAGONALS];
char result[60];


extern "C" void analyzeRectangle();
extern "C" double sideLength(POINT a, POINT b);
extern "C" bool isRectangle(double SIDES[], double DIAGONAL[]);
extern "C" void TriangleInsideAngles(double a, double b, double c, char result[]);
extern "C" void analyzeTriangle(double side1, double side2, double side3, char result[]);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RectangleFeatureTesting
{
	TEST_CLASS(sideLength_Function_Testing)
	{
	public:
		
		TEST_METHOD(SideLengthTesting1)
		{
			POINT a = {-1,-1};
			POINT b = {-9,-7};

			double expected = 10;
			double result = sideLength(a, b);
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(SideLengthTesting2)
		{
			POINT a = {-2,-3};
			POINT b = {1,1};

			double expected = 5;
			double result = sideLength(a, b);
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(SideLengthTesting3)
		{
			POINT a = {0,0};
			POINT b = {0,0};

			double expected = 0;
			double result = sideLength(a, b);
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(SideLengthTesting4)
		{
			POINT a = {-4,-3};
			POINT b = {0,0};

			double expected = 5;
			double result = sideLength(a, b);
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(SideLengthTesting5)
		{
			POINT a = {9,40};
			POINT b = {0,0};

			double expected = 41;
			double result = sideLength(a, b);
			Assert::AreEqual(expected, result);
		}

	};

	TEST_CLASS(isRectangle_Function_Testing)
	{
	public:
		TEST_METHOD(isRectangleTesting1)
		{

			POINT points[] = { {0, 0}, {0, 4}, {4, 4}, {4, 0} };

			for (int i = 0; i < NUMBEROFSIDES; i++) {

				SIDES[i] = sideLength(points[i], points[(i + 1) % 4]);
			}

			DIAGONAL[0] = sideLength(points[0], points[2]);
			DIAGONAL[1] = sideLength(points[1], points[3]);

			Assert::IsTrue(isRectangle(SIDES, DIAGONAL));
		}

		TEST_METHOD(isRectangleTesting2)
		{

			POINT points[] = { {0, 0}, {0, 4.5}, {3.5, 4.5}, {3.5, 0} };

			for (int i = 0; i < NUMBEROFSIDES; i++) {

				SIDES[i] = sideLength(points[i], points[(i + 1) % 4]);
			}

			DIAGONAL[0] = sideLength(points[0], points[2]);
			DIAGONAL[1] = sideLength(points[1], points[3]);

			Assert::IsTrue(isRectangle(SIDES, DIAGONAL));
		}

		TEST_METHOD(isRectangleTesting3)
		{

			POINT points[] = { {-4, 0}, {-4, -6}, {2, -6}, {2, 0} };

			for (int i = 0; i < NUMBEROFSIDES; i++) {

				SIDES[i] = sideLength(points[i], points[(i + 1) % 4]);
			}

			DIAGONAL[0] = sideLength(points[0], points[2]);
			DIAGONAL[1] = sideLength(points[1], points[3]);

			Assert::IsTrue(isRectangle(SIDES, DIAGONAL));
		}

		TEST_METHOD(isRectangleTesting4)
		{

			POINT points[] = { {-3, -7}, {1, -7}, {1, -1}, {-3, -1} };

			for (int i = 0; i < NUMBEROFSIDES; i++) {

				SIDES[i] = sideLength(points[i], points[(i + 1) % 4]);
			}

			DIAGONAL[0] = sideLength(points[0], points[2]);
			DIAGONAL[1] = sideLength(points[1], points[3]);

			Assert::IsTrue(isRectangle(SIDES, DIAGONAL));
		}

		TEST_METHOD(isRectangleTesting5)
		{

			POINT points[] = { {-100, -100 }, { -90, -100 }, { -90, 100 }, { -100, 100 } };

			for (int i = 0; i < NUMBEROFSIDES; i++) {

				SIDES[i] = sideLength(points[i], points[(i + 1) % 4]);
			}

			DIAGONAL[0] = sideLength(points[0], points[2]);
			DIAGONAL[1] = sideLength(points[1], points[3]);

			Assert::IsTrue(isRectangle(SIDES, DIAGONAL));
		}

	};

};


namespace TriangFeatureTesting
{
	TEST_CLASS(TriangleAnalysisTesting)
	{
	public:

		TEST_METHOD(TriangleAnalysisTest1) //Test for equilateral triangle
		{
			analyzeTriangle(2, 2, 2, result);
			Assert::AreEqual("Equilateral triangle", result);
		}
		TEST_METHOD(TriangleAnalysisTest2) //test for Isosceles triangle (very long one)
		{
			analyzeTriangle(100000, 0.1, 100000, result);
			Assert::AreEqual("Isosceles triangle", result);
		}
		TEST_METHOD(TriangleAnalysisTest3) //test for scalene triangle
		{
			analyzeTriangle(3, 4, 5, result);
			Assert::AreEqual("Scalene triangle", result);
		}
		TEST_METHOD(TriangleAnalysisTest4) //test for bad input
		{
			analyzeTriangle(-3, 4, 5, result);
			Assert::AreEqual("Not a triangle", result);
		}
		TEST_METHOD(TriangleAnalysisTest5) //test for sides that cant make a triangle 
		{
			analyzeTriangle(1, 4, 5, result);
			Assert::AreEqual("Not a triangle", result);
		}
	};

	TEST_CLASS(TriangleAngleTesting)
	{
	public:

		TEST_METHOD(TriangleAngleTest1)
		{
			TriangleInsideAngles(1000, 1000, 1000, result); //test for equilateral
			Assert::AreEqual("This triangle's angles are 60.00, 60.00, 60.00", result);
		}
		TEST_METHOD(TriangleAngleTest2)
		{
			TriangleInsideAngles(1000000000, 1000000000, 1, result);
			Assert::AreEqual("This triangle's angles are 90.00, 90.00, 0.00", result); //test for a very long isosceles triangle
		}
		TEST_METHOD(TriangleAngleTest3)
		{
			TriangleInsideAngles(-3, 999999, 1, result); //test for when input is negative
			Assert::AreEqual("The triangle cannot be made", result);
		}
		TEST_METHOD(TriangleAngleTest4)
		{
			TriangleInsideAngles(1000, 1000, 0.1, result);
			Assert::AreEqual("This triangle's angles are 90.00, 90.00, 0.01", result); //test for decimal + big number
		}
		TEST_METHOD(TriangleAngleTest5)
		{
			TriangleInsideAngles(0, 3, 2, result);
			Assert::AreEqual("The triangle cannot be made", result); //test to see if one of the sides is 0
		}
	};
}