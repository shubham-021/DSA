#include "headers.h"
// Q1 - Perfect square less than N

long long int bs(int n){
    int start = 1;
    int end = n;
    long long int mid;
    while(start<end){
        mid = start + (end-start)/2;
        long long int square = mid * mid;
        if(square == n) return mid;
        if(square>n){
            end = mid - 1;
        }else{
            start = mid+1;
        }
    }
    return start;
}

int main() {
	int t;
	cin>>t;
	while(t>0){
	    int input;
	    cin>>input;
	    long long int result = bs(input);
	    long long square = result * result;
	    if(square==input){
	        cout<<square<<endl;
	    } else{
	        result--;
	        square = result * result;
	        cout<<square<<endl;
	    }
	    t--;
	}
	return 0;
}

// Q2 - GCD



