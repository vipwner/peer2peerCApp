#include "NodesLoader.h"

int loadNodes(Node *nodesContainer){
	//Definitions.
    FILE *nodesFile;
	//Node nodesCont[999];
	char* nodesFileName = "Nodes.txt";
	nodesFile = fopen(nodesFileName,"r");
	int i = 0;
	int j = 0;
	// Si el archivo no existe...
    if(nodesFile == NULL){
        printf("El archivo o directorio no existe.\n");
        return - 1; // Terminamos la ejecucion del programa.
    }
    size_t buffer_size = 100; // Tamaño de la linea
    char *buffer = malloc(buffer_size * sizeof(char)); // Buffer que almacenara la linea en cada iteracion
    int line_number = 0;
    while(-1 != getline(&buffer, &buffer_size, nodesFile))
    {
        printf("%d: %s", ++line_number, buffer);
        // Definiciones temporales
        int flag_count = 0;     
        Node tempNode;
        char* id = "";
        char* ip = "";
        char* port = "";
        // Recorremos la linea asi:
        for(i = 0; i < buffer_size; i++){
            if(buffer[i] == '\t'){
                flag_count++;
            }else if(buffer[i] == '\n'){
            	//puts("Paso por linea 32.");
                break; // Detenemos el cilo.
            }
            else{
                if(flag_count == 0){
                    id = concat_(id, (char)buffer[i]);
                }
                if(flag_count == 1){
                    ip = concat_(ip, (char)buffer[i]);
                }
                if(flag_count == 2){
                    port = concat_(port, (char)buffer[i]);
                }
            }
        }
        //printf("%s\n", id);
        //printf("%s\n", ip);
        //printf("%s\n", port);
        tempNode.idNode = id;
        tempNode.ipNode = ip;
        tempNode.portNode = port;
        // Agregamos al contenedor...
        *nodesContainer++ = tempNode;
        j++;                
    }
	fflush(stdout);
	// Se cierra archivo de nodos.
	fclose(nodesFile);
	free(buffer);
    return j;
}


int setChunksNode(char* content, int contentLenght, Chunk *chunks)
{
    // Escribimos primero un archivo temporal de lista de Chunks del lado emisor para su posterior carga...
    FILE *tempFile;
    tempFile = fopen("ChunkList_temp.txt","wb");
    // Inicio archivo de copia...
    fseek(tempFile, 0, SEEK_SET);
    //fprintf(tempFile, "%s", content);
    fwrite(content, 1, contentLenght, tempFile);
    fclose(tempFile);
    // A esta altura el archivo temporal es creado para su lectura...
    FILE *tempFile_;
    tempFile_ = fopen("ChunkList_temp.txt","r");
    if(tempFile_ == NULL){
        printf("El archivo no existe.\n");
        return -1;
    }
    int i = 0;
    int chunkCount = 0;
    size_t buffer_size = 100; // Tamaño de la linea
    char *buffer = malloc(buffer_size * sizeof(char)); // Buffer que almacenara la linea en cada iteracion
    int line_number = 0;
    while(-1 != getline(&buffer, &buffer_size, tempFile_))
    {
        printf("%d: %s", ++line_number, buffer);
        // Definiciones temporales
        int flag_count = 0;         
        Chunk tempChunk;
        char* idCh = "";
        char* sha = "";
        // Recorremos la linea asi:
        for(i = 0 ; i < buffer_size; i++){
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
        *chunks++ = tempChunk;
        chunkCount++; 
    }
    fflush(stdout);
    fclose(tempFile_);
    free(buffer);
    // Borramos el archivo...
    remove("ChunkList_temp.txt");
    return chunkCount;
}

