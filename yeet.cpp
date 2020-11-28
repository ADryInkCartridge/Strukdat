#include <stdio.h>

void isi (int *data)
{
	for (int i=0;i<5;i++)
	{
		scanf("%d",data);
		*data++;
	}
}

void tampil (int *data)
{
	for (int i=0;i<5;i++)
	{
		printf("%d ",*data);
		*data++;
	}
	puts("");
}

int main ()
{
	int mydata[5];
	printf("Pengisisan...\n");
	isi(mydata);
	printf("Tampilkan...\n");
	tampil(mydata);
}
