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

// spiral print

vector<int> spiral_print(vector<vector<int>> &a){
    int row = a.size();
    int col = a[0].size();

    vector<int> ans;
    int total = row*col;
    int count = 0;

    int startingCol = 0;
    int startingRow = 0;
    int endingCol = col-1;
    int endingRow = row-1;

    while(count<total){
        for(int i=startingCol; count<total && i<=endingCol; i++){
            ans.push_back(a[startingRow][i]);
            count++;
        }
        startingRow++;

        for(int i=startingRow; count<total && i<=endingRow; i++){
            ans.push_back(a[i][endingCol]);
            count++;
        }
        endingCol--;

        for(int i=endingCol; count<total && i>=startingCol; i--){
            ans.push_back(a[endingRow][i]);
            count++;
        }
        endingRow--;

        for(int i=endingRow; count<total && i>=startingRow; i--){
            ans.push_back(a[i][startingCol]);
            count++;
        }
        startingCol++;
    }

    return ans;
}

// transpose 

void transpose(vector<vector<int>> &a){
    int row = a.size();
    int col = a[0].size();

    for(int i=0; i<row; i++){
        for(int j=i+1; j<col; j++){
            swap(a[i][j],a[j][i]);
        }
    }

}

// rotate_90_degree

void rotate_90(vector<vector<int>> &a){
    int row = a.size();
    transpose(a);

    // reverse each row 
    for(int i=0; i<row; i++){
        reverse(a[i].begin(),a[i].end());
    }
}

int main(){
    vector<vector<int>> c = {{1,2,3},{4,5,6},{7,8,9}};
    rotate_90(c);
    for(auto it : c){
        for(auto x : it){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}