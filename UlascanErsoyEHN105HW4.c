#include <stdio.h>
#include <stdlib.h>

/** Ulascan Ersoy 040160509 Hw4 **/

//Function Prototypes
void calculate(int* sizex , int* sizey , int A[*sizex][*sizey] , int B[*sizex][*sizey]);
void printM(int* sizex , int* sizey , int A[*sizex][*sizey] , int B[*sizex][*sizey]);		

int main(){

	int _sizex = 5 , _sizey = 4 , i;		   //Declare
	
	int A[_sizex][_sizey] , B[_sizex][_sizey]; //Declare

	for(i = 0 ; i < 5 * 4 ; i++){
	       	
		A[i%5][i/5] = ("\n %d" , ((i * 2) + 1) + 3 );	//Initialize A
		B[i%5][i/5] = 0;								//Initialize B 

	}//End of for
	calculate(&_sizex , &_sizey , A , B); //Calculate
	printM(&_sizex , &_sizey , A , B ); //print	

}//End of main

void calculate(int* sizex , int* sizey , int A[*sizex][*sizey] , int B[*sizex][*sizey]){

	int i , k; 
	
	for(i = 0 ;  i < (*sizex) * (*sizey) ; i++){

			printf("\n%d : " , A[i%5][i/5]);

			int curr = A[i%5][i/5];
			for(k = 2 ; curr!= 1 ;){

			
			if(curr % k == 0){
			
				curr/= k;
				B[i%5][i/5]+= k;
				printf("%d*" , k );

			}else{
			
				if(k == 2)k++; else k+=2;				

			}//End of if



			}//End of for **/

			puts("\b \b");

	}//End of for

	puts("\v");

}//End of Calculate

void printM(int* sizex , int* sizey , int A[*sizex][*sizey] , int B[*sizex][*sizey]){


	printf("A : \t\t\t\t\t B : \n\n");
	int i ;
	for(i = 0 ;  i < (*sizey) ; i++){

		printf("%d\t%d\t%d\t%d\t%d\t|\t%d\t%d\t%d\t%d\t%d\n" , A[0][i] , A[1][i], A[2][i] , A[3][i]  , A[4][i],
													   		   B[0][i] , B[1][i], B[2][i] , B[3][i]  , B[4][i]);

	}//End of for

	puts("\n");

}//End of PrintM	
