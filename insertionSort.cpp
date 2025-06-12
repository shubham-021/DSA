#include "headers.h"

void insertion_Sort(vector<int> &arr , int size){
    for(int i = 0; i<size ; i++){
        int j = i;
        while( j > 0 && arr[j-1]>arr[j]){
            swap(arr[j-1] , arr[j]);
            j--;
        }
    }
}

int main(){
    vector<int> arr = {10,5,8,1,3,0,9}; 
    int size = arr.size();
    insertion_Sort(arr , size);
    for(int i =0;i<size;i++)cout<<arr[i]<<" ";
    return 0;
}