#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

/*
 * Algorithm Challenge – Level 3 | #8 Multiply Two Matrices (Element-wise Multiplication)
 *
 * This program fills two 4x4 matrices with random numbers, then multiplies them element by element and stores the result in a third matrix.
 *
 * The main goal of this challenge is to understand how multiple matrices interact together and how data flows across corresponding positions in two-dimensional arrays.
 */

// Generates a random number within a given range
int RandNumbr(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

// Fills a matrix with random numbers
void FillMatrxWithRandNums(int arr[4][4], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++) // Traverse rows
    {
        for (short j = 0; j < Cols; j++) // Traverse columns
        {
            arr[i][j] = RandNumbr(1, 9);
        }
    }
}

// Multiplies two matrices element by element
void Multiply2Arr(int Matrix1[4][4], int Matrix2[4][4],
                  int MatrixResult[4][4], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            // Multiply corresponding elements
            MatrixResult[i][j] = Matrix1[i][j] * Matrix2[i][j];
        }
    }
}

// Prints a matrix with formatted output
void PrintMatrix(int arr[4][4], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            printf(" %0*d   ", 2, arr[i][j]);
        }
        cout << endl;
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int Matrix1[4][4], Matrix2[4][4], MatrixResult[4][4];

    FillMatrxWithRandNums(Matrix1, 4, 4);
    cout << "Matrix 1:\n";
    PrintMatrix(Matrix1, 4, 4);

    FillMatrxWithRandNums(Matrix2, 4, 4);
    cout << "\nMatrix 2:\n";
    PrintMatrix(Matrix2, 4, 4);

    Multiply2Arr(Matrix1, Matrix2, MatrixResult, 4, 4);
    cout << "\nResult Matrix:\n";
    PrintMatrix(MatrixResult, 4, 4);

    return 0;
}
