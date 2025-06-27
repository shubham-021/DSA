#include"headers.h"

// print in sinusoidal form

// (i&1) --> gives 1 for odd i and 0 for even i 
vector<int> sine_wave_form(vector<vector<int>> &a , int col , int row){
    vector<int> ans;
    for(int i=0; i<col; i++){
        if(i&1){
            for(int j=row-1; j>=0; j--){
                ans.push_back(a[j][i]);
            }
        }else{
            for(int j=0; j<row; j++){
                ans.push_back(a[j][i]);
            }
        }
    }

    return ans;
}

int main(){
    vector<vector<int>> c = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> ans = sine_wave_form(c,3,3);
    for(auto it:ans)cout<<it<<" ";
    return 0;
}