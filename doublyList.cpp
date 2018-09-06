#include <iostream>
using namespace std;


template<typename T>
class List
{
public:
	List();
	~List();
    void pop_front();

    void push_back(T data);

    void clear();

    void ifClear();

    int GetSize() { return Size; }

    T& operator[](const int index);

	void push_front(T data);

    void insert(T data, int index);

    void removeAt(int index);

	void pop_back();

private:


	
	class Node
	{
	public:
		Node * pNext;
        Node * pPrev;
		T data;

		Node(T data, Node *pNext = NULL, Node *pPrev = NULL )
		{
			this->data = data;
			this->pNext = pNext;
            this->pPrev = pPrev;
		}
	};
	int Size;
	Node *head;
	Node *tail;
};


template<typename T>
List<T>::List()
{
	Size = 0;

	head = NULL;

	tail = NULL;
}


template<typename T>
List<T>::~List()
{
	clear();
}


template<typename T>
void List<T>::pop_front()
{
	Node *temp = head;

	head = head->pNext;

	delete temp;

	Size--;

}

template<typename T>
void List<T>::push_back(T data)
{
	if (head == NULL)
	{
		head = new Node(data);

		Size++;
	}
	else
	{
	    insert(data, Size);

	}

}

template<typename T>
void List<T>::clear()
{
	while (Size)
	{
		pop_front();
	}
}

template<typename T>
void List<T>::ifClear()
{
	bool clr = false;

	if (head == 0) clr = true;

	cout<<clr<<endl;
}


template<typename T>
T & List<T>::operator[](const int index)
{
	int counter = 0;

	Node *current = this->head;

	while (current != NULL)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}

template<typename T>
void List<T>::push_front(T data)
{
    Node *newNode = new Node(data, head);
   
    head = newNode;

	Size++;
}

template<typename T>
void List<T>::insert(T data, int index)
{

	if (index == 0)
	{
		push_front(data);
	}
	else if (index > Size)
	{
		cout << "Unvalid index" << endl;
	}
	else
	{
		Node *previous = this->head;

		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		Node *newNode = new Node(data, previous->pNext);

		previous->pNext = newNode;

		newNode->pPrev = previous;

		Size++;
	}





}

template<typename T>
void List<T>::removeAt(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else if(index > Size)
	{

     cout << "Unvalid index" << endl;
	}
	else
	{
		
		Node *current = this->head;

		for (int i = 0; i < index - 1; i++)
		{
			current = current->pNext;

		}
		
		Node *toDelete = current->pNext;

		current->pNext = toDelete->pNext;

		Node *next = this->head;

		if (toDelete->pNext) 
        toDelete->pNext->pPrev = toDelete->pPrev;
		
        delete toDelete;
		
		Size--;
	}

}

template<typename T>
void List<T>::pop_back()
{
	removeAt(Size - 1);
}

// void show(List<int> lst)
// {
	// 	for (int i = 0; i < lst.GetSize(); i++)
	// {
	// 	cout << lst[i] << endl;
	// }
// }


int main()
{

	setlocale(LC_ALL, "ru");


	List<int> lst;
	// lst.push_front(5);
	// lst.push_front(7);
	// lst.push_front(101);
	lst.push_back(102);
    lst.push_back(103);
    lst.push_back(103);
	//lst.insert(2,2);
	//show(lst);
		for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}
	//lst.pop_back();
	lst.removeAt(2);
	//lst.ifClear();
	//show(lst);
		for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}

	return 0;
}

