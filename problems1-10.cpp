#include "tree.cpp"

template <class T>
void Tree<T>::Task1(const T &elem, Node* current)
{

    if (current == NULL) return; 
	Task1(elem, current->left); //обхід дерева
	Task1(elem, current->right);
	if ((current->data % elem) == 0) Remove(current->data); //видалення нащадка, за умови 
    return;
}

template <class T>
void Tree<T>::Task2(Node* current)
{
    if (current == NULL) 
        return; 
	Task2(current->left); //обхід дерева
	Task2(current->right);
	if ((current->data % 2) != 0) //видалення нащадка, якщо його поле data націло ділиться на 2
        Remove(current->data); 
    return;
}

template <class T>
void Tree<T>::Task3(const T &elem, Node* current)
{
    if (current == NULL) 
        return; 
	Task3(elem, current->left); //обхід дерева
	Task3(elem, current->right);
	if (current->data > elem) //видалення нащадка, якщо його поле data більше заданого значення
        Remove(current->data); 
    return;
}

template <class T>
void Tree<T>::Task4(const T &elem, Node* current)
{
    if (current == NULL) 
        return; 
	Task4(elem, current->left); //обхід дерева
	Task4(elem, current->right);
	if (current->data < elem) 
        Remove(current->data); //видалення нащадка, якщо його поле data менше заданого значення
    return;
}

template <class T>
void Tree<T>::Task5(int num, ...)
{
    Node* node;
    va_list args; //видалення нащадка, якщо його поле data відповідає заданому значенню
	va_start(args, num);
	while (num--)
    {
		Remove(va_arg(args, T));
	}
    va_end(args);
}

template <class T>
void Tree<T>::Task6(Node* current)
{
    if (current == NULL) 
        return; 
	Task6(current->left); //обхід дерева
	Task6(current->right);
	bool flag = false;
	for (int i = 2; i < current->data - 1; i++) //видалення нащадка, якщо його поле data є простим числом
    {
		if ((current->data % i) == 0) //Remove(current->data);
        flag = true;
	}
    if (flag) Remove(current->data); 
        return;
}

template <class T>
void Tree<T>::Task7(Node* current)
{
    if (current == NULL) 
        return; 
	Task7(current->left); //обхід дерева
	Task7(current->right);
	bool flag = false;
	for (int i = 2; i < current->data - 1; i++)
    {
		if ((current->data % i) != 0) //Remove(current->data);
        flag = true;
	}
    if (flag) Remove(current->data); //видалення нащадка, якщо його поле data є складним числом
        return;
}


template <class T>
void Tree<T>::Task8(const T &elem, const T &elem2,Node* current)
{
    if (current == NULL) return;

	Task8(elem, elem2, current->left);
	Task8(elem, elem2, current->right); 
	if (current->data < elem2 && current->data > elem) Remove(current->data);
    return; //видалення нащадка, якщо його поле data належить інтервалу
}

template <class T>
void Tree<T>::Task9(const T &elem, Node* current)
{
    if (current == NULL) 
        return; 
	Task9(elem, current->left); 
	Task9(elem, current->right);
	
    char intStr[3];
    sprintf(intStr, "%d", current->data);
    int digit = 0;
    int sum = 0;
	for (int i = 0; i < 3; i++)
	{
		digit = (int)intStr[i] - (int)'0';
        sum = sum + digit;  
        if (sum < elem) //видалення нащадка, якщо його поле data менше суми цифр елементів
            Remove(current->data);
	}
    return;
}

template <class T>
void Tree<T>::Task10(const T &elem, Node* current)
{
    if (current == NULL) 
        return; 
	Task9(elem, current->left); 
	Task9(elem, current->right);
	
    char intStr[3];
    sprintf(intStr, "%d", current->data);
    int digit = 0;
    int sum = 0;
	for (int i = 0; i < 3; i++)
	{
		digit = (int)intStr[i] - (int)'0';
        sum = sum + digit;
        if (sum > elem)  //видалення нащадка, якщо його поле data більше суми цифр елементів
            Remove(current->data);
	}
    return;
}
// string NumberToString ( int Number )
//   {
//      std::ostringstream ss;
//      ss << Number;
//      return ss.str();
//   }