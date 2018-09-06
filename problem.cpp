#include <iostream>
using namespace std;
#include "climits"
#include <string.h>



//функція, яка виводить масив на екран
void printArray(int arr[], int size){
    for (int i=0; i < size; i++)
        cout << arr[i] << ", ";
        cout << endl;
}

void printArray(string arr[], int size){
    for (int i=0; i < size; i++)
        cout << arr[i] << ", ";
        cout << endl;
}


//#13
// функція обміну елементів
void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

//#14

void pushElement(int *array, int &n, const int value){
    int *newArray = new int[n];
    n++;
    int j = 0;
    
     while (array[j] < value){
         newArray[j] = array[j];
         j++; 
     }
    
     newArray[j] = value;
    
     for (int i = j+1; i < n; i++){
         newArray[i] = array[i-1];
    }
     
}

// обираємо останній елемент як pivot
// порівнюємо елементи з pivot і залежно від цього поділяємо масив на дві частини
int partition (int arr[], int low, int high){
    int pivot = arr[high];    
    int i = low-1;  //i = -1 тому що поки жоден ел не стоїть на своєму місці
    for (int j = low; j <= high- 1; j++){
        if (arr[j] >= pivot){
            i++;   //i - змінна, значення якої відповідає індексу pivot (збільшується лише тоді, коли він знайшов своє місце)
            swap(&arr[i], &arr[j]); //обмін, який встановлює порівняний елемент у потрібне положення
        }
    }
    swap(&arr[i + 1], &arr[high]);  //обмін, який встановлює pivot у потрібне положення
    return (i + 1);
}
//  окремо сортуємо кожну частину масиву
// динамічно створюємо новий масив та записуємо в нього відсортовані елементи
void quickSort(int arr[], int low, int high){
    if (low < high){
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1); //окремо сортуємо обидві частини масиву
        quickSort(arr, pi + 1, high);
    }
      
}
 


void shellSortFromTheLowest(int A[], int n){
    int d = n/2;
    while (d > 0){
        for (int i = 0; i < n-d; i++){ 
        int j = i; 
            while (j >= 0 && A[j] > A[j+d]){ //  використовуючи цикл перебираємо всі елементи,
            // які стоять на відстані d = n/2 порівнюємо і якщо потрібно, переставляємо їх
                int count = A[j];
                A[j] = A[j+d]; 
                A[j+d] = count;
                j--;
            }
        }
    d = d/2; // знову зменшуємо d і повторюємо поки d>0
  }
    int *newArray = new int[n];
}



void shellSort(int A[], int n){
    int d = n/2;
    while (d > 0){
        for (int i = 0; i < n-d; i++){
            int j = i;
            while (j >= 0 && A[j] < A[j+d]){
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




//#16
int* FilterArray(int* arr, int n)
{
    int *newArray = new int[n]; //динамічно створюємо новий масив
    int j = 0;
    while (j < n)
    {
        for (int i = 0; i < n; i++)
        {                           //j відповідає за позицію значення у відфільтрованому масиві, i проходить по заданому
            if (arr[i] > 0){        //якщо значення масиву відповідає умові
                newArray[j] = arr[i]; //записуємо його в нивий масив
                j++;
      }
  }
    n = j;
    shellSortFromTheLowest(newArray, n); //сортуємо
    printArray(newArray, n); //виводимо на екран
    return newArray; //повертаємо новий масив
 
  }
}

//#17
int* creatingSort(int *array, int n)
{
    int *newArray = new int[n];     //динамічно створюємо новий масив
    for (int i = 0; i < n; i++)
        newArray[i] = array[i];     //записуємо значення в нивий масив
    
    shellSortFromTheLowest(newArray, n); //сортуємо
    printArray(newArray, n);    //виводимо на екран
    return newArray;    //повертаємо новий масив
}



//#21
int* absolute(int *array, int n)
{
    int *newArray = new int[n];   //динамічно створюємо новий масив
    for (int i = 0; i < n; i++)
    {
        if (array[i] <= 0)        //якщо значення масиву менше нуля
            newArray[i] = array[i]*(-1); //знаходимо його модуль і записуємо в нивий масив
        else
            newArray[i] = array[i]; //або записуємо значення в нивий масив
    }
    shellSortFromTheLowest(newArray, n); //сортуємо
    printArray(newArray, n);    //виводимо на екран
    return newArray;        //повертаємо новий масив

}



int main(){
    int n = 6;
    int arr[6] = {10, 7, 8, 9, 1, 5};
    int arr1[] = {1, 3, 5, 7, 9, 11};
    int arr2[] = {80, 64, -20, 1, -8, 32};
    string arr3[] = {"dfg", "sdk", "asd", "ffghjk", "asdf"};
     
    cout << "before:\n";
    //printArray(arr, n);
    printArray(arr2, n);
    

    cout << "after:\n";
    alphabeticOrder(arr3, n);
    // insertAverage(arr1, n);
    // printArray(arr1, n);
    //absolute(arr2, n);
    //author(arr3, n);
    //printArray(arr3, n);
    //FilterArray(arr2, n);
    //creatingSort(arr, n);
    
    return 0;
}
