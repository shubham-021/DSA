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

// sum --> contiguous triplets having sum = 3 

vector<pair<int,int>> three(vector<int> &nums){
    int n = nums.size();
    int i = 0 ;
    int j = 0;
    int sum = 0;
    int count = 3;
    pair<int,int> p;
    vector<pair<int,int>> will_return;

    while(i<n-2){
        if(sum<4 && count){
            sum += nums[j];
            count--;
            j++;
        }else{
            if(sum==3){
                p = {i,j-1};
                will_return.push_back(p);
            }
            i++;
            j=i;
            sum = 0;
            count = 3;
        }
    }
    return will_return;
}

// checking valid palindromes after removing alphanumeric characters ,  ex : "A man, a plan, a canal: Panama";

char lowerCase(char ch){
        if(ch>='A'&&ch<='Z'){
            return ch-'A'+'a';
        }
        return ch;
    }

bool checking(string &s){
    int start = 0;
    int end = s.length()-1;
    while(start<end){
        if(s[start]!=s[end])return false;
        else{
            start++;
            end--;
        }
    }
    return true;
}

bool isPalindrome(string s) {
    string lowerString = "";
    for(int i=0; i<s.length(); i++){
        lowerString += lowerCase(s[0]);
    }
    string compare = "";
    for(int i=0; i<s.length(); i++){
        if((lowerString[i]>='a'&& lowerString[i]<='z')){
            compare += lowerString[i];
        }
    }
    return checking(compare);
}

int main(){
    string s = "A man, a plan, a canal: Panama";
    string lowerString = "";
    for(int i=0; i<s.length(); i++){
        lowerString += lowerCase(s[i]);
    }
    string compare = "";
    for(int i=0; i<s.length(); i++){
        if((lowerString[i]>='a'&& lowerString[i]<='z')){
            compare += lowerString[i];
        }
    }
    cout<<checking(compare)<<endl;
    
    return 0;
}