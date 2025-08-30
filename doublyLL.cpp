#include "headers.h"


class Node{
    public:
        int val;
        Node* prev;
        Node* next;

    Node(int val){
        this->val = val;
        this->next = nullptr;
        this->prev = nullptr;
    }

    ~Node(){}
};

void insertAtHead(Node* &head , int d){
    Node* temp = new Node(d);
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insertAtTail(Node* &head , int d){
    // Node* toBe = new Node(d);
    // if(head->next == nullptr){
    //     head->next = toBe;
    //     toBe->prev=head;
    // }

    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }

    Node* toBe = new Node(d);
    temp->next = toBe;
    toBe->prev = temp;
}

void insertAtPos(Node* &head, int pos , int d){
    if(pos == 1){
        insertAtHead(head , d);
        return;
    }

    int cnt = 1;
    Node* temp = head;
    while(cnt<pos-1 && temp != nullptr){
        temp = temp->next;
        cnt++;
    }

    if(temp==nullptr){
        cout<<"Invalid posi"<<endl;
        return;
    }

    if(temp->next == nullptr){
        insertAtTail(head,d);
        return;
    }

    Node* toBe = new Node(d);
    toBe->next = temp->next;
    temp->next->prev = toBe;
    toBe->prev = temp;
    temp->next = toBe;
}

void deleteAtPos(Node* &head , int pos){
    Node* temp = head;
    if(pos==1){
        head = head->next;
        delete temp;
        return;
    }

    int cnt = 1;
    while(cnt<pos-1){
        temp = temp -> next;
        cnt++;
    }
    Node* del = temp->next;

    if(del->next == nullptr){
        temp->next=nullptr;
        delete del;
        return;
    }

    temp->next = del->next;
    del->next->prev = temp;
    del->next = nullptr;
    delete del;
}

void printLL(Node* &head){
    if(head->next == nullptr){
        cout<<head->val<<" "<<"End";
        return;
    }

    Node* temp = head;
    while(temp != nullptr){
        cout<<temp->val<<" ";
        temp = temp -> next;
    }
    cout<<"End"<<endl;
}

void printReverse(Node* &head){
    if(head==nullptr){
        return;
    }
    Node* temp = head;
    printReverse(temp->next);
    cout<<temp->val<<" ";
}

int main(){
    Node* head = new Node(5);
    insertAtHead(head , 10);
    insertAtHead(head , 20);
    insertAtHead(head , 3);
    // printLL(head);
    // insertAtTail(head , 59);
    // insertAtTail(head , 21);
    // insertAtTail(head , 23);
    insertAtHead(head , 0);
    insertAtPos(head,2,15);
    insertAtPos(head,7,25);
    insertAtPos(head,4,90);
    printLL(head);
    deleteAtPos(head , 3);
    printLL(head);
    deleteAtPos(head , 1);
    printLL(head);
    deleteAtPos(head , 6);
    printLL(head);
    printReverse(head);
    // printReverse(head); 
    return 0;
}