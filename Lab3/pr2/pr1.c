#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

main(int argc, char *argv[])
{
	FILE *src;
	FILE *dst;
	char ch;
	int count = 0;

	if(argc < 3){
		printf("Usage: file_copy");
		exit(1);
	}

	if((src = fopen(argv[1], "r")) == NULL) {
		perror("fopen: src");
		exit(1);
	}

	if((dst = fopen(argv[2], "w")) == NULL) {
		perror("fopen: dst");
		exit(1);
	}

	while(!feof(src)){
		ch = (char)fgetc(src);
		if(ch != EOF)
			fputc((int)ch, dst);


		count++;
	}






	fclose(src);
	fclose(dst);
}

