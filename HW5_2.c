#include<stdio.h>
#include<stdlib.h>

int main()

{
	FILE *fIn;
	fIn=fopen("partf.txt","r");

	struct {int ID;	char description[100];double price;}parts[100];

	int i;

	for(i = 0 ; ; i++)if(fscanf(fIn , "%d %s %lf" , &parts[i].ID , parts[i].description , &parts[i].price) == EOF)break;
	
	fclose(fIn);

	fIn = fopen("part_picked.txt" , "w+");

	int j;

	for(j = 0 ; j < i ; j++)if(parts[j].price > 15.75)fprintf(fIn , "%d %s %lf \n" , parts[j].ID , parts[j].description , parts[j].price);

	fclose(fIn);
return 0;

}
