#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void my_perror(const char* str){


	
	perror(str);




}

void main (int argc, char *argv[])
{
	FILE *fp;

	if (argc < 2) {
		printf("Usage : strerror_show nofilename \n");
		my_perror(NULL);
		exit(1);
	}

	if ( (fp = fopen(argv[1], "r")) == NULL) {
		printf("Cannot open a file %s... (error message : %s \n", argv[1], argv[1]);
		my_perror("fopen");
		exit(1);

	}
	printf("open a file %s. \n", argv[1]);

	fclose(fp);
}


