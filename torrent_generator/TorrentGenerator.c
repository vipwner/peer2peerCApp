// CUSTOM LIBRARIES
#include "TorrentGenerator.h"
#include "SHACalculator.h"
#include "AddressGetter.h"
#include "StringFunctions.h"

int generateTorrent(char *fileName)
{
    // Definiciones...
    int CHUNK_TAM = 512*1024;
    int MAX_BUF_TAM = 100;
    int MAX_CONTAINER_NUM = 99;

    FILE *originalFile;
    FILE *copyFile;
    FILE *torrentFile;

    char buffer[CHUNK_TAM];

    char name_[MAX_BUF_TAM];
    int path_len = strlen(fileName);
    getName(fileName,  path_len, name_);
    printf("NOMBRE DEL ARCHIVO: %s, TAM: %d\n", fileName, path_len);
    // CREAMOS Y ABRIMOS LOS ARCHIVOS.
    fflush( stdin );
    originalFile = fopen(fileName, "r");   
    if(originalFile == NULL){
        printf("El archivo o directorio no existe.\n");
        return -1;
    } 
    // Archivo de copia...
    char copyFileName[MAX_BUF_TAM];
    sprintf(copyFileName, "%s_COPY", name_);
    fflush( stdin );
    copyFile = fopen(copyFileName,"wb");
    // Archivo de Chunks (.torrent)
    char torrentFileName[MAX_BUF_TAM];
    sprintf(torrentFileName, "%s.torrent", name_);
    fflush( stdin );
    torrentFile = fopen(torrentFileName,"w+b");
    // Me posiciono al final del archivo.
    fseek(originalFile,0,SEEK_END);
    // Calculo el tamano en bytes.
    int fileSize = ftell(originalFile);
    // Mostrar el tamano del archivo.
    printf("Tamano archivo: %d\n",fileSize);
    //Numero de chunks en que se dividira.
    int chunks_can = (fileSize / CHUNK_TAM) + 1;
    printf("Numero de chunks: %d\n", chunks_can);
    // Al inicio del archivo...
    fseek(originalFile,0,SEEK_SET);
    // Inicio archivo de copia...
    fseek(copyFile, 0, SEEK_SET);
    // Inicio del archivo .torrent
    fseek(torrentFile, 0, SEEK_SET);
    // Si el archivo original no existe...    
    //Escribo el nombre del archivo original en el archivo que contiene los chunks
    fprintf(torrentFile,"File: %s\nChunks:\n",fileName);
    // Inicio del ciclo para crear los chunks...   
    int i = 0;  
	for(i; !feof(originalFile) ; i++){
        // Definiciones temprales...
        char temp_id[MAX_BUF_TAM];
        sprintf(temp_id, "%s_%d", name_, i);
        int len_chunk_name = strlen(temp_id);
		printf("Nombre temporal del chunk: %s, tam: %d\n", temp_id, len_chunk_name);
		Chunk tempChunk;		
		strcpy(tempChunk.idChunk, temp_id);
        fflush( stdin );
        // Va creando los Chunks o particiones del archivo, empezando desde 0.  
        FILE *fileChunk;     
        fileChunk = fopen(tempChunk.idChunk, "w+b"); // Creamos el chunk. 
        fseek(fileChunk,0,SEEK_SET);
        //printf("%s\n", chunkFileName);
        // Si el chunk no pudo ser creado...
        if(fileChunk == NULL){
            printf("El chunk no puede ser creado.\n");
            fclose(fileChunk);
            return -1;
        } 
        // Lee de a 512 KB del archivo original, en binario.
        int bytesReaded = fread(buffer, 1, CHUNK_TAM, originalFile);
        if(bytesReaded == -1){
            perror("Error al leer archivo.");
            return -1;
        }
        // Escribe cada chunk.
        fwrite(buffer ,1, bytesReaded, fileChunk);
        // Escribe el archivo que sera la copia del archivo original.
        fwrite(buffer, 1, bytesReaded, copyFile);
        // Cerramos el archivo del Chunk.
        fclose(fileChunk);
        // Si la creacion del Chunk fue exitosa entonces calculamos su SHA y lo asignamos a la variable de la estructura Chunk.        
        char tempSHA[40];
        calculateSHA(tempChunk.idChunk, tempSHA);
        strcpy(tempChunk.SHA, tempSHA);
        printf("SHA en generateTorrent(): %s\n", tempSHA );
        //printf("%s %s", temp_id, fileManagerInstance->chunksCont[i].SHA);        
        //Se escribe el id y sha de cada chunk del archivo .torrent
        fprintf(torrentFile,"%s\t%s\n", tempChunk.idChunk, tempChunk.SHA);
    }
	// Se cierran los archivos, original, copia y torrent.
	fclose(originalFile);
	fclose(copyFile);
    fclose(torrentFile);
	return 0;
}

