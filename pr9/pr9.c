#include <search.h>
#include <stdio.h>
#include <string.h>

struct node {

	char *name;
	int mid, fin;
};

#define TABLESIZE 50

char nametable[TABLESIZE*20];
struct node nodetable[TABLESIZE];
struct node *root = NULL;

int compare(const void *cp1, const void *cp2, const void *cp3)
{
	return strcmp(((struct node *)cp1)->name, ((struct node *)cp2)->name);
}

void print_node(const void*, VISIT, int);

int main()
{
	char *nameptr = nametable;
	struct node *nodeptr = nodetable;
	struct node **ret;
	int i = 1;
	int a;

	printf("input count of student");
	scanf("%d", &a);

	ret = (struct node **)malloc(sizeof(struct node)*a);	

	while(scanf("%s %d %d", nameptr, &nodeptr -> mid, &nodeptr -> fin) != EOF && i++ <=a){
		nodeptr ->name = nameptr;

		ret = (struct node **)tsearch((void *) nodeptr, (void **) &root, compare);
		printf("\%s\"   ", (*ret)->name);


		if(*ret == nodeptr)
			printf("complete in tree\n");
		else
			printf("exist in tree \n");

		nameptr += strlen(nameptr) +1;
		nodeptr++;
	}
	twalk((void *) root, print_node);

	free(ret);
}

void print_node(const void *nodeptr, VISIT order, int level)
{
	if(order == preorder || order == leaf)
		printf("name = %s, mid term = %d, final term =%d\n",
				(*(struct node **)nodeptr)->name,
				(*(struct node **)nodeptr)->mid,
				(*(struct node **)nodeptr)->fin);

}

