#include <stdio.h>
#include <stdlib.h>

typedef struct mhs {
	char nrp[10];	char nama[30];	int nilai;
	mhs *left; 	mhs *right;
};
mhs *input()
{	mhs* a = (struct mhs*)
                                  malloc(sizeof(struct mhs));
	printf("nrp   :");scanf("%s",a->nrp);
	//printf("nama  :");scanf("%s",a->nama);
	//printf("nilai :");scanf("%d",&a->nilai);
	a->left=NULL;
	a->right=NULL;	
	return a;
}
void output(mhs *a)
{	printf("nrp   = %s\n",a->nrp);
	//printf("nama  = %s\n",a->nama);
	//printf("nilai = %d\n",a->nilai);
}
void printPreorder(mhs *a)
{	if (a==NULL) return;
	output(a);
	printPreorder(a->left);
	printPreorder(a->right);
}
void printpostorder(mhs *a)
{	if (a==NULL) return;
	printpostorder(a->left);
	printpostorder(a->right);
	output(a);
}
void printinorder(mhs *a)
{	if (a==NULL) return;
	printinorder(a->left);
	output(a);
	printinorder(a->right);
}

int main()
{	mhs *data;
	data=input();data->left=input();	data->right=input();	data->left->left=input();	data->left->right=input();
	printPreorder(data);
	printinorder(data);
	printpostorder(data);
	system("pause");return 0;
}


