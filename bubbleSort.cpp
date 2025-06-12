#include "headers.h"

void bubble_sort(vector<int> &arr , int size){
    for(int i = 0; i < size-1 ; i++){
        for(int j = 0; j < size-i-1 ; j++){
            if(arr[j] > arr[j+1]) swap(arr[j], arr[j+1]);
        }
    }
}

void optimized_bubble_sort(vector<int> &arr , int size){
    bool flag = true;
    for(int i = 0; i < size-1 ; i++){
        for(int j = 0; j < size-i-1 ; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                flag = false;
            }
        }
        if(flag == true) break;
    }
}

int main(){
    vector<int> arr = {1,2,3,5,4};
    int size = arr.size();
    optimized_bubble_sort(arr, size);
    for(auto el : arr)cout<<el<<" ";
    return 0;
}