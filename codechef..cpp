#include"headers.h"

int add(vector<int> &nums , int i){
    int min = INT_MAX;
    int index;
    int n = nums.size();
    int j = 0;
    int sum=0;
    while(j<n){
        if(j==i){
            if(nums[i]+1 < min){
                min = nums[i]+1;
                index = i;
            }
        }else{
            if(nums[j]+2 < min){
                min = nums[j]+2;
                index = j;
            }
        }
        j++;
    }
    return index;
}

int add_1_or_2(vector<int> &in , vector<int> &ev){
    int n = ev.size();
    int i=0;
    while(n>0){
        int noE = ev[i];
        while(noE>0){
            add(in , i);
            noE--;
        }
    }
    return 0;
}

int main(){
    vector<int> input = {1,2,1};
    vector<int> events = {2,1,1};
    cout<<add_1_or_2(input , events)<<endl;
    return 0;
}