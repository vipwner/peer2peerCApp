#ifndef SHACALCULATOR_H_INCLUDED
#define SHACALCULATOR_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * SHACalculator SHACalculator.h
 *
 * @date 20/12/2014
 * @author Álvaro Jose Lobaton Restrepo. Codigo: 1130054
 * @author Jhon Jairo Pantoja. Codigo: 1125572
 * @author Leydi Joanna Carvajal Henao. Codigo:1125189
 */
/**
 * [calculateSHA Metodo que obtiene el SHA de una archivo.]
 * @param fileName [Nombre del archivo.]
 * @param SHACopy  [Copia del SHA a ser obtenido.]
 */
void calculateSHA(char* fileName, char *SHACopy);

#endif