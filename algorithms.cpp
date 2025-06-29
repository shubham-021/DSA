#include"headers.h"

// Sieve of Eratosthenes
int count_primes(int &n){
    vector<bool> track(n , true);
    track[0] = track[1] = false;
    int count = 0;

    for(int i=2; i<n; i++){
        if(track[i]){
            count++;
        }

        for(int j = i*2; j<=n; j=j+i){
            track[j] = false;
        }
    }

    return count;
}

// Euclid's way of finding GCD

int gcd(int a , int b){
    if(a==0) return b;
    else if(b==0) return a;
    
    if(a>b){
        gcd(a%b , b);
    }else{
        gcd(a , b-a);
    }

    return 1;
}

int main(){
    int n = 40;
    cout<<gcd(2,3);
    return 0;
}
