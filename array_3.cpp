#include "headers.h"

// maximum subarray sum
// brute force 

// int max_subarray(vector<int> &nums){
//     int n = nums.size();
//     vector<int> helper;
//     int sum;
//     for(int i=0; i<n; i++){
//         sum = nums[i];
//         helper.push_back(sum);
//         for(int j=i+1; j<n; j++){
//             sum += nums[j];
//             helper.push_back(sum);
//         }
//     }

//     int max = helper[0];
//     for(int i=1 ; i<helper.size(); i++){
//         if(helper[i]>max) max = helper[i];
//     }

//     return max;
// }

// you dont have to use an additional array , you can do this :

int max_subarray(vector<int> &nums){
    int n = nums.size();
    int maxi = INT_MIN;
    for(int i=0; i<n; i++){
        int sum = 0;
        for(int j=i; j<n; j++){
            sum += nums[j];
            maxi = max(maxi , sum);
        }
    }
    return maxi;
}

// optimal solution : use kadane's algo

int max_subarray_kadane(vector<int> &nums){
    int n = nums.size();
    int maxi = INT_MIN;
    int sum = 0;
    for(int i=0; i<n; i++){
        if(sum<0)sum = 0;
        sum += nums[i];
        if(sum>maxi)maxi=sum;
    }
    return maxi;
}

// print the maximum subarray

int max_subarray_print(vector<int> &nums){
    int n = nums.size();
    vector<int> print(2) ;
    int maxi = INT_MIN;
    int sum = 0;
    int j = 0;
    for(int i=0; i<n; i++){
        if(sum<0){
            j = i;
            sum = 0;
        }
        sum += nums[i];
        if(sum>maxi){
            maxi=sum;
            print[0] = j;
            print[1] = i;
        }
    }
    cout<<print[0]<<" "<<print[1]<<endl;
    return maxi;
}


int main(){
    vector<int> arr = {-2,-3,4,-1,-2,1,5,-3};
    cout<<max_subarray_print(arr);
    return 0;
}