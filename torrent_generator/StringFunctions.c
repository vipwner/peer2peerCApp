/**
 * StringFunctions.c
 * @date
 * @author Alvaro Jose Lobaton Restrepo - 1130054
 * @author Jhon Jairo Pantoja - 1125572
 */
// CUSTOM LIBRARIES
#include "StringFunctions.h"

char *substr(char *string, int start, int length)
{
    if (length == 0) length = strlen(string) - start;
    char *result = (char *)malloc(sizeof(char) * (length + 1)); // +1 for '\0'
    if (!result) {
        perror("Memory allocation failed in substr");
        exit(EXIT_FAILURE);
    }
    strncpy(result, string + start, length);
    result[length] = '\0'; // Ensure null-termination
    return result;
}

char *substr_(char string[], int start, int length)
{
    if (length == 0) length = strlen(string) - start;
    char *result = (char *)malloc(sizeof(char) * (length + 1)); // +1 for '\0'
    if (!result) {
        perror("Memory allocation failed in substr_");
        exit(EXIT_FAILURE);
    }
    strncpy(result, string + start, length);
    result[length] = '\0'; // Ensure null-termination
    return result;
}

char *concat(const char *char1, const char *char2)
{
    int length = strlen(char1) + strlen(char2) + 1;
    char *result = (char *)malloc(sizeof(char) * length);

    if (result == NULL) {
        perror("Failed to allocate memory for concat");
        exit(EXIT_FAILURE);
    }

    snprintf(result, length, "%s%s", char1, char2);
    //printf("Concatenacion: %s \n", result);
    return result;
}

char *concat_(char *char1, char char2)
{
    char temp[2];
    temp[0] = char2;
    temp[1] = '\0';
    return concat(char1, (const char *)temp);
}

void toString(int a, char *copychar)
{
    sprintf(copychar, "%d", a);
}

