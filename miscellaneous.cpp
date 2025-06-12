#include"headers.h"

// finding the largest in an array

int largest_in_array(vector<int> &arr){
    int size = arr.size();
    int largest = -1;
    for(int i = 0 ; i <size ; i++){
        if(arr[i] > largest) largest = arr[i];
    }
    return largest;
}

// finding second largest in an array

int second_largest_in_array(vector<int> &arr){
    int size = arr.size();
    int largest = arr[0];
    int second_largest = -1;
    for(int i = 1 ; i <size ; i++){
        if(arr[i] > largest){
            second_largest = largest;
            largest = arr[i];
        }else if(arr[i] != largest && arr[i] > second_largest) second_largest = arr[i];
    }
    return second_largest;
}

// checking if array is sorted or not

bool is_sorted(vector<int> arr){
    int size = arr.size();
    bool flag = true;
    for(int i = 1 ; i < size ; i++){
        if(arr[i] < arr[i-1]){
            flag = false;
            break;
        }
    }

    return flag;
}

// remove duplicate elements from array

int remove_dup(vector<int> &arr){
    int size = arr.size();
    int i = 0;
    for(int j = i+1 ; j<size; j++){
        if(arr[i] != arr[j]){
            arr[i+1] = arr[j];
            i++;
        }
    }
    return i+1;
}

// rotate array by d places

void rotate_array(vector<int> &arr, int d){
    int size = arr.size();
    int rotate_by = d % size ;

    if(rotate_by != 0){
        vector<int> removed(d);
        for(int i = 0 ; i<rotate_by ; i++) removed[i] = arr[i];

        for(int j = rotate_by; j < size; j++){
            int to_replace = j - rotate_by;
            arr[to_replace] = arr[to_replace + rotate_by];
        }

        for(int k = 0 ; k < rotate_by ; k++){
            arr[size-rotate_by+k] = removed[k];
        }
    }
}

// optimal rotate array by d places , optimal as it uses no extra space 

void reverse_array(vector<int> &arr , int low , int high){
    int mid = ( low + high ) / 2 ;
    int i = low;
    int j = high;

    while(i < j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
}

void optimal_rotate_array(vector<int> &arr , int d){
    int size = arr.size();
    d = d % size ;
    reverse_array(arr,0,d-1);
    reverse_array(arr,d,size-1);
    reverse_array(arr,0,size-1);
}

int main(){
    vector<int> arr = {10,5,8,1,3,0,9};
    optimal_rotate_array(arr , 2);
    for( auto it : arr ) cout<<it<<" ";
    return 0;
}