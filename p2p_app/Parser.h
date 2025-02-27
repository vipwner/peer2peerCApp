#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StringFunctions.h"

/**
 * Parser Parser.h
 * 
 * @date 02/01/2015
 * @author Álvaro Jose Lobaton Restrepo. Codigo: 1130054
 * @author Jhon Jairo Pantoja. Codigo: 1125572
 * @author Leydi Joanna Carvajal Henao. Codigo:1125189
 */

/**
 * [validateGET Metodo encargado de validar el comando GET]
 * @param  command [char* 	Correspondiente al comando.]
 * @return         [int 	Correspondiente a la validacion.]
 */		
int validateGET(char* command);
/**
 * [validateHAS Metodo encargado de validar el comando HAS]
 * @param  command [char* 	Correspondiente al comando.]
 * @return         [int 	Correspondiente a la validacion.]
 */
int validateHAS(char* command);
/**
 * [validateSENDME Metodo encargado de validar el comando SENDME]
 * @param  command [char* 	Correspondiente al comando.]
 * @return         [int 	Correspondiente a la validacion.]
 */
int validateSENDME(char* command);
/**
 * [validateEXIT Metodo encargado de validar el comando EXIT]
 * @param  command [char* 	Correspondiente al comando.]
 * @return         [int 	Correspondiente a la validacion.]
 */
int validateEXIT(char* command);

#endif