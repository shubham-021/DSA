#include"headers.h"

int partition(vector<int> &arr , int low , int high){ 
    int pivot = arr[low];
    int i = low;
    int j = high;

    while(i<j){
        while(arr[i] <= pivot && i < high){
            i++;
        }

        while(arr[j] >= pivot && j > low){
            j--;
        }

        if(i<j) swap(arr[i] , arr[j]);
    }

    swap(arr[low] , arr[j]);
    return j;
}

void quick_Sort(vector<int> &arr , int low , int high){
    if(low<high){
        int pIndex = partition(arr , low , high);
        quick_Sort(arr , low , pIndex - 1);
        quick_Sort(arr , pIndex+1 , high);
    }
}

int main(){
    vector<int> arr1 = {10,5,8,1,3,0,9};
    int size = arr1.size();
    quick_Sort(arr1 , 0 , size -1 );
    for(auto el : arr1 ) cout<<el<<" ";
    return 0;
}