// #include <iostream>
// using namespace std;
// int j, mid, f1, f2, t;
// bool finish;
// int n = 6;
// int fib(int i)
// {
//     int *newArray = new int[n];

//     newArray[0] = newArray[1] = 1; 
     
//     int a = fib(i-1) + fib(i - 2);

//     return a;
// }

// int fibSearch(int key)
// {

// j=1;

// while (fib(j) <= n)

// j++;

// mid=n-fib(j-2)+ 1;	

// f1=fib(j - 2);

// f2=fib(j - 3);	

// finish=false;

// while (key != mid && !finish)

// {

// if (mid <= 0 || key > mid)

// {

// if (f1 == 1)

// finish=true;

// else

// {

// mid=mid + f2;

// f1 = f1 - f2;

// f2 = f2 - f1;
// }

// }
// else	

// {
// if (f2 == 0)	

// finish=true;

// else	

// {
// mid = mid - f2;

// t = f1 - f2;

// f1 = f2;

// f2 = t;

// }

// }



// return key;
// }
// }

// int main(){
//     int key1 = 5;
//     fibSearch(key1);
//     return 0;
// }


// int n = 10;
// int a[10] = {1, 2, 3, 4, 5, 6, 7, 8 ,9 ,10};
// int fib[10] = {1, 2, 3 ,5, 8, 13, 21, 34, 55, 89};

// int sfb (int key)
// {   
//     int i = 0;
//     while ( i <= n)
//     {
//         int f = fib[i];
//         if (a[f] < key)
//         {
//            i++;
//         }
//         if (a[f] == key)
//         {
//             cout << key << endl;
//             return key;
//         }
//         if (a[f] > key)
//         {
           
//             f = fib[i - 1];
//             sfb(key);
            
//         }
//     }
// }

// int main()
// {
//     sfb(2);
//     return 0;
// }

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
int rand (void);
int Fib(int i)
{
    if(i < 1) return 0;

    if(i == 1) return 1;

    return Fib(i-1) + Fib(i - 2);
}

// int SearchFib(int n, int arr[], int size, int key)
// {
//     int i = 0;
//     while(arr[Fib(i) + n]<= arr[key])
//         {
//             i++;
//         }
//     int f1 = Fib(i) + n;
//     int f2 = Fib(i-1) + n;
    
//     if(arr[f2] != arr[key])
//     {
//         if( f1 < size)
//         SearchFib(f2, arr, f1, key);
//         SearchFib(f2, arr, size, key);
        
    
//     }else{
//         return f2;
//     }
// }
    int i = Fib(10);
    int p = Fib(9);
    int q = Fib(8);
    int comparisons = 0;
int SearchFib(int arr[], int key, int n)
{   
    cout << comparisons << endl;
    if (arr[i] == key)
            return arr[i];

    
    if (arr[i] > key){
        comparisons++;
        if (q == 0)
        {
            cout << "Fault!";
            return 0;
        }else
        {
            i = i - q;
            int temp = p - q;
            p = q;
            q = temp;
            SearchFib(arr, key, n);
        }
    }
    
    if (arr[i] < key){
        comparisons++;
        if (p == 0)
        {
            cout << "Fault1!";
            return 0;
        }
        if (p != 0)
        {
            i = i + q;
            int temp = p - q;
            int tmp = q - p;
            p = temp;
            q = tmp;
            SearchFib(arr, key, n);
        }
    }
   
}
void Rand(int arr[], int size)
{
    arr[0] = 1;
    for(int i = 0; i < size; i++)
    {
        arr[i + 1] = arr[i] + rand() % 10;
    }
}

int main()
{
  
     int arr[100];
     Rand(arr, 100);
     for (int i = 0; i <= 100; i++)
     {
         cout << arr[i]<< ", ";
     }
     cout << endl;
    cout << SearchFib(arr, 17, 100);
     
}