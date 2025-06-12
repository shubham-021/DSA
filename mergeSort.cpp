#include"headers.h"

void merge_Array(vector<int> &arr , int low , int mid , int high){
    vector<int> newArray;
    int i = low;
    int j = mid + 1;
    
    while( i < mid + 1 && j < high+1){
        if(arr[j] < arr[i]){
            newArray.push_back(arr[j]);
            j++;
        }else{
            newArray.push_back(arr[i]);
            i++;
        }
    }

    while (i < mid+1){
        newArray.push_back(arr[i]);
        i++;
    }

    while (j<high+1){
        newArray.push_back(arr[j]);
        j++;
    }

    for(int i = low ; i < high+1 ; i++){
        arr[i] = newArray[i-low];
    }
    
}

void merge_Sort(vector<int> &arr , int startIndex , int lastIndex){
    if(startIndex == lastIndex )return;
    int mid = ( startIndex + lastIndex ) / 2 ;
    merge_Sort(arr,startIndex,mid);
    merge_Sort(arr,mid+1,lastIndex);
    merge_Array(arr , startIndex , mid , lastIndex);
}

int main(){
    vector<int> arr1 = {10,5,8,1,3,0,9};
    int size = arr1.size();
    merge_Sort(arr1 , 0 , size -1 );
    for(auto el : arr1 ) cout<<el<<" ";
    return 0;
}