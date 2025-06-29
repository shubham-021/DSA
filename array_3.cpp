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

// rearrange positive and negatives , array always starts from a positive number

//brute force:
vector<int> rearrange_brute(vector<int> &a){
    int size = a.size();
    vector<int> pos;
    vector<int> neg;
    vector<int> ans;

    for(auto it:a){
        if(it<0) neg.push_back(it);
        else pos.push_back(it);
    }

    int posi = 0;
    int negi =0;
    for(int i=0; i<size; i++){
        if(i&1){
            ans.push_back(neg[negi]);
            negi++;
        }else{
            ans.push_back(pos[posi]);
            posi++;
        }
    }
    return ans;
}


// better way : not using any additional array to store , instead modifying the original
// TC : O(2N) , SC : O(N)
void rearrange_better(vector<int> &a){
    int size = a.size();
    vector<int> pos;
    vector<int> neg;

    for(auto it:a){
        if(it<0) neg.push_back(it);
        else pos.push_back(it);
    }

    int posi = 0;
    int negi =0;
    for(int i=0; i<size; i++){
        if(i&1){
            a[i] = neg[negi];
            negi++;
        }else{
            a[i] = pos[posi];
            posi++;
        }
    }
}

// TC : O(N) , SC : O(N)
vector<int> rearrange_optimal(vector<int> &a){
    int size = a.size();
    int pos =0;
    int neg =1;
    vector<int> ans(size);
    
    for(int i=0; i<size; i++){
        if(a[i]<0){
            ans[neg]=a[i];
            neg += 2;
        }else{
            ans[pos]=a[i];
            pos+=2;
        }
    }

    return ans;
}

// till now , we have done assuming occurence of pos and neg are same , what if they are present in diff numbers
// TC : O(2N)
void rearrange_diff_occ(vector<int> &a){
    int size = a.size();
    vector<int> pos,neg;

    for(auto it : a){
        if(it>0) pos.push_back(it);
        else neg.push_back(it);
    }

    int pos_size = pos.size();
    int neg_size = neg.size();

    if(pos_size<neg_size){
        for(int i=0; i<pos_size; i++){
            a[2*i] = pos[i];
            a[2*i+1] = neg[i];
        }
        int index = pos_size*2;
        for(int i=pos_size; i<neg_size; i++){
            a[index++]=neg[i];

        }
    }else{
        for(int i=0; i<neg_size; i++){
            a[2*i] = pos[i];
            a[2*i+1] = neg[i];
        }
        int index = neg_size*2;
        for(int i=neg_size; i<pos_size; i++){
            a[index++]=pos[i];
        }
    }
}

// next permutation in sorted order (sorted order means in dictionary like order)
// [1,2,3,] -> [1,3,2] -> [2,1,3] -> [2,3,1] -> [3,1,2] -> [3,2,1] -> [1,2,3] : all permutations of array [1,2,3]
// given an array find the next permutation 

// brute force : 
// find all permutation and store them in sorted order , then find the next permutation of given array
// find permutations by recursion

// better way : use stl's next_permutation method
void next_permutation_stl(vector<int> &a){
    next_permutation(a.begin(),a.end());
}

// optimal way : 




int main(){
    vector<int> b = {3,1,2};
    next_permutation_stl(b);
    for(auto it:b)cout<<it<<" ";
    return 0;
}