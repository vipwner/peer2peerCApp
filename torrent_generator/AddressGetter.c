#include "AddressGetter.h"
#include "StringFunctions.h"


void getName(char *path, int path_len, char *copy_p)
{			
	int n = getPosOf('.', path);
	strncpy(copy_p, path + 0, n);
	copy_p[n] = '\0';
}

int getPosOf(char a, char *string)
{	
	int n = 0;
	while(string[n] != '\0')
	{
		if(string[n] == a){
			break;	    
		}
		n++;
	}
	return n;
}