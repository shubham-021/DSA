#include "headers.h"

class Stack{

    int top;
    int size;
    int* arr;

    public:
        Stack(int size){
            this->top = -1;
            this->size = size;
            this->arr = new int[size];
        }

        void push(int d){
            if(size-top>1){
                top++;
                arr[top] = d;
            }else{
                cout<<"Stack overflow";
            }
        }

        void peek(){
            if(top>-1){
                cout<<arr[top];
            }else{
                cout<<"Stack is empty";
            }
        }

        void pop(){
            if(top<0){
                cout<<"Stack underflow";
            }else{
                cout<<arr[top];
                top--;
            }
        }

        bool isEmpty(){
            if(top==-1){
                return true;
            }
            return false;
        }

        // void print(){
        //     for(auto it:arr){

        //     }
        // }
};

class TwoStack{

};

int main(){
    Stack st(4);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    // st.push(5);
    st.pop();

    return 0;
}