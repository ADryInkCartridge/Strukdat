#include <stdio.h>
#include <string.h>

int main ()
{
	int maps[10][10];
	char lol[100],*val;
	int bawah,num,value,samping;
	char delims[] = " \t\r\n";
	for (int i=0;i<10;i++)
	{
		int j=0;
		if (fgets(lol, 100, stdin) == NULL) 
        {
        	bawah=i;
        	break;
		}
		val = strtok(lol, delims);
		num = sscanf(val, "%d",&value);
		samping = num-1;
		while(num>0)
	    {
	    	maps[i][j]=value;
	        val = strtok(NULL, delims);
	        num = (val == NULL) ? 0 : sscanf(val, "%d",&value);
	    }
	}
	for (int a=0;a<bawah;a++)
	{
		for (int b=0;b<samping;b++)
		{
			printf("%d",maps[a][b]);
		}
		puts("");
	}
}
