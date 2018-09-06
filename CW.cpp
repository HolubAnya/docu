#include <iostream> 
#include <fstream>
#include <stdio.h>
#include <string>
using namespace std;

FILE * file = fopen("ingredients.txt", "r");
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

    string Find(const T& item, const T &category);

private:
    void Add(Node *&node, const T &elem);

    void DeleteSubTree(Node *node);
};

 class food{
    public:
        char name[40];
        char dish[40];
        char appetizer[40];
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
string Tree<T>::Find(const T &item, const T &catagory){
    food shop[100];
    Node *parent = NULL;
    Node *t = this->root;
    while (t != NULL){
        if (item == t->data){
            while (fscanf (file, "%s%s%s", shop->name, shop->dish, shop->appetizer)!= EOF){
                if (item == shop->name)
                    if (catagory == "main")
                        return shop->dish;
                    if (catagory == "appetizer")
                        return shop->appetizer;
            }
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


    int main(){
   
    Tree <string> tree;
    FILE * file = fopen("ingredients.txt", "r");
    food shop[10];
    while (fscanf (file, "%s%s%s", shop->name, shop->dish, shop->appetizer)!= EOF){
            tree.Add(shop->name);
    }
    //tree.Show(tree.getRoot());
    cout << "Find dish with beef:";  
    cout << endl;
    cout << tree.Find("beef", "main");
    cout << endl;    
    fclose(file);
    return 0;
}



