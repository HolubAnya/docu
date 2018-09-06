#include <iostream>
using namespace std;
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
    bool Have(const T &) const;
    void remove(const T &data);
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
