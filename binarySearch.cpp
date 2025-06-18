#include"headers.h"
// first occurence

int first_Occ(vector<int> nums , int k){
    int ans;
    int n = nums.size();
    int start = 0;
    int end = n-1;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(nums[mid]==k){
            ans = mid;
            end = mid-1;
        }else if(nums[mid]<k){
            start = mid + 1;
        }else{
            end = mid - 1;
        }
    }
    return ans;
}

// last occurence

int last_Occ(vector<int> nums , int k){
    int ans;
    int n = nums.size();
    int start = 0;
    int end = n-1;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(nums[mid]==k){
            ans = mid;
            start = mid+1;
        }else if(nums[mid]<k){
            start = mid + 1;
        }else{
            end = mid - 1;
        }
    }
    return ans;
}

// total occurence

int total_Occ(vector<int> &nums , int k){
    int first = first_Occ(nums , k);
    int last = last_Occ(nums , k);
    int total = (last-first)+1;
    return total;
}

// peak of mountain : linear search 

int peak_Mountain_LS(vector<int> &nums){
    int index;
    int max = INT_MIN;
    for(int i=0; i<nums.size(); i++){
        if(nums[i]>max){
            max = nums[i];
            index = i;
        }else{
            break;
        }
    }
    return index;
}

// peak of mountain : binary search

int peak_Mountain_BS(vector<int> &nums){
    int index;
    int n = nums.size();
    int start = 0;
    int end = n-1;
    while(start<end){
        int mid = start + (end - start)/2;
        if(nums[mid]<nums[mid+1]){
            start = mid + 1;
        }else{
            end = mid;
        }
    }
    index = end;
    return index;
}

// finding pivot element index

int pivot(vector<int> &nums){
    int n = nums.size();
    int start = 0;
    int end = n-1;
    while(start<end){
        int mid = start + (end-start)/2;
        if(nums[mid]>nums[start]){
            start = mid+1;
        }else{
            end = mid;
        }
    }
    return start;
}

int main(){
    vector<int> arr = {7,9,1,2,3};
    cout<<pivot(arr)<<endl;
    return 0;
}

