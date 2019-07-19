#include <stdio.h>
#include <stdlib.h>
int a=0;
int *i;
int main(int argc, char **argv)
{
	printf("%s", " C after a very long time \n");
	printf("%d\n",a);
	i=(int*) malloc(sizeof(int)*1);
	*i=11;
	printf("%d\n",*i);
}
