#include"headers.h"

// finding missing element in array of 1 to N elements
// Brute force : iterate over N and find which value is not present in the array . T.C will be O(N^2)
// Better way: use hashing array , T.C will be O(N) , S.C will be O(N) due to use an additional hashing array

int missing_element(vector<int> &arr , int n){
    int size = arr.size();
    int missing = -1;
    vector<int> hashing(n+1,0);

    for(int i=0;i<size;i++){
        hashing[arr[i]] = 1;
    }

    for(int i = 1 ; i<n+1 ; i++){
        if(hashing[i] == 0){
            missing = i;
            break;
        }
    }
    return missing;
}

// Optimal way:

int optimal_missing_element_1(vector<int> &arr , int n){
    int index = 1;
    int missing = -1;
    for(int i=0; i<arr.size(); i++){
        if(arr[i] != index){
            missing = i;
            break;
        }
        index++;
    }
    return missing;
}

int optimal_missing_element_2(vector<int> &arr , int n){
    int total_sum = n*(n+2)/2;
    int arr_sum = 0;
    for(int i = 0; i<arr.size() ; i++){
        arr_sum += arr[i];
    }
    if(arr_sum == total_sum){
        return -1;
    }else{
        return total_sum - arr_sum;
    }
}

int xor_missing_element(vector<int> &arr , int n){
    int xor1 = 0;
    int xor2 = 0;
    for(int i=1;i<n+1;i++) xor1 ^= i;
    for(int i=0;i<arr.size();i++) xor2 ^= arr[i];
    return xor1^xor2;
}

int optimized_xor_missing_element(vector<int> &arr , int n){
    int xor1 = 0;
    int xor2 = 0;
    for(int i=0;i<arr.size();i++){
        xor1 ^= (i+1);
        xor2 ^= arr[i];
    }
    xor1 ^= n;
    return xor1^xor2;
}

// longest subarray whose sum is equal to k : video 20

int longest_subarray_sum(vector<int> arr , int k){
    int maxi = 0;
    int cnt = 0;
    int sum;
    for(int i=0;i<arr.size();i++){
        sum = arr[i];
        for(int j=i+1;j<arr.size();j++){
            if(sum>k){
                cnt++;
                break;
            }else if(sum<k){
                sum += arr[j];
                cnt++;
            }else{
                cnt++;
                maxi = max(cnt , maxi);
                cnt = 0;
                break;
            }
        }
    }
    return maxi;
}


int main(){
    vector<int> arr = {15, 5, 2, 7, 9};
    cout<<longest_subarray_sum(arr,15);
    return 0;
}