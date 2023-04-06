#include "pch.h"
#include "CppUnitTest.h"

extern "C" void analyzeTriangle(double side1, double side2, double side3, char result[]);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

char result[40];

namespace TriangleAnalysisTesting
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
			analyzeTriangle(3,4,5, result);
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
}