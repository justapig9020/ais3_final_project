#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
	int  n;
	char *c;
    int *a;
    a = malloc (4);
    // puts ("main start");
   // scanf ("%d", &n);
    n = 10;
    c = malloc (n);
    for (int i=0; i<n; i++)
        c[i]='a'+i;
	free (c);
    c = NULL;
   // puts ("main terminate");
	return 0;
}
