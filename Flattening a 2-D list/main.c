#include <stdio.h>
#include "assignment3.h"

int main ()
{
    int n = 5 , m = 5;
    
    HBnodePtr L = createHBlist(n , m );
    printf("HB list \n");
    printHBlist(L);
    printf("\n");


    SLnodePtr P = flattenList(L);
    printf("SL list \n");
    printSLlist(P);
    printf("\n");

    // printf("\n");
    // printf("HB list \n");
    // printHBlist(L);
    // printf("\n");

    freeSLlist(P);
    freeHBlist(L);
    return 0;
}