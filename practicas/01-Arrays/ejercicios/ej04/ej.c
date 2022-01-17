#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main() {

    int v[10] = {1,2,3,4,5,6,7,8,9,10};
    int *p,i=1;
    p=&v;

    while(i<10+1)
    {
        printf("%d\n",*(p+10-i));
        i++;
    }

    i=9;

    while(i>-1)
    {
        printf("%d\n",*(p+i));
        i--;
    }




    system ("pause");

    return 0;

}
