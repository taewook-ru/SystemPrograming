#include <stdio.h>
#include <dlfcn.h>

main()
{
	void *handle;
	int (*add)(int, int), (*subtract)(int, int), (*multiply)(int, int);
	double (*divide)(double, double);
	char *error;

	handle = dlopen ("./lib/libpr1.so", RTLD_LAZY);
	if(!handle){
		fputs(dlerror(), stderr);
		exit(1);
	}

	add = dlsym(handle, "add");
	if((error = dlerror()) != NULL) {
		fprintf(stderr, "%s", error);
		exit(1);
	}

	subtract = dlsym(handle, "subtract");
	if((error = dlerror()) != NULL) {
		fprintf(stderr, "%s", error);
		exit(1);
	}

	multiply = dlsym(handle, "multiply");
        if((error = dlerror()) != NULL) {
                fprintf(stderr, "%s", error);
                exit(1);
        }

	divide = dlsym(handle, "divide");
        if((error = dlerror()) != NULL) {
                fprintf(stderr, "%s", error);
                exit(1);
        }
	
 	int a, b;


        printf("input:");
        scanf("%d %d", &a, &b);


        printf("add(%d, %d) = %d \n", a, b, add(a, b));


        printf("subtract(%d, %d) = %d \n", a, b,  subtract(a, b));

        printf("multiply(%d, %d) = %d \n", a, b, multiply(a, b));

        printf("divide(%d, %d) = %f \n", a, b, divide(a, b));
	

	dlclose(handle);
}


	
