#include"headers.h"

// finding the largest in an array

int largest_in_array(vector<int> &arr){
    int size = arr.size();
    int largest = -1;
    for(int i = 0 ; i <size ; i++){
        if(arr[i] > largest) largest = arr[i];
    }
    return largest;
}

// finding second largest in an array

int second_largest_in_array(vector<int> &arr){
    int size = arr.size();
    int largest = arr[0];
    int second_largest = -1;
    for(int i = 1 ; i <size ; i++){
        if(arr[i] > largest){
            second_largest = largest;
            largest = arr[i];
        }else if(arr[i] != largest && arr[i] > second_largest) second_largest = arr[i];
    }
    return second_largest;
}

// checking if array is sorted or not

bool is_sorted(vector<int> arr){
    int size = arr.size();
    bool flag = true;
    for(int i = 1 ; i < size ; i++){
        if(arr[i] < arr[i-1]){
            flag = false;
            break;
        }
    }

    return flag;
}

// remove duplicate elements from array

int remove_dup(vector<int> &arr){
    int size = arr.size();
    int i = 0;
    for(int j = i+1 ; j<size; j++){
        if(arr[i] != arr[j]){
            arr[i+1] = arr[j];
            i++;
        }
    }
    return i+1;
}

// rotate array by d places

void rotate_array(vector<int> &arr, int d){
    int size = arr.size();
    int rotate_by = d % size ;

    if(rotate_by != 0){
        vector<int> removed(d);
        for(int i = 0 ; i<rotate_by ; i++) removed[i] = arr[i];

        for(int j = rotate_by; j < size; j++){
            int to_replace = j - rotate_by;
            arr[to_replace] = arr[to_replace + rotate_by];
        }

        for(int k = 0 ; k < rotate_by ; k++){
            arr[size-rotate_by+k] = removed[k];
        }
    }
}

// optimal rotate array by d places , optimal as it uses no extra space 

void reverse_array(vector<int> &arr , int low , int high){
    int mid = ( low + high ) / 2 ;
    int i = low;
    int j = high;

    while(i < j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
}

void optimal_rotate_array(vector<int> &arr , int d){
    int size = arr.size();
    d = d % size ;
    reverse_array(arr,0,d-1);
    reverse_array(arr,d,size-1);
    reverse_array(arr,0,size-1);
}

// moving zeroes to the end of an array

void moving_zeroes(vector<int> &arr){
    int size = arr.size();
    int j = 0;
    for(int i = 0; i<size ; i++){
        if(arr[i] != 0){
            swap(arr[j] , arr[i]);
            j++;
        }
    }
}

// Union of two sorted array 

vector<int> union_sorted_array(vector<int>arr1 , vector<int> arr2){
    vector<int> final;
    set<int> st;
    int size1 = arr1.size();
    int size2 = arr2.size();
    for(int i=0;i<size1;i++){
        st.insert(arr1[i]);
    }

    for(int i=0;i<size2;i++){
        st.insert(arr2[i]);
    }

    int total_Size = size1 + size2;
    for(auto it : st)final.push_back(it);
    
    return final;
}

// Optimal way for union of two array

vector<int> optimal_union_sorted_array(vector<int>arr1 , vector<int> arr2){
    vector<int> final;
    int size1 = arr1.size();
    int size2 = arr2.size();
    int i,j = 0;
    int recent_pushed = 0;
    
    while(i<size1 && j<size2){
        if(arr1[i]<=arr2[j]){
            if(arr1[i] != recent_pushed){
                final.push_back(arr1[i]);
                recent_pushed = arr1[i];
                i++;
            }else{
                i++;
            }
        }else{
            if(arr2[j]!=recent_pushed){
                final.push_back(arr2[j]);
                recent_pushed = arr1[j];
                j++;
            }else{
                j++;
            }
        }
    }

    while(i<size1){
        if(arr1[i] != recent_pushed){
            final.push_back(arr1[i]);
            recent_pushed = arr1[i];
            i++;
        }else{
            i++;
        }
    }

    while(j<size2){
        if(arr2[j]!=recent_pushed){
            final.push_back(arr2[j]);
            recent_pushed = arr1[j];
            j++;
        }else{
            j++;
        }
    }

    return final;
}

// Intersection of two sorted arrays (unique elements)

vector<int> intersection_of_arrays_unique(vector<int>arr1 , vector<int>arr2){
    int n1 = arr1.size();
    int n2 = arr2.size();
    set<int> st;
    vector<int> final;

    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            if(arr1[i]==arr2[j]) st.insert(arr1[i]);
        }
    }

    for(auto it:st)final.push_back(it);

    return final;
}

// Intersection of two sorted arrays (repeated values)

vector<int> intersection_of_arrays_repeated(vector<int>arr1 , vector<int>arr2){
    vector<int> final;
    int n1 = arr1.size();
    int n2 = arr2.size();
    vector<int> visited(n2 , 0);

    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            if(arr1[i]==arr2[j] && visited[j] != 1){
                final.push_back(arr1[i]);
                visited[j] = 1;
                break;
            }
            if(arr1[i]<arr2[j])break;
        }
    }

    return final;
}

// Optimal way of intersection for two sorted arrays (repeated values)
vector<int> optimal_intersection_of_arrays_repeated(vector<int> arr1 , vector<int> arr2){
    vector<int> final;
    int n1 = arr1.size();
    int n2 = arr2.size();
    int i = 0;
    int j = 0;

    while(i<n1 && j<n2){
        if(arr1[i]==arr2[j]){
            final.push_back(arr1[i]);
            i++;
            j++;
        }else{
            if(arr1[i]<arr2[j]){
                i++;
            }else{
                j++;
            }
        }
    }

    return final;

}

int main(){
    vector<int> arr1 = {1,1,5,7,9,9,20,20};
    vector<int> arr2 = {1,1,7,9,20,20};
    vector<int> arr = optimal_intersection_of_arrays_repeated(arr1 , arr2);
    for(auto it : arr)cout<<it<<" ";
    return 0;
}