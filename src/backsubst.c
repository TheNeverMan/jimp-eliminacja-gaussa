#include "backsubst.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) 
{
	if (mat->r != mat->c || mat->r != b->r || b->c != 1 || x->r != mat->c || x->c != 1)
	{
        fprintf(stderr, "Nieprawidłowe rozmiary macierzy\n");
        return 2; 
    }

    int n = mat->r;

    for (int i = 0; i < n; i++) 
	{
        x->data[i][0] = 0.0;
    }

    for (int i = n - 1; i >= 0; i--)
	{
        if (mat->data[i][i] == 0.0) 
		{
            fprintf(stderr, "Dzielenie przez 0\n");
            return 1;
        }

        x->data[i][0] = b->data[i][0];
        for (int j = i + 1; j < n; j++) 
		{
            x->data[i][0] -= mat->data[i][j] * x->data[j][0];
        }
        x->data[i][0] /= mat->data[i][i];
    }

    return 0;
}


