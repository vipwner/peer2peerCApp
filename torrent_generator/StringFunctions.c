/**
 * StringFunctions.c
 * @date
 * @author Alvaro Jose Lobaton Restrepo - 1130054
 * @author Jhon Jairo Pantoja - 1125572 
 */
// CUSTOM LIBRARIES
#include "StringFunctions.h"

char* substr(char* string, int start, int length)
{
    if (length == 0) length = strlen(string)-start;
    char *result = (char*)malloc(sizeof(char) * length);
    strncpy(result, string + start, length);
    return result;
}

char* substr_(char string[], int start, int length)
{
    if (length == 0) length = strlen(string)-start;
    char *result = (char*)malloc(sizeof(char) * length);
    strncpy(result, string + start, length);
    return result;

}

char* concat(char* char1, char* char2)
{
	int length;
	length = strlen(char1);
	char *result = (char*)malloc(sizeof(char) * length);
	strcpy(result, char1);
	strcat(result, char2);	
	//printf("Concatenacion: %s \n", result);
	return result;
}

char* concat_(char* char1, char char2)
{
	// METODO I
	char temp[2]; 
	temp[0] = char2; 
	temp[1] = '\0'; 
	return concat(char1, temp);
}

void toString(int a, char *copychar)
{
    sprintf(copychar, "%d", a);   
}

