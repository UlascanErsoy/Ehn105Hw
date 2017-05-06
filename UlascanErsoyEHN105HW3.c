#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**Ulascan Ersoy EHN105 HW3 040160509**/

#define RowS 8
#define ColS 9

//Function Prototypes
void shuffle(int mtrx[RowS][ColS]);
void displayMatrix(int size_x , int size_y ,int mtrx[size_x][size_y]);


int main(){

//Initialize a seed for the random number generator
	srand(time(NULL));
//Generate a random matrix
	int matrix[RowS][ColS];
	int i , j;
	
	for(i=0;i<RowS;i++){
	
		for(j=0;j<ColS;j++) matrix[i][j] = rand()%26;

		}//End of random matrix gen
	printf("The Initial matrix: \n\n");
	displayMatrix(RowS , ColS , matrix);

	//Shuffle the matrix
	shuffle(matrix);
	printf("\nThe Shuffled matrix: \n\n");
	displayMatrix(RowS , ColS , matrix);
	
	//Ask for user input
	int poolx , pooly ;
	printf("\nEnter the dimesions of the pooling region [X,Y] : ");
	scanf("%d %d",&poolx ,&pooly);
	//Check if the dimensions are appropriate 
	if((RowS%poolx)!=0 || (ColS%pooly)!=0) {
		printf("Error : Inappropriate dimensions for pooling!\n");
		return -1;
	}
	
	//Start Pooling 
	int sizex = RowS / poolx,		//
		sizey = ColS / pooly;		//
	int pool_matrix[sizex][sizey];	//pool matrix
	int x , y , a ;					//Cursor
	//Initialize the pool matrix to 0, so we can use it as a cursor
	for(i = 0 ; i < sizex ; i++) for(j = 0 ; j < sizey ; j++) pool_matrix[i][j] = 0;

	for(a = 0 ; a < sizex * sizey ; a++){
		x = a % sizex; //Calculate where our cursor
		y = a / sizex; //belongs on the pool matrix
		for(i = 0 ; i < poolx ; i++){

			for(j = 0 ; j < pooly ; j++){

				if(matrix[x * poolx + i][y * pooly + j] > pool_matrix[x][y]) 
					pool_matrix[x][y] = matrix[x * poolx + i][y * pooly + j];

			}//End of col-loop

		}//End of row-loop

	}//End of for-loop

printf("The matrix after the max-pooling : \n\n");
displayMatrix(sizex , sizey , pool_matrix);

system("Pause");
return 0;
}//End of the main function

//Matrix Display function 
void displayMatrix(int size_x , int size_y ,int mtrx[size_x][size_y]){

	int i , j;
	for(i = 0 ; i < size_x;i++){

		for(j=0; j<size_y ; j++){

			printf("%d\t",mtrx[i][j]);

		}//End of Col loop

		printf("\n");
	}//End of Row loop

}//End of displayMatrix

//Shuffling function
/** Uses the modern adoptation of Fisher&Yate's shuffling algorhtym **/
void shuffle(int mtrx[RowS][ColS]){

	//Turn the matrix into a single dimensional array
	int size = RowS * ColS;
	int _array[size] ,s_array[size];
	int i , j;
	for(i=0 ; i < RowS ; i++){

		for(j=0 ; j < ColS ; j++){

			_array[j * RowS + i] = mtrx[i][j];
		
		}//End of Col loop

	}//End of row loop

	//Shuffle
	int temp;
	for(i=size ; i != 0 ; i--){

		temp = rand()%size;
		s_array[i-1] = _array[temp]; //Put the chosen index from the original array
									 //to the end of the shuffle matrix
		_array[temp] = _array[i- 1]; //Swap the last unstruct number with the chosen one  

	}
	//Reassamble the matrix
	for(i=0 ; i < size ; i++){

		mtrx[i%RowS][i/RowS] = s_array[i];

	}//End of for-loop
	
}//End of function


