#include<stdio.h>
#include<math.h>
#include "Image2.h"
#define ROW 128
#define COL 128


float arr1[3];
int n=9,t;

float SR1,SR2,SR3,SR4,SR5,SR6,SR7,SR8,SR9;

int Sliding_window[3][3];

int RED1[ROW][COL];
int SR[9];
float median;
int arr[8];

int main(){
	int i,j,i1,j1;

	
	for(i=0;i<ROW;i++){
		for(j=0;j<COL;j++){
			
			RED1[i][j]=Input[i][j];
			
		}
	}
	
	for(i=1;i<127;i++){
		for(j=1;j<127;j++){
			
			Sliding_window[1][1] = Input[i-1][j-1];
			Sliding_window[1][2] = Input[i-1][j];
			Sliding_window[1][3] = Input[i-1][i+1];
			Sliding_window[2][1] = Input[i][j-1];
			Sliding_window[2][2] = Input[i][j];
			Sliding_window[2][3] = Input[i][j+1];
			Sliding_window[3][1] = Input[i+1][j-1];
			Sliding_window[3][2] = Input[i+1][j];
			Sliding_window[3][3] = Input[i+1][j+1];
			
			SR1 = Sliding_window[1][1];
			SR2 = Sliding_window[1][2];
			SR3 = Sliding_window[1][3];
			SR4 = Sliding_window[2][1];
			SR5 = Sliding_window[2][2];
			SR6 = Sliding_window[2][3];
			SR7 = Sliding_window[3][1];
			SR8 = Sliding_window[3][2];
			SR9 = Sliding_window[3][3];
			
			
			arr[0]=SR1;
			arr[1]=SR2;
			arr[2]=SR3;
			arr[3]=SR4;
			arr[4]=SR5;
			arr[5]=SR6;
			arr[6]=SR7;
			arr[7]=SR8;
			arr[8]=SR9;
			
			
			for(i1=0;i1<=n-1;i1++)
			{
				for(j1=0;j1<n-1;j1++)
				{
					if(arr[j1]<=arr[j1+1])
					{
						t=arr[j1];
						arr[j1]=arr[j1+1];
						arr[j1+1]=t;
					}
					else{
						continue;
					}	
				}
			}
			if (n%2==0){
				median=(arr[(n)/2]+arr[n/2+1])/2.0;
			}
			else{
				median=arr[(n-1)/2];
			}
			
		
			RED1[i][j]=median;
			
		}
	}
	
	for(i=0;i<ROW;i++)	
	{
		printf("{");
	
		for(j=0;j<COL;j++)
		{
			printf("%d ",RED1[i][j]);
	}
	printf("}\n");

	
}
}





