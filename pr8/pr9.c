#include <stdio.h>
#include <stdlib.h>

int main(void)
{
        int **arr1, **arr2;
        int n, m;
        int i, j;

        printf("width array size : ");
        scanf("%d", &n);

        printf("height array size : ");
        scanf("%d", &m);


        arr1 = (int **)malloc(sizeof(int) *m);
        for(i=0; i<m; i++){
                arr1[i] = (int **)malloc(sizeof(int) *n);

        }

        arr2 = (int **)malloc(sizeof(int) *m);
        for(i=0; i<m; i++){
                arr2[i] = (int *)malloc(sizeof(int) *n);

        }


	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
				printf("arr1[%d][%d] :", i, j);
				scanf("%d", &arr1[i][j]);
				}
				}

	      for(i=0; i<m; i++){
                for(j=0; j<n; j++){
                                printf("arr1[%d][%d] : %d ", i, j, arr1[i][j]);
                                }
                                }



 for(i=0; i<m; i++){
                        free(arr1[i]);					
free(arr2[i]);
					}

        free(arr1);


        free(arr2);

        return 0;

}

