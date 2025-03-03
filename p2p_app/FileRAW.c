#include "FileRAW.h"

void readFile(char *fileName, char *content, int contentTam)
{
    FILE *file_;
    int bytesReaded;
    int i = 0;
    //Se procede a abrir el chunk para su consecuente lectura.
    file_ = fopen(fileName,"r");
    //Se valida que exista dicho chunk.
    if(file_ == NULL) {
        printf("El chunk no existe.\n");
    }
    for(i = 0; !feof(file_) ; i++) {
        bytesReaded = fread(content, 1, contentTam, file_);
    }
    fflush(stdout);
    // Se cierra archivo .torrent.
    fclose(file_);
}

void writeFile(char *fileName, char *content, int contentLenght)
{
    // Escribimos primero un archivo temporal de lista de Chunks del lado emisor para su posterior carga...
    FILE *tempFile;
    tempFile = fopen(fileName,"wb");
    // Inicio archivo de copia...
    fseek(tempFile, 0, SEEK_SET);
    //fprintf(tempFile, "%s", content);
    fwrite(content, 1, contentLenght, tempFile);
    fclose(tempFile);
    fflush(stdout);
}

void writeFile_(char *fileName, char *content, int contentLenght)
{
    // Escribimos primero un archivo temporal de lista de Chunks del lado emisor para su posterior carga...
    FILE *tempFile;
    tempFile = fopen(fileName,"ab");
    // Inicio archivo de copia...
    fseek(tempFile, 0, SEEK_SET);
    fprintf(tempFile, "%s\n", content);
    //fwrite(content, 1, contentLenght, tempFile);
    fclose(tempFile);
    fflush(stdout);
}

int getFileSize(char *fileName)
{
    FILE *file_;
    int bytesReaded;
    int i = 0;
    //Se procede a abrir el chunk para su consecuente lectura.
    file_ = fopen(fileName,"r");
    //Se valida que exista dicho chunk.
    if(file_ == NULL) {
        printf("El chunk no existe.\n");
    }
    fseek(file_, 0, SEEK_END);
    return ftell(file_);
}

