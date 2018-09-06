
#include <iostream>

using namespace std;

template <class T>
class Tree 
{
    class Node 
    {
    public:
        T data;
        Node *left;
        Node *right;


        Node(T i, Node *l = NULL, Node *r = NULL)
        {
            data = i;
            left = l;
            right = r;
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

    Tree<T> Filter(Node *node);

    Node * Iterator(const T &data)
    {
        Node *node = this->root;
        while (node != NULL)
        {
            if (node->data == data)
                return node;

            else if (node->data < data)
                node = node->right;

            else 
            node = node->left;
        }
    }


    Node * Define(const T &data)
    {
        Node *node = Iterator(data);
        node = node->right;
        if (node->left)
        {
            while (node->left)
                node = node->left;
        }
        return node;
    }
    Node * findParent(const T &data)
    {
        Node *parent = NULL;
        Node *t = this->root;
        while (t != NULL)
        {
            if (data == t->data)
            {
                if (t == root)
                    return NULL;
                return parent;
            }
            else {
                parent = t;
                if (data < t->data)
                    t = t->left;
                else
                    t = t->right;
        }
        
    }
}

    bool ifNegative(Node *node);

    void Remove(const T &data);
    
    Tree<T> Filter2(Node *node);

    Node * getRoot() {return root;}

    void DeleteWithBoth(Node *node, Node *parent);

    void DeleteSubTree(Node *node);

    
private:
    void Add(Node *&node, const T &elem);
};

template <class T>
Tree<T>::Tree()
{
    root = NULL;
    size = 0;
}

template <class T>
Tree<T>::~Tree()
{
    DeleteSubTree(root);
}

template <class T> 
void Tree<T>::DeleteSubTree(Node *node)
    {
        if (node)
        {
            DeleteSubTree(node->left);
            DeleteSubTree(node->right);
            delete node;
        }
    }

template <class T> 
void Tree<T>::Add(Node *&node, const T &data)
    {   
        if (node == NULL)
            node = new Node(data);

        else if(data < node->data)
            Add(node->left, data);

        else
            Add(node->right, data);
        
    
    }

template <class T> 
void Tree<T>::Show(Node *node)
{
     if (!node)    return;   
   
    Show(node->left);
    cout<<node->data<< ", ";
    Show(node->right);
}



template <class T> 
bool Tree<T>::ifNegative(Node *node)
{
    bool result = true;
    if(!node) return result;
    
    if(node->data > 0){result = false;}
    bool next;
    next = ifNegative(node->left);
    if(next == false) {result = false;}

    next = ifNegative(node->right);
    if(next == false) {result = false;}

    return result;
}

template <class T> 
void Tree<T>::Remove(const T &data)
{
    Node *node = Iterator(data);
    Node *parent = findParent(data);
    if (node == this->root)
        {                                       //видалення кореня
        Node *definedNode = Define(data);        //обираємо ноду, яку слід перемістити на місце кореня
        Node *parent2 = findParent(definedNode->data);//знаходимо її батька
        if (definedNode != node->right) //якщо обрана нода - крайній лівий нащадок
        {
            definedNode->right = node->right;  //встановлюємо посилання на праве піддерево
            parent2->left = NULL;  //прибираємо посилання на обрану ноду
        }else{//в іншому випадку
            if (!definedNode->right) // якщо у обраної ноди немає нащадків
                parent2->right = NULL; //прибираємо посилання
            else 
                root->right = definedNode->right; //або спрямовуємо його на наступний правий елемент
        }
        definedNode->left = node->left; //встановлюємо посилання на ліве піддерево
        Show(definedNode);
        delete node; //видаляємо ноду
        }
    if(!node->left && !node->right) //1 випадок (листок)
    {   
        if (parent->left == node) //прибираємо посилання на ноду у її батька
            parent->left = NULL;
        if (parent->right == node)
            parent->right = NULL;   
        delete node; //видаляємо ноду
    } 
    if (node->left && node->right && node != this->root)  //2  випадок (два нащадки)
        DeleteWithBoth(node, parent);
        
    if (node->right && !node->left)  //3 випадок (1 нащадок)
    {
        if (parent->left == node) //прибираємо посилання на ноду у її батька
            parent->left = NULL;
        if (parent->right == node)           
            parent->right = node->right;  //перенаправляємо посилання на нащадка ноди
        delete node;    //видаляємо ноду
    
    }
    
    if (node->left && !node->right) //3 випадок (1 нащадок)
    {
        if (parent->left == node)
            parent->left = node->left;  //перенаправляємо посилання на нащадка ноди
        if (parent->right == node)
            parent->right = NULL;  //прибираємо посилання на ноду у її батька
        delete node;    //видаляємо ноду
        
    }
    
  size--;
}

template <class T> 
void Tree<T>::DeleteWithBoth(Node *node, Node *parent) //2  випадок (два нащадки)
{
    Node *definedNode = Define(node->data); //обираємо ноду, яку слід перемістити
    Node *parent2 = findParent(definedNode->data);//знаходимо її батька
        if (parent->left == node)   //встановлюємо посилання на обрану ноду у батька ноди, яку видаляємо
            parent->left = definedNode;
        if (parent->right == node)
            parent->right = definedNode;
        if (parent2->left == definedNode) //прибираємо посилання на обрану ноду у її батька
            parent2->left = NULL;
        if (parent2->right == definedNode)
            parent2->right = definedNode->right;
        definedNode->left = node->left;
        definedNode->right = node->right;
        
}



template <class T> 
Tree<T> Tree<T>::Filter(Node * node)
{
  
     Tree<int> anotherTree;
        if (!node) return anotherTree;
        
        if (node->data < 0)
            anotherTree.Add(node->data);

        if (node->right)
            Filter(node->right);

        if (node->left)
            Filter(node->left);
    
  anotherTree.Show(anotherTree.getRoot());
}






