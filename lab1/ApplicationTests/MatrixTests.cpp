#include "stdafx.h"
#include "../matrix33/matrix33.h"

BOOST_AUTO_TEST_SUITE(MatrixTests)

	BOOST_AUTO_TEST_CASE(Determinant)
	{
		matrix33 matrix = {
			matrix3{{1, 2, 3}},
			matrix3{{4, -3, 8}},
			matrix3{{19, -9, 0}}
		};
		BOOST_CHECK_EQUAL(Det(matrix), 439);

		matrix33 onesMatrix = {
			matrix3{ { 1, 0, 0 } },
			matrix3{ { 0, 1, 0 } },
			matrix3{ { 0, 0, 1 } }
		};
		BOOST_CHECK_EQUAL(Det(onesMatrix), 1);
	}

	BOOST_AUTO_TEST_CASE(MultiplierFind)
	{
		BOOST_CHECK_EQUAL(FindMultiplier(0, 0), 1);
		BOOST_CHECK_EQUAL(FindMultiplier(1, 0), -1);
		BOOST_CHECK_EQUAL(FindMultiplier(0, 1), -1);
		BOOST_CHECK_EQUAL(FindMultiplier(1, 1), 1);
		BOOST_CHECK_EQUAL(FindMultiplier(3, 6), -1);
		BOOST_CHECK_EQUAL(FindMultiplier(1, 3), 1);
	}

	BOOST_AUTO_TEST_CASE(MinorFind)
	{
		matrix33 matrix = {
			matrix3{ { 2, 4, 3 } },
			matrix3{ { 7, -6, 1 } },
			matrix3{ { 1, 5, 4 } }
		};

		BOOST_CHECK_EQUAL(FindMinorDet(matrix, 0, 0), -29);
		BOOST_CHECK_EQUAL(FindMinorDet(matrix, 2, 2), -40);
		BOOST_CHECK_EQUAL(FindMinorDet(matrix, 1, 1), 5);
		BOOST_CHECK_EQUAL(FindMinorDet(matrix, 0, 2), 41);
	}

	BOOST_AUTO_TEST_CASE(InverseMatrixTest)
	{
		matrix33 matrix = {
			matrix3{ { 2, 4, 3 } },
			matrix3{ { 7, -6, 1 } },
			matrix3{ { 1, 5, 4 } }
		};

		matrix33 expected = {
			matrix3{ { 29.0 /43.0, 1.0 /43.0, -22.0 /43.0 } },
			matrix3{ { 27.0 /43.0, -5.0 /43.0, -19.0 /43.0 } },
			matrix3{ { -41.0/43.0, 6.0 /43.0, 40.0 /43.0 } }
		};

		matrix33 result = InverseMatrix(matrix);

		BOOST_CHECK_EQUAL_COLLECTIONS(result[0].begin(), result[0].end(),
			expected[0].begin(), expected[0].end());

		BOOST_CHECK_EQUAL_COLLECTIONS(result[1].begin(), result[1].end(),
			expected[1].begin(), expected[1].end());

		BOOST_CHECK_EQUAL_COLLECTIONS(result[2].begin(), result[2].end(),
			expected[2].begin(), expected[2].end());

	}

BOOST_AUTO_TEST_SUITE_END()