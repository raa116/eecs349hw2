#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int exists(char *fname) {
	FILE *file;
	if (file = fopen(fname, "r")) {
		fclose(file);
		return 1;
	}
	return 0;
}

void errorcheck(FILE *fptr) {
	if(fptr == NULL) {
   		printf("Error!");   
    	exit(1);             
   }
}

int main() {
	FILE *fptr;
	char c[1000];
	char pefile[33] = "I want to learn PE file format.\n";
	char fname[9] = "PE-1.txt";
	if (exists(fname)) {
		fptr = fopen(fname, "r+");
		errorcheck(fptr);
   		while (fgets(c, 512, fptr) != NULL) {
   			if (strncmp(c, pefile, 32)) {
   				fclose(fptr);
   				return 0;
		   }
		}
		fprintf(fptr, pefile);
		fclose(fptr);
		return 0;
   }

   fptr = fopen(fname, "w");
   errorcheck(fptr);
   fprintf(fptr, "%s\n", pefile);
   fclose(fptr);
   return 0;
}
