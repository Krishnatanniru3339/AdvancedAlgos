#include<iostream>
#include<array>
using namespace std;

void findindices(int usertarget, int given_array[],int size_of_array){
	for (int j=0;j<(size_of_array-1);j++){
		for (int k=(j+1);k<size_of_array;k++){
			if((given_array[j]+given_array[k])==usertarget){
				cout<<j;
				cout<<k;
				cout<<"\n";
			}
		}
	}


}

int main() {
	int size_of_array;
	int given_array[105];
	int usertarget;
	int i=0;
	cout<<"Enter the length of array";
	cin>>size_of_array;
	cout<<"Please input the numbers in the array";
	while(i<size_of_array){
		cin>>given_array[i];
		i++;
	}
	cout<<"Enter your target number";
 	cin>>usertarget;
 	findindices(usertarget,given_array,size_of_array);
}








