#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	FILE *file;
	char fileName[255] = "[FILE_PATH_WITH_EXTENSION]";
	int i = 1;
	int pos = 0;
	char line[255] = "";
	
	file = fopen(fileName,"r");
	
	if(file == NULL){
		printf("File IO Error\n");
		system("PAUSE");
		exit(1);
	}
	
	char c = fgetc(file);
	
	while(!feof(file)){
		line[pos] = c;
		
		c=fgetc(file);
		pos++;

		if(c == '\n'){
			//printf("Line %i => %s\n",i,line);
			printf(line);
			i++;

			memset(line, 0, sizeof line);
			pos=0;
		}
	}
	
	fclose(file);
	
	printf("\n\nTotal Lines => %i\n",i);
	
	system("PAUSE");
	return 0;
}
