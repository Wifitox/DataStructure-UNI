#include <iostream>
using namespace std;

class Node {
    public:
        int value;
        Node* next;

        Node(int value){
            this->value = value;
            next = nullptr;
        }
};

class LinkedList {
    private:
    Node* head;
    Node* tail;
    int length;

    public:
    LinkedList(int value){
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }
    ~LinkedList(){
        Node* temp = head;
        while(head){
            head = head -> next;
            delete temp;
            temp = head;
        }
    }

    void printList() {
    Node* temp = head;
        while(temp){
            cout << temp->value << endl;
            temp = temp->next;
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
            tail = newNode;
        }
        length++;
    }


    void prePend(int value){
        Node* newNode = new Node(value);

        if(head == nullptr){
            head = newNode;
            tail = newNode;
        } else {
            newNode -> next = head; // aqui enlazamos el nodo al que era antes el primer(head)
            head = newNode; // aqui ya cambiamos head a nuestro nuevo nodo
        }
        length++;
    }

    void deleteFirst(){
        if(length == 0)return;
        Node * temp = head;
        if (length == 1){
            head = nullptr;
            tail = nullptr;
        } else {
        head = head->next;
    }
    delete temp;
    length --;
    }

    void deleteLast(){
        if(length == 0)return;
        Node * temp = head;

        if (length == 1){
            head = nullptr;
            tail = nullptr;
        } else {
        Node *pre = head;
        while(temp->next){
            pre = temp;
            temp = temp->next;
        }
        tail = pre;
        tail->next = nullptr;
        }
        delete temp;
        length--;
    }

    Node* get(int index){
        if(index < 0 || index >= length){
            return nullptr;
        }
        Node * temp = head;
        for(int i = 0; i < index; i++){
            temp = temp->next;
        }
        return temp;
    }

    bool set(int index, int value){
        Node* temp = get(index);
        if(temp){
            temp-> value = value;
            return true;
        }
        return false;
    }

    bool insert(int index, int value){
        if (index < 0 || index > length) { // Si es indice invalido
        return false;
        }

        if (index == 0) { // Si es al inicio
            prePend(value);
            return true;
        }

        if(index == length){ // Para insertar justo despues del ultimo elemento existente
            append(value);
            return true;
        }
        // Para insertar en el medio
        Node* newNode = new Node(value);
        Node* temp = get(index-1); // Buscamos al nodo anterior y conseguimos su dirección de memoria

        newNode->next = temp->next; //Nuevo nodo apunta a al siguiente sabieno a que apuntaba el nodo anterior
        temp->next = newNode; // El anterior apunta al nuevo nodo

        length++;
        return true;

    }

    void deleteNode(int index){
        if (index < 0 || index >= length) return;
        if(index == 0) return deleteFirst();
        if(index == length - 1) return deleteLast();

        Node* prev = get(index-1); // Apuntamos al elemento previo del que borraremos
        Node* temp = prev->next; // Apuntamos al elemento a borrar
        
        prev->next = temp->next; // Apuntar el elemento anterior a donde apuntaba lo que borramos (enlazamos)

        delete temp; //eliminamos el que queriamos
        length--;
    }

    void reverse(){
        Node* temp = head;
        head = tail;
        tail = temp;

        Node* after = nullptr;
        Node* before = nullptr;

        for(int i = 0; i < length; i++){
            after = temp->next;
            temp->next = before;
            before = temp;
            temp = after;
        }

    }

};

int main(){
    
    LinkedList myLinkedList(1);
    myLinkedList.append(2);
    myLinkedList.printList();
}