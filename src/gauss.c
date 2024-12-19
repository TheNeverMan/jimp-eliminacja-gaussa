#include "gauss.h"
#include <math.h>
#include <stdlib.h>

static size_t findRowWithBiggestElementInColumn(Matrix* mat, size_t upperRowConstraint, size_t column)
{
    size_t resultRow = upperRowConstraint;

    for (size_t i = mat->r; i-- > upperRowConstraint;) 
    {
        if (fabs(mat->data[i][column]) > fabs(mat->data[resultRow][column])) 
        {
            resultRow = i;
        }
    }

    return resultRow;
}

static void swapRows(Matrix* mat, size_t origRowIndex, size_t swappedRowIndex)
{
	if(((mat->r <= swappedRowIndex) || (mat->r <= origRowIndex)) || (origRowIndex == swappedRowIndex))
		return;
	double* tmpRow = mat->data[origRowIndex];
	mat->data[origRowIndex] = mat->data[swappedRowIndex];
	mat->data[swappedRowIndex] = tmpRow;
}

static void multiplyRow(Matrix* mat, size_t row, double value)
{
	size_t index = mat->c;
	if(mat->r <= row)
		return;
	while(index --> 0)
		mat->data[row][index] *= value;
}

static void substractRows(Matrix* mat, size_t rowOrig, size_t rowModified)
{
	size_t index = mat->c;
	if((mat->r <= rowOrig) || (mat->r <= rowModified))
		return;
	while(index --> 0)
		mat->data[rowModified][index] -= mat->data[rowOrig][index];

}

static double getMultiplicationFactor(double value, double outcome)
{
	return outcome/value;
}

static double sumRow(Matrix* mat, size_t row)
{
	double out = 0.0;
	size_t index = mat->c;
	if(mat->r <= row)
		return out;
	while(index --> 0)
		out += mat->data[row][index];
	return out;
}

static double sumColumn(Matrix* mat, size_t column)
{
	double out = 0.0;
	size_t index = mat->r;
	if(mat->c <= column)
		return out;
	while(index --> 0)
		out += mat->data[index][column];
	return out;
}

static int isMatrixOsobliwy(Matrix* mat)
{
	size_t rowIndex = mat->r;
	size_t columnIndex = mat->c;
	while(rowIndex --> 0)
		if(!(int)sumRow(mat,rowIndex))
			return 1;
	while(columnIndex --> 0)
		if(!(int)sumColumn(mat,columnIndex))
			return 1;
	return 0;
}

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b)
{
	int rowIndex = 0;
	int columnIndex = 0;
	while((rowIndex < mat->r) && (columnIndex < mat->c))
	{
		int substractedRowIndex = rowIndex+1;
		size_t rowWithBiggestElementInColumn = findRowWithBiggestElementInColumn(mat,rowIndex,columnIndex);
		swapRows(mat,rowIndex,rowWithBiggestElementInColumn);
		swapRows(b,rowIndex,rowWithBiggestElementInColumn);
		double substractedElement = mat->data[rowIndex][columnIndex];
		while(substractedRowIndex < mat->r)
		{
			double multiplicationFactor = getMultiplicationFactor(mat->data[substractedRowIndex][columnIndex],substractedElement);
			multiplyRow(mat, substractedRowIndex, multiplicationFactor);
			multiplyRow(b, substractedRowIndex, multiplicationFactor);
			substractRows(mat, rowIndex, substractedRowIndex);
			substractRows(b, rowIndex, substractedRowIndex);
			substractedRowIndex++;
		}
		rowIndex++;
		columnIndex++;
	}
	if(isMatrixOsobliwy(mat))
		return 1;
	return 0;
}