#include"headers.h"

// finding missing element in array of 1 to N elements
// Brute force : iterate over N and find which value is not present in the array . T.C will be O(N^2)
// Better way: use hashing array , T.C will be O(N) , S.C will be O(N) due to use an additional hashing array

int missing_element(vector<int> &arr , int n){
    int size = arr.size();
    int missing = -1;
    vector<int> hashing(n+1,0);

    for(int i=0;i<size;i++){
        hashing[arr[i]] = 1;
    }

    for(int i = 1 ; i<n+1 ; i++){
        if(hashing[i] == 0){
            missing = i;
            break;
        }
    }
    return missing;
}

// Optimal way:

int optimal_missing_element_1(vector<int> &arr , int n){
    int index = 1;
    int missing = -1;
    for(int i=0; i<arr.size(); i++){
        if(arr[i] != index){
            missing = i;
            break;
        }
        index++;
    }
    return missing;
}

int optimal_missing_element_2(vector<int> &arr , int n){
    int total_sum = n*(n+2)/2;
    int arr_sum = 0;
    for(int i = 0; i<arr.size() ; i++){
        arr_sum += arr[i];
    }
    if(arr_sum == total_sum){
        return -1;
    }else{
        return total_sum - arr_sum;
    }
}

int xor_missing_element(vector<int> &arr , int n){
    int xor1 = 0;
    int xor2 = 0;
    for(int i=1;i<n+1;i++) xor1 ^= i;
    for(int i=0;i<arr.size();i++) xor2 ^= arr[i];
    return xor1^xor2;
}

int optimized_xor_missing_element(vector<int> &arr , int n){
    int xor1 = 0;
    int xor2 = 0;
    for(int i=0;i<arr.size();i++){
        xor1 ^= (i+1);
        xor2 ^= arr[i];
    }
    xor1 ^= n;
    return xor1^xor2;
}

// longest subarray whose sum is equal to k : video 20

int longest_subarray_sum(vector<int> arr , int k){
    int maxi = 0;
    int cnt = 0;
    int sum;
    for(int i=0;i<arr.size();i++){
        sum = arr[i];
        for(int j=i+1;j<arr.size();j++){
            if(sum>k){
                cnt++;
                break;
            }else if(sum<k){
                sum += arr[j];
                cnt++;
            }else{
                cnt++;
                maxi = max(cnt , maxi);
                cnt = 0;
                break;
            }
        }
    }
    return maxi;
}

int optimal_longest_subarray(vector<int> arr , int k){
    int maxi = 0;
    int size = arr.size();
    int cnt;
    int sum = 0;
    int i = 0;
    int j = 0;

    while(j<size){
        sum += arr[j];
        if(sum==k){
            cnt = j-i+1;
            maxi = max(cnt,maxi);
        }else if(sum > k){
            sum -= arr[i];
            i++;
        }
        j++;
    }
    return maxi;
}


// array of digits , add one and return the number

void plus_one(vector<int> &arr){
    int carry = 1;
    int size = arr.size();
    int i = size-1;
    while(i>0){
        int plus = arr[i] + carry;
        if(plus % 10 == 0){
            arr[i] = 0;
        }else{
            arr[i] = plus;
            break;
        }
        i--;
    }
    if(i==0&&arr[i]==9)arr[i] = 10;
}

// two sum

// returning bool value for whether two sum exist or not
bool two_sum(vector<int> arr , int sum){
    bool result = false;
    map<int , int> mp;
    for(auto it:arr){
        int diff = sum - it;
        mp[it]++;
        if(it != diff) mp[diff]++;
    }

    for(auto it : mp){
        if(it.second > 1){
            result = true;
            break;
        }
    }

    return result;
}

//returning indices if two sum exists
// vector<int> two_sum_indices(vector<int> arr , int sum){
//     vector<int> indicies;
//     map<int , int> mp;
//     for(int i = 0; i < arr.size(); i++){
//         mp[arr[i]] = i;
//     }
//     for(int i = 0 ; i < arr.size() ; i++){
//         int diff = sum - arr[i];
//         if(mp.find(diff) != mp.end()){
//             int index = mp[diff];
//             if(index != i){
//                 indicies.push_back(i);
//                 indicies.push_back(index);
//                 break;
//             }
//         }
//     }
//     return indicies;
// }

//better way to write the same
vector<int> two_sum_indices(vector<int> arr , int sum){
    vector<int> indicies;
    map<int , int> mp;
    for(int i = 0; i < arr.size(); i++){
        int diff = sum - arr[i];
        if(mp.find(diff) == mp.end()){
            mp[arr[i]] = i;
        }else{
            indicies.push_back(mp[diff]);
            indicies.push_back(i);
            break;
        }
    }
    return indicies;
}

// two pointer approach

string two_sum_pointer(vector<int> &arr , int target){
    int n = arr.size();
    int left = 0;
    int right = n-1;
    sort(arr.begin(),arr.end());
    while(left<right){
        int sum = arr[left]+arr[right];
        if(sum==target) return "YES";
        if(sum<target){
            left++;
        }else{
            right--;
        }
    }
    return "NO";
}

// sorting array containing 0,1,2
// brute force way will be to use any sorting algo
// better will be to count 0,1,2 and store them in a varibale , then run loops for all three from 0 to 2 , to replace the elements with the respective digit
// optimal way will be to use dutch national flag algo , use three pointer approach

void dutch(vector<int> &arr){
    int n = arr.size();
    int low = 0;
    int mid = 0;
    int high = n-1;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }else if(arr[mid]==1){
            mid++;
        }else if(arr[mid]==2){
            swap(arr[mid],arr[high]);
            high--;
        }
    }
}


int main(){
    vector<int> arr = {2,0,1}; // --> {1,0,2}
    dutch(arr);
    for(auto it:arr)cout<<it<<" ";
    return 0;
}