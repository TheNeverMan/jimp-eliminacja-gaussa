#ifndef _MAT_IO_H
#define _MAT_IO_H

#include <stdlib.h>

typedef struct _Matrix {
				size_t r,c;
				double **data;
} Matrix;

/**
 * Zwraca 0 - udalo sie wczytac
 * Zwraca 1 - podczas wczytywania wystapil blad
 */
Matrix * readFromFile(char * fname);
void printToScreen(Matrix *mat);

Matrix * createMatrix(size_t r, size_t c);
void freeMatrix(Matrix *mat);

#endif
