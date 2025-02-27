#ifndef STRINGFUNCTIONS_H_INCLUDED
#define STRINGFUNCTIONS_H_INCLUDED
// C 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/**
 * StringFunctions StringFunctions.h
 * 
 * @date 02/01/2015
 * @author Álvaro Jose Lobaton Restrepo. Codigo: 1130054
 * @author Jhon Jairo Pantoja. Codigo: 1125572
 * @author Leydi Joanna Carvajal Henao. Codigo:1125189
 */

/**
 * Estructura String.
 */
typedef struct 
{
	char* string;
}String;

/**
 * substr Metodo encargado de retornar una subcadena de una cadena.
 * @param string Un char* correspondiente a la cadena de la cual se desea obtener la subcadena.
 * @param start Un int correspondiente al inicio de la subcadena.
 * @param length Un int correspondiente a la logitud de la subcadena a partir del inicio. Si es 0, se toma hasta el final de la cadena original.
 * @return Un char* correspondiente a la subcadena.
 */
char* substr(char* string, int start, int length);

/**
 * [substr_ Metodo encargado de retornar una subcadena de una cadena.]
 * @param string 	[Un char[] correspondiente a la cadena de la cual se desea obtener la subcadena.]
 * @param start 	[Un int correspondiente al inicio de la subcadena.]
 * @param length 	[Un int correspondiente a la logitud de la subcadena a partir del inicio. Si es 0, se toma hasta el final de la cadena original.]
 * @return char* 	[Un char* correspondiente a la subcadena.]
 */
char* substr_(char string[], int start, int length);
/**
 * [concat Metodos encargado de concatenar dos cadenas de caracteres.]
 * @param  char1 [Cadena de caracteres.]
 * @param  char2 [Cadena de caracteres.]
 * @return char* [Cadena concatenada.]
 */
char* concat(char* char1, char* char2);
/**
 * [concat Metodo encargado de concatenar una cadena de caract. con un caracter.]
 * @param  char1 [Cadena de caracteres.]
 * @param  char2 [Caracter]
 * @return char* [Cadena concatenada.]
 */
char* concat_(char* char1, char char2);
/**
 * [toString Metodo encargado de convertir un int a string]
 * @param  a [Corresponde al entero.]
 */
void toString(int a, char *copychar);

#endif