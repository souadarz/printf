#include <stdio.h>
#include "header.h"

int main(void)
{
    int n;
    n = _printf("my name is %s %c.\n", "fatiha", 'a');
    printf("%d\n", n);
    return (0);
}