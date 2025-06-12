#include "headers.h"

void selection_sort(vector<int> &arr , int size){
    int minIndex;
    for(int i = 0 ; i < size - 1 ; i++){
        minIndex = i;
        for (int j = i + 1; j < size; j++){
            if(arr[j] < arr[minIndex] ) minIndex = j;
        }
        swap(arr[i] , arr[minIndex]);
    }
    

}


int main(){
    vector<int> arr = {10,5,8,1,3,0,9}; 
    int size = arr.size();
    selection_sort(arr , size);
    for(int i =0;i<size;i++)cout<<arr[i]<<" ";
    return 0;
}