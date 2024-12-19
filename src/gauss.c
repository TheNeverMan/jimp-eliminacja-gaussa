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

int eliminate(Matrix *mat, Matrix *b)
{
	return 0;
}
