// Write a program which reads 10 numbers into an array. The array should not contain any duplicate values. The output should then display all the indexes of the values and the value stored in the corresponding indexes.  
#include <iostream>
using namespace std; 

bool isDuplicate( int n, int arr[], int value){
    for(int i = 0; i < n; i++){
        if(arr[i] == value)
            return true;
    }
    return false;
}

void print(int n, int arr[]){
    for (int i = 0; i < n; i++)
        cout<< arr[i] << " " ;
}

int main (){
    int n = 10;
    int arr[n]; 
    int value;
    int count = 0;
    cout << "Enter 10 numbers, no duplicate ";
    while(count < n){
        cout << "enter ";
        cin >> value;
        
        if(isDuplicate(n, arr, value))
            cout << "Duplicate try again ";
        else{
            arr[count] = value;
            count++;
        }
        
    };
    print(n, arr);
    
    return 0;
    
}
