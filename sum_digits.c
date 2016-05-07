#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


void mul2(int *n)
{
    int c = 0, v;
    while(*n >= 0)
    {
        v  = c + *n * 2;
        c  = v / 10;
        *n++ = v % 10;
    }
    if(c) *n++ = c;//1
    *n = -1;//stopper
}

int sum(int *n)
{
    int sum=0;
    while(*n>=0)
        sum += *n++;
    return sum;
}

int main()
{
    int arr[1000] = {1, -1};//need 302 + 1, -1 is stoper
    int i;
    for(i = 0;i < 1000;i++)
        mul2(arr);
    printf("%d\n", sum(arr));
    return 0;
}
