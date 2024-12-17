#ifndef _GAUSS_H
#define _GAUSS_H

#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include <math.h>
#include "mat_io.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
 /* this function modifies mat and n */
int eliminate(Matrix *mat, Matrix *b);

#endif
