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

int no_odd(vector<int> &s , int size){
    int count_one = 0;
    int count_two = 0;
    for(auto it:s){
        if(it==1)count_one++;
        else count_two++;
    }

    if(count_one==count_two && count_one%2==0){
        return count_one/2;
    }else if((count_one==count_two && count_one%2!=0) || (count_two<count_one)){
        return count_two;
    }else if(count_one==size || count_two==size){
        return 0;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int size;
        cin>>size;
        vector<int> arr;
        int inpt;
        for(int i=0; i<size; i++){
            cin>>inpt;
            arr.push_back(inpt);
        }
        cout<<no_odd(arr,size)<<endl;
    }
    return 0;
}