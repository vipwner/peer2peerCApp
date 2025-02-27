// CUSTOM LIBRARIES
 #include "SHACalculator.h"
 #include "StringFunctions.h"
 #include "AddressGetter.h"

/**
 *
 */
void calculateSHA(char* fileName, char *SHACopy)
{   	
    int MAX_BUFFER_TAM = 9999;
	char* comand = "openssl sha1 ";
	const char* finalComand = concat(comand, fileName);
	printf("Comando: %s\n", finalComand);
    FILE *inputFile;   
    char outputBuffer[MAX_BUFFER_TAM];
    extern FILE *popen();
    inputFile = popen(finalComand, "r"); // Inicializamos el archivo de entrada.
    fgets(outputBuffer, sizeof(outputBuffer), inputFile); // Obtenemos el resultado del comando openssl.  
    pclose(inputFile); // Cerramos el archivo.  
    // Buscamos el primer caracter igual a ' ' 
	int n = getPosOf(' ', outputBuffer);
    int i = 0;
    for(i; i < 40; i++){
        SHACopy[i] = outputBuffer[n + 1 + i];
    }
    SHACopy[40] = '\0';
    printf("SHA Al interior de calculateSHA(): %s\n", SHACopy);
    printf("Resultado del comando: %s", outputBuffer); // Imprimimos por consola el resultado del comando. 
    //printf("Resultado: %s", sha_); 
}
