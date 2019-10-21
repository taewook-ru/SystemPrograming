#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

# define assert(expr)							\
  ((expr)								\
   ? __ASSERT_VOID_CAST (0)						\
   : __assert_fail (__STRING(), __FILE__, __LINE__, __ASSERT_FUNCTION))



void my_assert(FILE *fp){
	


	assert(fp != NULL);




}

main(int argc, char *argv[])
{
	FILE *fp;

	if (argc < 2) {

		printf("Usage: file_name \n");
		exit(1);
	}


	fp = fopen(argv[1], "r");

	my_assert(fp);

	fclose(fp);
}
