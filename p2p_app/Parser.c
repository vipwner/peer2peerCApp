#include "Parser.h"
// 0 Verdarero
// 1 Falso

int validateGET(char *command)
{
    return !strncmp(command, "GET ", 4);
}

int validateHAS(char *command)
{
    return !strncmp(command, "HAS ", 4);
}

int validateSENDME(char *command)
{
    return !strncmp(command, "SENDME ", 7);
}

int validateEXIT(char *command)
{
    return !strncmp(command, "exit", 4);
}