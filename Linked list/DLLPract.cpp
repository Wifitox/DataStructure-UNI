#include <iostream>

using namespace std;

class Node {
    public:
    int value;
    Node* next;
    Node*prev;

    Node(int value){
        this->value = value; 
        next = nullptr;
        prev = nullptr;
    }
};

class DoubleLinkeList {
    private:
    Node* head;
    Node* tail;
    int length;

    public:
    DoubleLinkeList(int value){
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }
    ~DoubleLinkeList() {
    Node* temp = head;
    while (head) {
        head = head->next;
        delete temp;
        temp = head;
    }
    tail = nullptr;
    length = 0;
    }

    void printList() {
    Node* temp = head;
        while(temp){
            cout << temp->value << endl;
            temp = temp->next;
        }
    }

    void printListReverse() {
    Node* temp = tail; 
    while (temp) {
        cout << temp->value << endl;
        temp = temp->prev; 
    }
    }

    void append(int value){
        Node* newNode = new Node(value);
        
        if(head == nullptr){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            newNode -> prev = tail;
            tail = newNode;
        }
        length++;
    }

    void deleteLast(){
        if(length == 0)return;
        Node *temp = tail;

        if (length == 1){
            head = nullptr;
            tail = nullptr;
        } else {
        tail = tail->prev;
        tail->next = nullptr;
        }
        delete temp;
        length--;
    }

    void prePend(int value){
        Node* newNode = new Node(value);
        if(head == nullptr){
            head = newNode;
            tail = newNode;
        } else {
            newNode -> next = head;
            head->prev = newNode;
            head = newNode;
        }
        length++;
    }

    void deleteFirst(){
        if(length == 0) return;
        Node* temp = head;
        if(length == 1){
            head = nullptr;
            tail = nullptr;
        } else {
            head = head -> next;
            head-> prev = nullptr;
        }
        delete temp;
        length--;
    }
    
    Node* get(int index){
        if(index < 0 || index >= length) return nullptr;
        Node* temp = head;
        if(index < length/2){
        for(int i = 0; i < index; i++){
            temp = temp->next;
        }
        } else{
            temp = tail;
            for(int i = length - 1; i > index; i--){
                temp = temp ->prev;
            }
        }
        return temp;
    }

    bool set(int index, int value) {
        Node* temp = get(index);
        if(temp){
            temp-> value = value;
            return true;
        }
        return false;
    }

    bool insert(int index, int value){
        if(index < 0 || index > length)return false;

        if(index == 0){
            prePend(value);
            return true;
        }
        if(index == length){
            append(value);
            return true;
        }
        
        Node* newNode = new Node(value);
        Node* before = get(index-1);
        Node* after = before->next;

        newNode->next = after;
        newNode->prev = before;
        before->next = newNode;
        after->prev = newNode;
        
        
        length++;
        return true;
    }

    void deleteNode(int index){
        if(index < 0 || index >= length) return;
        if(index == 0) {
            deleteFirst();
            return;
        }
        if(index == length - 1) {
            deleteLast();
            return;
        }

        Node* temp = get(index);
        Node* before = temp->prev;
        Node* after = temp->next;

        before->next = after;
        after->prev = before;

        delete temp;
        length--;

    }

};

int main(){

};
