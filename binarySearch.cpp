#include"headers.h"
// binary search
int bs(vector<int> &nums , int k){
    int n = nums.size();
    int start = 0;
    int end = n-1;
    int mid;
    while(start <= end){
        mid = start + (end - start)/2;
        if(nums[mid]==k){
            return mid;
        }else if(nums[mid]>k){
            end = mid - 1;
        }else{
            start = mid + 1;
        }
    }
    return -1;
}

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

// search in rotated array

int bs_mod(vector<int> &nums , int k , int start , int end){
    int mid;
    while(start <= end){
        mid = start + (end - start)/2;
        if(nums[mid]==k){
            return mid;
        }else if(nums[mid]>k){
            end = mid - 1;
        }else{
            start = mid + 1;
        }
    }
    return -1;
}

int search_rotated(vector<int> &nums , int k){
    int pivotElement = pivot(nums);
    int n = nums.size();
    int start , end ; 
    if(k==nums[0]){
        return pivotElement;
    }else if(k<nums[0]){
        start = pivotElement + 1;
        end = n-1;
        return bs_mod(nums , k , start , end);
    }else{
        start = 1;
        end = pivotElement-1;
        return bs_mod(nums , k , start , end);
    }

    return -1;
}

// finding sqr root of a number

long long int square_root(int num){
    int start = 1;
    int end = num;
    long long int ans = -1;
    int mid;
    while(start<=end){
        mid = start + (end-start)/2;
        if(mid*mid == num){
            return mid;
        }else if(mid*mid>num){
            end = mid-1;
        }else{
            ans = mid;
            start = mid + 1;
        }
    }
    return ans;
}

// book allocation : 2 students : brute force

int book(vector<int> &nums){
    int n = nums.size();
    int min = INT_MAX;
    int total = 0;
    for(auto it : nums) total+=it;

    int i=0;
    while(i<n-1){
        int max = 0;
        int j=i;
        while(j>=0){
            max+=nums[j];
            j--;
        }
        int left = total - max;
        if(max>left){
            if(max<min)min = max;
        }else{
            if(left<min)min=left;
        }
        i++;
    }
    return min;
}

int main(){
    vector<int> arr = {10,20,30,40};
    cout<<book(arr)<<endl;
    return 0;
}

