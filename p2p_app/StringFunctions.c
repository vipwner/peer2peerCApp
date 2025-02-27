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
	// METODO II
	//int originalLen = strlen(char1);
	//char1[originalLen] = char2;
	//char1[originalLen + 1] = '\0';
	//return char1;
	// METODO III	
	//char temp[2]; 
	//snprintf(temp, 2, "%c", char2);
	//printf("%s", temp);
	//int length;
	//length = strlen(char1);
	//char *result = (char*)malloc(sizeof(char) * length);
	//char *result = (char *) calloc (length, sizeof(char));
	//sprintf(result, "%s%s", char1, temp);
	//return result;
	// METODO IV	
	//char *temp = &char2;
	//int length;
	//length = strlen(char1);
	//char *result = (char*)malloc(sizeof(char) * length);
	//strcpy(result, char1);
	//strcat(result, temp);
	//return result;

}

void toString(int a, char *copychar)
{
    sprintf(copychar, "%d", a);   
}

