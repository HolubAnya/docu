#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdio.h>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

class Block
{
public:
    Block()
    {
        i = x = 0;
    }
    Block(int i,int x)
    {
        this->i = i;
        this->x = x;
    }
    int i;
    int x;
    void Print()
    {
       cout << x << ", " << i << endl;
    }
};

int FindBlock(int x, int n)
{
    int block = x/n;
    return block;
}


void Add(int size)
{
    ofstream fout;
    Block block;
    char intStr[11];
    while (block.i < 10000)
    {
        Block block1(block.i, rand()% 10000);
        sprintf(intStr, "%d", FindBlock(block1.x, size));
        fout.open(intStr, ofstream::app);
        if (fout.is_open())
            fout.write((char*)&block1, sizeof(Block));
        fout.close();
        block.i++;
    }
    
}

void MakeBase()
{
    Block blk;
    ifstream fin;
    ofstream fout;
    char intStr[11];
    for (int i = 0; i < 17; i++)
    {
        sprintf(intStr, "%d", i);
        fin.open(intStr);
        fin.read((char*)&blk, sizeof(Block));
        fin.close();
        Block block(i, blk.x);
        fout.open("base");
        fout.write((char*)&block, sizeof(Block));
        fout.close();
    }
    
}

int SizeOfBlock(int n)
{
    char intStr[11];
    Block blk;
    int i = 0;
    ifstream fin;
    sprintf(intStr, "%d", n);
    fin.open(intStr);
    while(fin.read((char*)&blk, sizeof(Block)))
        i++;
    return i;
    fin.close();
}

void Rebuild()
{
    int i = 0;
    while (SizeOfBlock(i) == SizeOfBlock(i+1))
      i++;
    
    if (i < 15)
      {
          Add(SizeOfBlock(i));
          MakeBase();
      }
    else
      cout << "Ok";
}

int BinSearch(const int* arr, int count, int key) 
{
  int l = 0;           
  int u = count - 1;    
 
  while (l <= u) {
    int m = (l + u) / 2;
    if (arr[m] == key) return m;
    if (arr[m] < key) l = m + 1;
    if (arr[m] > key) u = m - 1;
  }
  return -1;
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

bool remove_line(const char *filename, size_t index)
{
    std::vector<std::string> vec;
    std::ifstream file(filename);
    if (file.is_open())
    {
        std::string str;
        while (std::getline(file, str))
            vec.push_back(str);
        file.close();
        if (vec.size() < index)
            return false;
        vec.erase(vec.begin() + index);
        std::ofstream outfile(filename);
        if (outfile.is_open())
        {
            std::copy(vec.begin(), vec.end(), 
                std::ostream_iterator<std::string>(outfile, "\n"));
            outfile.close();
            return true;
        }
        return true;
    }
    return true;
}

int AddElem(int x, int size)
{
    ifstream fin;
    int y = 0;
    Block blk, blck; 
    char intStr[11];
    int newArray[590] = {};
    sprintf(intStr, "%d", FindBlock(x, size));
    fin.open(intStr);
    int J = 0;
    if (fin.is_open())
    {
        while (fin.read((char*)&blk, sizeof(Block)))
        {
            newArray[J] = blk.x;
            J++;
            
        }
        newArray[size] = x;
    }
    shellSort(newArray, size+1);
    fin.close();
    while (blck.i <= size)
    {
        ofstream fout;
        Block block (rand()% 10000, newArray[blck.i]);
        fout.open(intStr, ofstream::app);
        if (fout.is_open())
            fout.write((char*)&block, sizeof(Block));
        fout.close();
        blck.i++;
    }
    
    return x;

}

int Search(int x)
{
    ifstream fin;
    Block blk;
    char intStr[11];
    int size = 589;
    int newArray[589] = {};
    int newArray1[589] = {};
    sprintf(intStr, "%d", FindBlock(x, size));
    fin.open(intStr);
    int J = 0;
    if (fin.is_open())
    {
        while (fin.read((char*)&blk, sizeof(Block)))
        {
            newArray[J] = blk.x;
            newArray1[J] = blk.i;
            J++;
        }
    }
    fin.close();
    int result = BinSearch(newArray, size, x);
    return newArray1[result];     
}

int Trans(int x, int y)
{
    ifstream fin;
    Block blk;
    char intStr[11];
    int size = 589;
    int newArray[589] = {};
    int newArray1[589] = {};
    sprintf(intStr, "%d", FindBlock(x, size));
    fin.open(intStr);
    int J = 0;
    if (fin.is_open())
    {
        while (fin.read((char*)&blk, sizeof(Block)))
        {
            newArray[J] = blk.x;
            if (blk.x == x)
            blk.i = y;
            J++;
        }
    }
    fin.close();
    int result = BinSearch(newArray, size, x);
    return y;     
}


int main()
{
    // Add(589);
    // MakeBase();
    // ifstream fin;
    // fin.open("0");
    // if (fin.is_open())
    // {   
    //     Block blk;
    //     while (fin.read((char*)&blk, sizeof(Block)))
    //         blk.Print();
    // }
    // fin.close();
    //cout << Trans(34, 1000);
    //cout << Search(34);
    //cout << remove_line(0, 5);
    // int x, y;
    // cout << "print 0 to find element" << endl;
    // cout << "print 1 to delete element" << endl;
    // cout << "print 2 to add element" << endl;
    // cout << "Enter number:" << endl;
    // cin >> x;

    // cout << "Enter value:" << endl;
    // cin >> y;
    // if (x == 0)
    // {
    //     cout << "Found value is:" << endl;
    //     cout << Search(y);
    // }
    // if (x == 1)
    // {
    //     cout << remove_line("0", y);
    //     cout << "element is deleted";
    // }
    // if (x == 2)
    // {
    //     AddElem(y, 589);
    //     cout << "Element &y was added";
    // }
    return 0;
}