#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define PRICE 15.75

/** Ulascan Ersoy 040160509 **/

struct part{

	int ID;
	char description[140];
	double price;

};


int main(){


	
	struct part* PARTS     = calloc(1 , sizeof(struct part));
	struct part* EXPENSIVE = calloc(1 , sizeof(struct part));
	
	FILE* f = fopen("partf.txt" , "r");

	if(!f){

		puts("Invalid file !");
		return -1;
	
	}//End of file check

	int p_size , e_size = 0;

	for(p_size = 0 ;; p_size++){


		if(fscanf(f ,"%d %s %lf",&PARTS[p_size].ID , &PARTS[p_size].description , &PARTS[p_size].price) == EOF )break;
		
		PARTS = realloc(PARTS , sizeof(struct part) * (p_size+2));

		if(PARTS[p_size].price >= PRICE){
		
			EXPENSIVE[e_size] = PARTS[p_size];
			e_size++;
			EXPENSIVE = realloc(EXPENSIVE , sizeof(struct part) * (e_size + 1));
			
		}//End of if

	}//End of for

	fclose(f);

	f = fopen("partpricef.txt" , "w+");

	int j;

	for(j = 0 ; j < e_size ; j++){


	fprintf( f ,"%d %s %lf \n" , EXPENSIVE[j].ID , EXPENSIVE[j].description , EXPENSIVE[j].price);



	}
	








}//End of main

