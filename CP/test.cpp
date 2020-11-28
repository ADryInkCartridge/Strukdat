#include <stdio.h>
int main()
{
   int x,y;
   for(x=1;x<=3;x++) // nomor (1)
     for (y=3;y>=1;y--) // nomor (2)
           printf("%d %d ",x,y);
    return 0;
}
