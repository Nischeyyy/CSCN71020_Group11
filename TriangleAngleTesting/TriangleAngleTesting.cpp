#include "pch.h"
#include "CppUnitTest.h"

extern "C" void TriangleInsideAngles(double a, double b, double c, char result[]);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

char result[60];

namespace TriangleAngleTesting
{
	TEST_CLASS(TriangleAngleTesting)
	{
	public:
		
		TEST_METHOD(TriangleAngleTest1)
		{
			TriangleInsideAngles(1000, 1000, 1000, result); //test for equilateral
			Assert::AreEqual("This triangle's angles are 60.00, 60.00, 60.00",result);
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
