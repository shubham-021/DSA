#include "headers.h"
#include<cctype>

void reverseArr(int i , int a[] , int n){
    if(i>=n/2) return;
    swap(a[i] , a[n-i-1]);
    reverseArr(i+1,a,n);
}

bool checkPalin(string s , int i , int n){
    if(i>=n/2) return true;
    if(s[i] == s[n-i-1]){
        return checkPalin(s,i+1,n);
    }else{
        return false;
    }    
}

// for loop fibo implementation
int fibo(int n){
    int fiboSum[n];
    fiboSum[0] = 0;
    fiboSum[1] = 1; 
    for(int i =2 ; i<n ; i++) fiboSum[i] = fiboSum[i-2] + fiboSum[i-1];
    return fiboSum[n-1];
}

// recursive fibo implementation
int recFibo(int n){
    if( n <= 2) return n-1;
    return recFibo(n-1) + recFibo(n-2);
}


int main(){
    string s = "Shubham";
    
    for(char &c : s) c = toupper(c);

    cout<<s;

    return 0;
}



