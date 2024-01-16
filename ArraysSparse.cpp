#include<iostream>
#include<array>
using namespace std;

int matrixcolumnsize(int given_sparse_matrix[4][5]){
	int number_of_columns;
	int i=0;
	for (int i=0;i<4;i++){
		for (int j=0;j<5;j++){
			if(given_sparse_matrix[i][j]!=0){
				number_of_columns++;
			}
		}
	}
	return number_of_columns;
}

void resultmatrix(int number_of_columns, int given_sparse_matrix[4][5]){
	int result_matrix[3][number_of_columns];
	int k=0; 
	int i=0;
	while (i<4){
		int j=0;
		while(j<5){
			if(given_sparse_matrix[i][j]!=0){
				result_matrix[0][k] = i;  
                result_matrix[1][k] = j;  
                result_matrix[2][k] = given_sparse_matrix[i][j];  
                k++;  
			}
		 j++;
		}
		i++;
	}

	
	for(int i=0 ;i<3; i++)  
    {  
        for(int j=0; j<number_of_columns; j++)  
        {  
            cout<< result_matrix[i][j];  
            cout<<"\t"; 
        }  
        cout<<"\n";  
    }  
}

int main(){
	int number_of_columns = 0; 
	int given_sparse_matrix [4][5]= 
	{
		{0,0,3,0,4},
		{0,0,5,7,0},
		{0,0,0,0,0},
		{0,2,6,0,0}
	};
 	number_of_columns= matrixcolumnsize(given_sparse_matrix);
	resultmatrix(number_of_columns,given_sparse_matrix);
}