#include "headers.h"

class Node{
    public:
        int val;
        Node* next;
    Node(int val){
        this->val = val;
        this->next = nullptr;
    }

    ~Node(){}
};

void deleteAtPosi(Node* &head , int pos){
    
    if(pos==1){
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    int cnt = 1;
    Node* temp = head;
    while(cnt<pos-1){
        temp = temp->next;
        cnt++;
    }

    Node* tobeDel = temp->next;
    temp->next = tobeDel->next;
    delete tobeDel;
}

void insertAtHead(Node* &head , int d){
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &tail , int d){
    Node* temp = new Node(d);
    tail->next=temp;
    tail=temp;
}

void traverseLL(Node* &head){
    Node* temp = head;
    while(temp != nullptr){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<"END"<<" ";
}

void insertAtPosition(Node* &head , Node* &tail , int d , int pos){


    if(pos==1){
        insertAtHead(head,d);
        return;
    }

    Node* curr = head;
    int cnt = 1;
    while(cnt<pos-1){
        curr = curr->next;
        cnt++;
    }

    if(curr->next == nullptr){
        insertAtTail(tail,d);
        return;
    }

    Node* temp = new Node(d);
    temp->next = curr->next;
    curr->next = temp;
}

//recursion - Approach 1

void reverse(Node* &head , Node* &prev , Node* &curr){
    if(curr->next == nullptr){
        curr->next = prev;
        head = curr;
        return;
    }
    
    Node* opt = curr->next;
    curr->next = prev;
    reverse(head,curr,opt);
}

//recursion - Approach 2

Node* reverse_two(Node* &head){
    if(head==nullptr||head->next==nullptr){
        return head;
    }

    Node* head_opt = reverse_two(head->next);

    head->next->next = head;
    head->next = nullptr;

    return head_opt;
}

//reverse k nodes

Node* reverseK(Node* &head , int k){
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;
    int count = 0;

    while(curr != nullptr && count<k){
        next = curr->next;
        curr->next = prev;
        prev=curr;
        curr=next;
        count++;
    }

    if(next != nullptr){
        head->next = reverseK(next,k);
    }

    return prev;
}

// if ll is circular or not

int main(){
    Node* node1 = new Node(4);
    Node* head = node1;
    Node* tail = node1;
    // insertAtHead(head , 5);
    // insertAtHead(head , 6);
    // insertAtHead(head , 7);
    // insertAtHead(head , 8);
    // insertAtHead(head , 9);
    // insertAtHead(head , 10);
    insertAtTail(tail , 5);
    insertAtTail(tail , 7);
    insertAtTail(tail , 8);
    insertAtPosition(head,tail,11,3);
    insertAtPosition(head,tail,15,6);
    // cout<<tail->val<<" ";
    traverseLL(head);
    cout<<endl;
    // deleteAtPosi(head , 6);
    // traverseLL(head);
    // Node* curr = head;
    // Node* prev = nullptr;
    // reverse(head , prev , curr);
    // Node* ptr = reverse_two(head);
    // traverseLL(ptr);

    //reverse k nodes
    Node* newHead = reverseK(head,4);
    traverseLL(newHead);
    return 0;
}