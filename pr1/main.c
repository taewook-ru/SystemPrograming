#include <stdio.h> 
#include "testlib.h"

int main(){


int a, b;


        printf("input:");
        scanf("%d %d", &a, &b);


        printf("add(%d, %d) = %d \n", a, b, add(a, b));


        printf("subtract(%d, %d) = %d \n", a, b,  subtract(a, b));

        printf("multiply(%d, %d) = %d \n", a, b, multiply(a, b));

        printf("divide(%d, %d) = %f \n", a, b, divide(a, b));


	return 0;
}
