#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

class Node {
    public:
    int value;
    Node* left;
    Node* right;

    Node(int value, Node* left, Node* right){
        this->value = value;
        this->left = left;
        this->right = right;
    }
};

class BinarySearchTree {
    private:
    Node* root;

    void inorder(Node* n) const {
        if (n == nullptr) return;
        inorder(n->left);
        cout << n->value << " ";
        inorder(n->right);
    }

    int height(Node* n) const {
        if (n == nullptr) return -1;
        int hl = height(n->left);
        int hr = height(n->right);
        return 1 + max(hl, hr);
    }

    bool insert(Node*& n, int x) {
        if (n == nullptr) {
            n = new Node{x, nullptr, nullptr};
            return true;
        }
        if (x < n->value) return insert(n->left, x);
        if (x > n->value) return insert(n->right, x);
        return false;
    }

    void levelOrder(Node* n) const {
        if (n == nullptr) return;
        queue<Node*> q;
        q.push(n);
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            cout << curr->value << " ";
            if (curr->left)  q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
    }

    public:
    BinarySearchTree(){
        root = nullptr;
    }

    void inorder() const { inorder(root); }
    int height() const { return height(root); }
    bool insert(int x) { return insert(root, x); }
    void levelOrder() const { levelOrder(root); }
};

int main(){
    BinarySearchTree myBST;

    myBST.insert(50);
    myBST.insert(30);
    myBST.insert(70);
    myBST.insert(20);
    myBST.insert(40);
    cout << myBST.insert(30) << endl;   // 0 (repetido)

    cout << "Inorder: ";
    myBST.inorder();                    // 20 30 40 50 70
    cout << endl;

    cout << "Altura: " << myBST.height() << endl;   // 2

    cout << "Level order: ";
    myBST.levelOrder();                 // 50 30 70 20 40
    cout << endl;

    return 0;
}