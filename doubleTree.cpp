#include <iostream> 
#include <fstream>
#include <stdio.h>
#include <string>
using namespace std;

template <class T>
class Tree {
    class Node {
    public:
        T data;
        Node *left;
        Node *right;
        Node *parent;
        Node(T i, Node *p  = NULL, Node *l = NULL, Node *r = NULL){
            data = i;
            left = l;
            right = r;
            parent = p;
            
        }
    };
    Node *root;
    int size;

public:
    Tree();
    ~Tree();

    void Add(const T &elem){
        Add(root, elem);
        size++;
    }
    
    void Show(Node *node);

    Node * getRoot() { return root; }

    string Find(const T& item);

private:
    void Add(Node *&node, const T &elem);

    void DeleteSubTree(Node *node);
};

    

template <class T>
Tree<T>::Tree(){
    root = NULL;
    size = 0;
}

template <class T>
Tree<T>::~Tree(){
    DeleteSubTree(root);
}

template <class T> 
void Tree<T>::DeleteSubTree(Node *node){
        if (node){
            DeleteSubTree(node->left);
            DeleteSubTree(node->right);
            delete node;
        }
    }

template <class T> 
void Tree<T>::Add(Node *&node, const T &data){   
        if (node == NULL)
            node = new Node(data);

        else if(data < node->data)
            Add(node->left, data);

        else
            Add(node->right, data);
        
    }


template <class T>
string Tree<T>::Find(const T &item){
    Node *parent = NULL;
    Node *t = this->root;
    while (t != NULL){
        if (item == t->data){
            return t->data;
        } else {
            parent = t;
            if (item < t->data)
                t = t->left;
            else
                t = t->right;
        }
    }
    return 0;
}

template <class T> 
void Tree<T>::Show(Node *node){
    if (!node)    return;   
   
    Show(node->left);
    cout<<node->data<< ", " << endl;
    Show(node->right);
 
}
