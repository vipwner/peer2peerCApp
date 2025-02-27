#include "RarestChunkFirst.h"

int getRarestChunkFirst(char *rarestSHA, Chunk *torrentChunks, int chunkNumber, Node *nodes, int nodeNumber){
	int rarestChunkDet[chunkNumber];	
    int posArr[chunkNumber];	
	int i = 0;
	int j = 0;
	int m = 0;
	for (i = 0; i < chunkNumber; i++)
    {
        if(torrentChunks[i].status == 1){
        	// Limpiamos caracteres espuria...    	
    		(torrentChunks[i].SHA)[40] = '\0';
        	//printf("%d. raresChunkFirst(): %s\n", i, torrentChunks[i].SHA);
        	int coincidence = 0;
            for (j = 0; j < nodeNumber; j++)
            {
                for(m = 0; m < nodes[j].chunksQ; m++)
                {
                    if(!strncmp(nodes[j].chunks[m].SHA, torrentChunks[i].SHA, 40)) {
                        coincidence++;                    
                    }
                }
            }        
            if(coincidence > 0){
                //printf("Coincidencia %d: %d, %s\n", i, coincidence, torrentChunks[i].SHA);
                rarestChunkDet[i] = coincidence;
                posArr[i] = i;
            }else{
            	perror("No se puede descargar el archivo por que nadie lo tiene completo.");
            	return -1;
            }  
        }else if(torrentChunks[i].status == 0){
            rarestChunkDet[i] = -1;
            posArr[i] = i;
        }     
    }
    puts("Paso por linea 35 RarestChunkFirst");
    int posOfRarestChunk = getMinPosOf(rarestChunkDet, posArr, chunkNumber);
    puts("Paso por linea 37 RarestChunkFirst");
    if(posOfRarestChunk == -2){
        return posOfRarestChunk;
    }
    strcpy(rarestSHA, torrentChunks[posOfRarestChunk].SHA);
    puts("Paso por la linea 42 RarestChunkFirst");
    return posOfRarestChunk;
}

int getMinPosOf(int *array, int *posArr, int len)
{
	int i, j, x;
    int aux_a, aux_p;
    for (i = 0; i < len -1 ; i++) {
        for (j = i + 1; j < len ; j++) {
            if (array[i] > array[j]) {
                aux_a = array[i];
                aux_p = posArr[i];

                array[i] = array[j];
                posArr[i] = posArr[j];

                array[j] = aux_a;
                posArr[j] = aux_p;
            }
        }
    }

    for(x = 0; x < len; x++){
        printf("%d, %d\n", posArr[x], array[x]);
        if(array[x] > 0){
            printf("Resultado getMinPosOf(): %d\n", posArr[x]);
            return posArr[x];
        }
    }    
    return -2;

}


int searchNode(char *id, char *ip, char *port, Node *nodes, int nodeNumber, char *rarestSHA)
{
    Node possessorsNodes[100];
    int possessorsLen = 0;
    int j = 0;
    int m = 0;
    for (j = 0; j < nodeNumber; j++)
    {
        for(m = 0; m < nodes[j].chunksQ; m++)
        {
            if(!strncmp(nodes[j].chunks[m].SHA, rarestSHA, 40)) {
                // Si lo tiene entonces agrega al contenedor de nodos poseedores...
                //sprintf(nodeToCon->idNode, "%s", nodes[j].idNode);
                //strcpy(nodeToCon->idNode, nodes[j].idNode);
                //nodeToCon->ipNode = temp_ip;
                //nodeToCon->portNode = temp_port;
                //strcpy(id, nodes[j].idNode);
                //strcpy(ip, nodes[j].ipNode);
                //strcpy(port, nodes[j].portNode);
                //return 0;
                possessorsNodes[j] = nodes[j];
                possessorsLen++;
                break;
            }
        }
    }
    // Obtenemos el nodo al cual pediremos el chunk por medio de un rand.
    
    int random_ = rand() % possessorsLen;
    printf("NUMERO ALEATORIO: %d\n", random_);
    strcpy(id, possessorsNodes[random_].idNode);
    strcpy(ip, possessorsNodes[random_].ipNode);
    strcpy(port, possessorsNodes[random_].portNode);
    puts("PASO POR LINEA 114.");
    return 0;
}
