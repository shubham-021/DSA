#include"headers.h"

// reversing the order of the words seperated by a space string in an array of characters
// brute force 

void reverse_order(vector<char> &s){
    int size = s.size();
    string helper = "";
    vector<string> helperArray;
    for(int i=0 ; i<size ; i++){
        if(s[i]==' '){
            helperArray.push_back(helper);
            helper = "";
            continue;
        }
        helper += s[i];
    }
    helperArray.push_back(helper);
    vector<char> answer;
    size = helperArray.size();
    while(size){
        helper = helperArray[size-1];
        int s = helper.length();
        for(int i=0 ; i<s ; i++){
            answer.push_back(helper[i]);
        }
        if(size!=1)answer.push_back(' ');
        size--;
    }

    for(auto it:answer)cout<<it<<" ";
}

// optimal
// char array as input

// void reverse_array(vector<char> &s , int start , int end){
//     int mid = (start+end)/2;
//     int i,j ;
//     if((end-start)%2==0){
//         i = mid-1;
//         j = mid;
//     }else{
//         i = mid;
//         j = mid;
//     }
//     while(i>=start && j<end){
//         swap(s[i],s[j]);
//         i--;
//         j++;
//     }
//     for(int i = start ; i<end ; i++)cout<<s[i];
// }

void reverse_array(vector<char> &s, int start, int end) {
    end--;
    while (start < end) {
        swap(s[start], s[end]);
        start++;
        end--;
    }
}

void optimal_reverse_order(vector<char> &s){
    int size = s.size();
    int i = 0;
    while(i<size){
        int start = i;
        int end = i;
        while(end<size && s[end] != ' '){
            end++;
        }
        // cout<<"start : "<<start<<" end : "<<end<<endl;
        reverse_array(s,start,end);
        i=end+1;
    }

    reverse_array(s,0,size);

    for(auto it:s)cout<<it;
}

// string as input

void reverse_string(string &s, int start, int end) {
    end--;
    while (start < end) {
        swap(s[start], s[end]);
        start++;
        end--;
    }
}

void reverse_order_string(string &s){
    int size = s.length();
    int i=0;
    while(i<size){
        if(s[i]!=' '){
            int start = i;
            int end = i;
            while(end<size && s[end] != ' '){
                end++;
            }
            // cout<<"start : "<<start<<" end : "<<end<<endl;
            reverse_string(s,start,end);
            i=end;
        }
        i++;
    }

    reverse_string(s,0,size);

    for(auto it:s)cout<<it;
}

// remove all occurences of substring 'abc'

// wrong
// void remove(string &s , int start , int end){
//     for (int i = end + 1; i < s.length(); ++i) {
//         s[start++] = s[i];
//     }

//     s.resize(s.length() - (end - start + 1));
// }

// void remove_substring(string &s , string &part){
//     int i=0;
//     int size = s.length();
//     while(i<size){
//         int j = 0;
//         int k=i;
//         bool found = false;
//         while(j<part.length()){
//             if(s[k]!=part[j]){
//                 found = false;
//                 break;
//             }else{
//                 found = true;
//                 j++;
//                 k++;
//             }
//         }
//         if(found){
//             int start = i;
//             int end = i + part.length() - 1;
//             remove(s , start , end);
//             i=0;
//         }else{
//             i++;
//         }
//     }
// }


int main(){
    // vector<char> s = {'t','h','e',' ','s','k','y',' ','i','s',' ','b','l','u','e'};
    // optimal_reverse_order(s);
    string s = "axxxxyyyyb";
    string part = "xy";
    // remove_substring(s,part);
    cout<<s<<endl;
    // reverse_array(s,11,15);
    return 0;
}