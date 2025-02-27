#include "TorrentLoader.h"

int loadTorrent(char* torrentFileName, Chunk *chunks)
{
	FILE *torrentFile;
	//Se procede a abrir el torrent para su consecuente lectura.
	torrentFile = fopen(torrentFileName,"r");
	int i = 0;
	int j = 0;
	//Se valida que exista dicho torrent.
	if(torrentFile == NULL){
		printf("El archivo no existe.\n");
		return -1;
	}
	//size_t buffer_size = 100; // Tamaño de la linea
    //char *buffer = malloc(buffer_size * sizeof(char)); // Buffer que almacenara la linea en cada iteracion
	char buffer[200];
    int line_number = 0;
    while(fgets(buffer, sizeof(buffer), torrentFile) != NULL)
    //while(-1 != getline(&buffer, &buffer_size, torrentFile))
    {
        //printf("%d: %s", ++line_number, buffer);
        ++line_number;
        int len = strlen(buffer);
        //printf("%d\n", len);
        // Omitimos las 2 primeras lineas...
        if(line_number > 2){               	
	        // Definiciones temporales
	        int flag_count = 0;         
	       	Chunk tempChunk;
	        char* idCh = "";
	        char* sha = "";
	        // Recorremos la linea asi:
	        for(i = 0 ; i < strlen(buffer); i++){
	            if(buffer[i] == '\n'){ 
	                break;
	            }else if(buffer[i] == '\t'){
	            	flag_count++;
	            }
	            else{
	                if(flag_count == 0){
	                    idCh = concat_(idCh, (char)buffer[i]);
	                }
	                if(flag_count == 1){
	                    sha = concat_(sha, (char)buffer[i]);
	                }
	            }
	        }
	        tempChunk.idChunk = idCh;
	        tempChunk.SHA = sha;
	        // Agregamos al contenedor...
	        *chunks++ = tempChunk;
			//printf("%d: %s\t%s\n", line_number, chunks[j].idChunk, chunks[j].SHA);
	        j++;      
        }   
    }
	fflush(stdout);
	// Se cierra archivo .torrent.
	fclose(torrentFile);
	//free(buffer);
	return j;
}
