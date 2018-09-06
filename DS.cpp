#include <iostream>
#include <cassert>
//#include "List.cpp"
#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <limits.h>
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

    void Task1(const T &elem, Node* current);

    void Task2(Node* current);

    void Task3(const T &elem, Node* current);

    void Task4(const T &elem, Node* current);

    void Task5(int num, ...);

    void Task6(Node* current);

    void Task7(Node* current);

    void Task8(const T &elem, const T &elem2, Node* current);

    void Task9(const T &elem, Node* current);

    void Task10(const T &elem, Node* current);

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
class ListGraph;

template<class T>
class List 
{
    struct Node
    {
        T data;
        T weight;
        Node *next;

        Node(const T &d, const T &w, Node *n = NULL)
        {
            data = d;
            weight = w;
            next = n;
        }
    };
    Node *first, *last;
    int count;
public:
    List()
    {
        first = last = NULL;
        count = 0;
    }
    ~List();
    void Push(const T &, const T &w);
    int getWeight(int to)
    {
        Node *node = Iterate(to);
        return node->weight;
    }
    bool Have(const T &) const;
    void remove(const T &data);
    int*  adjacent();
    Node * Iterate(const T &data)
    {
        Node *node = this->first;
        while (node)
        {
            if (node->data == data)
                return node;
            node = node->next;
        }
        return NULL;
    }

    Node * Before(const T &data)
    {
        Node *node = this->first;
        while (node)
        {
            if (node->next->data == data)
                return node;
            node = node->next;
        }
    }
};

template<class T>
List<T>::~List()
{
    Node *temp = first;
	first = first->next;
	delete temp;
	count--;
}

template<class T>
void List<T>::Push(const T &data, const T &w)
{
    Node *newNode = new Node(data, w);
    if (last)
        last->next = newNode;
    else
        first = newNode;
    last = newNode;
    count++;
}

template<class T>
bool List<T>::Have(const T &data) const
{
    for(Node *current = first; current; current = current->next)
    {
        if (current->data == data)
        return true;
    }
    return false;
}

template<typename T>
void List<T>::remove(const T &data)
{
    Node *node = Iterate(data);
    if (node == NULL)
        cout << "Misstake" << endl;
	if (first == node)
	{
		Node *temp = first;
	    first = first->next;
	    delete temp;
	    count--;
    }
	else
	{
		Node *previous = Before(data);
        previous->next = node->next;
		delete node;
		count--;
	}
    
}


template<typename T>
int* List<T>::adjacent()
{
    Node *node = this->first;
    int *newArray = new int[count];
    for (int i = 0; i < count; i++)
    {
        if (!node) break;
        newArray[i] = node->data;
        node = node->next;
    }
  
    return newArray;
   
}
class Graph
{
private:
    List<int> *graph;
    int number;
public:
    Graph(int n) : number(n), graph(new List<int>[n]) {}
    ~Graph(){}

    int Count() const{return number;}
    void Add(int from, int to, int w);
    bool Has(int from, int to) const;
    void Remove(int from, int to);
    int Daykestra(int from, int to);
    int* Adjacent(int from);
    int GetWeight(int from, int to);
    int Path(int from, int to, int Weight);
    int Num(int arr[]);
    int FindAdjacent(int i, int a,int weight, int to);
  
};

void Graph::Add(int from, int to, int w)
{
    if (from < 0 || from > number || to < 0 || to > number)
        return;
    graph[from].Push(to, w);
}

void Graph::Remove(int from, int to)
{
    if (from < 0 || from > number || to < 0 || to > number)
        return;
    graph[from].remove(to);
}

bool Graph::Has(int from, int to) const 
{
    if (from < 0 || from > number || to < 0 || to > number)
        return false;
    graph[from].Have(to);
}

int* Graph::Adjacent(int from) 
{
    if (from < 0 || from > number)
        return 0;
    int *arr = new int[2];
    arr = graph[from].adjacent();
    return arr;
}

int Graph::GetWeight(int from, int to)
{
    
    if (from < 0 || from > number || to < 0 || to > number)
        return 0;
    return graph[from].getWeight(to);
}
int Graph::Num(int arr[])
{
    int i = 0;
    while (arr[i] != 0)
        i++;
    return i;
}
void shellSort(int A[], int n){
    int d = n/2;
    while (d > 0){
        for (int i = 0; i < n-d; i++){ 
        int j = i; 
            while (j >= 0 && A[j] > A[j+d]){ 
                int count = A[j];
                A[j] = A[j+d]; 
                A[j+d] = count;
                j--;
            }
        }
    d = d/2; 
  }
    int *newArray = new int[n];
}

int Graph::Daykestra(int from, int to)
{
    int *arr = new int[number];
    int *NewArr = new int[Num(arr)];
    arr = Adjacent(from);
    int weight = 0;
    if (Has(from, to))
        return weight = GetWeight(from, to);
    else
    {
        int weight1 = Path(from, to, 0);
        int i, j, weight2;
        i = 0;
        while (i < Num(arr))
        {   
            weight2 = Path(arr[i], to, GetWeight(from, arr[i]));
            if (weight2 != 0)
            {
                NewArr[i] = weight2;
            }
            else
                NewArr[i] = std::numeric_limits<int>::max();
 
            i++;                     

        }
        if (weight == 0 && weight1 == 0 && NewArr[0] == 0)
            return 0;
        shellSort(NewArr, Num(NewArr));
        if (weight1 < NewArr[0])
            return weight1;
        else 
            return NewArr[0];
        
    }
   
}

int Graph::Path(int from, int to, int weight)
{
    
    int *arr = new int[number];
    int *NewArr = new int[number];
    arr = Adjacent(from);
    int j = 0;
    for (int i = 0; i < Num(arr); i++)
    {
        if (Has(arr[i], to))
        {
            int weight1 = weight + GetWeight(from, arr[i]) + GetWeight(arr[i], to);
            NewArr[j] = weight1;
            //cout << NewArr[j] << endl;
            j++;
            
        }
    }
    

    shellSort(NewArr, Num(NewArr));
    //cout << NewArr[0] << endl;
    return NewArr[0];

}




int main()
{
    
    Graph graph1(12);
    graph1.Add(1, 2, 3);
    graph1.Add(3, 4, 1);
    graph1.Add(1, 3, 3);
    graph1.Add(3, 5, 2);
    graph1.Add(4, 5, 8);
    graph1.Add(2, 5, 7);
    //graph1.Path(1, 5, 0);
    //cout << graph1.Daykestra(1, 4);
    assert(graph1.Has(1,2) == 1);
    assert(graph1.Daykestra(1, 4) == 4);
    assert(graph1.Daykestra(1, 8) == 0);
   
    graph1.Remove(3, 5);
    assert(graph1.Has(2, 1) == 0);
    assert(graph1.Has(3, 5) == 0);
    return 0;
}