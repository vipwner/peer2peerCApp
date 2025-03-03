#include "ChunkFunctions.h"

void fileRebuilding(char *nameFileWe, int chunksNumber)
{
    FILE *fileRebuilded;
    fileRebuilded = fopen(nameFileWe, "wb");
    //fseek(fileRebuilded, 0, SEEK_SET);
    if(fileRebuilded == NULL) {
        printf("El archivo o directorio no existe.\n");
        return;
    }
    char buf[524288];
    int i = 0;
    for( i = 0; i < chunksNumber; i++) {
        char chunkName[100];
        sprintf(chunkName, "%s_%d", nameFileWe, i);


        FILE *chunkFile;
        chunkFile = fopen(chunkName,"r");
        if( chunkFile == NULL) {
            printf("El archivo o directorio no existe.\n");
            return; // Terminamos la ejecucion del programa.
        }
        fseek(chunkFile, 0, SEEK_SET);
        int j = 0;
        for(j = 0; !feof(chunkFile) ; j++) {
            fflush( stdin );
            int bytesReaded = fread(buf, 1, 524288, chunkFile);
            if(bytesReaded < 0) {

            }
            fwrite(buf, 1, bytesReaded, fileRebuilded);
            fseek(fileRebuilded, 0, SEEK_END);
        }
        fclose(chunkFile);
        memset(buf, 0, 524288);
    }
    fclose(fileRebuilded);
    fflush(stdout);
}

int getIDChunk(char *id, char *SHA)
{
    // A esta altura el archivo temporal es creado para su lectura...
    FILE *tempFile_;
    tempFile_ = fopen("ChunkList.txt","r");
    if(tempFile_ == NULL) {
        printf("El archivo no existe.\n");
        return -1;
    }
    int i = 0;
    int chunkCount = 0;
    size_t buffer_size = 100; // Tamaño de la linea
    char *buffer = malloc(buffer_size * sizeof(
                              char)); // Buffer que almacenara la linea en cada iteracion
    int line_number = 0;
    while(-1 != getline(&buffer, &buffer_size, tempFile_)) {
        printf("%d: %s", ++line_number, buffer);
        // Definiciones temporales
        int flag_count = 0;
        //Chunk tempChunk;
        char *idCh = "";
        char *sha = "";
        // Recorremos la linea asi:
        for(i = 0 ; i < buffer_size; i++) {
            if(buffer[i] == '\n') {
                break;
            } else if(buffer[i] == '\t') {
                flag_count++;
            } else {
                if(flag_count == 0) {
                    idCh = concat_(idCh, (char)buffer[i]);
                }
                if(flag_count == 1) {
                    sha = concat_(sha, (char)buffer[i]);
                }
            }
        }
        if(!strncmp(sha, SHA, 40)) {
            strcpy(id, idCh);
            return 0;
        }
    }
    fflush(stdout);
    fclose(tempFile_);
    free(buffer);
    perror("No tenemos ese chunk. Error ");
    return -1;
}
