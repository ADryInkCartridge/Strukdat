// Menghitung banyaknya bangunan yang ada di map
// Made by Bayu Dasprog C 0172 copyright 2019 :))

#include <stdio.h>
char maps[100][100];
int n,count=0,x,y;
int a,b;
int build ()//Build map function
{
    int i=0,j=0;
    while(1)
    {
        char c = getchar();
        if (c == EOF)
        {
            a++;
            return 0;
        }
        if (c == '\n')
        {
            i++;
            a=i;
            b=j;
            j=0;
        }
        if (c == '0' || c== '1')
        {
            maps[i][j]=c;
            j++;
        }
        
    }
}
 
int buildingcheck(int x, int y)
{
    // Base case
    if (x<0||x>b-1||y<0||y>a-1) //
    return 0;
 
    // Rercursive case
    if (maps[y][x]!='0')
    {
        maps[y][x] = '0';// menandai yg sudah dilewati
        if (buildingcheck(x+1,y)) //turn right
        {
            return 1;
        }
        if (buildingcheck(x-1,y))//turn left 
        {
            return 1;
        }
        if (buildingcheck(x,y-1))//turn down
        {
            return 1;
        }
        if (buildingcheck(x,y+1))//turn down
        {
            return 1;
        }
        return 0;
    }
    else return 0;
}
 
 
int main ()
{
    int x,y;
    build();
//    printf("%d %d",a,b);
//    for (int i=0;i<a;i++) // scan le rat and le cheese
//    {
//        for (int j=0;j<b;j++)
//        {    
//            printf("%c",maps[i][j]);
//        }
//        printf("\n");
//    }
    for (int i=0;i<a;i++) // scan le rat and le cheese
    {
        for (int j=0;j<b;j++)
        {    
            if (maps[i][j]=='1') // Cek mulai Bangunan
            {
                y=i;
                x=j;
                buildingcheck(x,y);
                count++;
            }
        }
    }
    printf("%d\n",count);
//    printf("%d %d",a,b);
}
