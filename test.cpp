// #include <stdio.h>
// #include <string>
// #include <iostream>
//  using namespace std;
// // int main () { 
// // 	FILE *file;
// // 	struct food {
// // 		char name[20]; 
// // 		unsigned qty; 
// // 		float price; 
// // 	};
// // 	struct food shop[10];
// // 	char i=0;
 
// // 	file = fopen("fscanf.txt", "r");
 
// // 	while (fscanf (file, "%s%u%f", shop[i].name, &(shop[i].qty), &(shop[i].price)) != EOF) {
// // 		printf("%s %u %.2f\n", shop[i].name, shop[i].qty, shop[i].price); 
// // 		i++;
// // 	}

// //     return 0;
// // }

// #include <iostream>
// #include <fstream>
// #include <string>


// void FuncReadFile(char* path)
// {
    
//     ifstream FileInput(path);
//     string str;
//     while (!FileInput.eof())
//     {
//         getline(FileInput, str);
//         cout << str << endl;
//     }
// }

// int main()
// {

//     std::string text;
//     char* path = "ingredients.txt";
//     FuncReadFile(path);
//         std::cout << text<<std::endl;

//     std::cout << "END" << std::endl;
    
// }

// template <class T> 
// Tree<T> Tree<T>::Filter2(Node *node)
// {
//     if (!node) return;

//         if (node->data < 0)
//         {
//             Remove(node->data);
//             Filter2(root->data);
//         }
//         if (node->right)
//             Filter2(node->right);

//         if (node->left)
//             Filter2(node->left);
//     Show(getRoot());


// }
#include <iostream>
// //#include <conio.h>
// #include <fstream>
// #include <cstring>

using namespace std;

// int main ()
// {
//     setlocale (LC_ALL, "Russian");

//     string str;
//     int k;
//     cout << "Введите строку: ";
//     getline (cin,str);

//     cout << "Введите номер строки, после которой требуется вставить: ";
//     cin >> k;

//     ofstream fout;
//     fout.open("text.txt", ofstream::app);

    
//         fout.seekp(k-1);
    

//     fout << str;
//      fout.close();

// //     //_getch ();
// //     return 0;
// // }
// R.File.cpp: определяет точку входа для консольного приложения.
//



	

#include <iostream>
#include <fstream>
#include <string>
class B
{
    public:
    B()
    {
        x = 0;
    }
    B(int x)
    {
       
        this->x = x;
    }
    
    int x;
    void Print()
    {
       cout << x << endl;
    }
};
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iterator>
 
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
        return false;
    }
    return false;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <cassert>

using namespace std;

const int inf = INT_MAX;

void find_min_way(int **g, int n, int start, int finish) {
  vector <int> d(n,inf), p(n,-1);
  vector <bool> used(n);
  int min,u;
  d[start] = 0;
  for (int i = 0; i < n; i++) {
      min = inf, u = -1;
      for (int j = 0; j < n; j++)
          if (!used[j] && d[j] < min)
              min = d[j], u = j;
      used[u] = true;
      for (int j = 0; j < n; j++)
          if (d[j] > d[u] + g[u][j] && g[u][j] > 0)
              d[j] = d[u] + g[u][j], p[j] = u;
  }
  vector <int> v;
  if (p[finish] == -1)
    cout << "No way\n";
  else {
      for (int u = finish; u != -1; u = p[u])
          v.push_back(u);
      reverse(v.begin(),v.end());
      cout << "Minimal way: ";
      int weight = 0;
      for (int i = 0; i < v.size(); i++) {
          if (i + 1 < v.size()) {
            weight += g[v[i]][v[i + 1]];
          }
          if (i > 0) cout << "->";
          cout << v[i] + 1;
      }
      cout << endl;
      cout << "Minimal weight: " << weight << endl;
  }
}

void print_graph(int **g, int n) {
  cout << "Graph: " << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      cout << g[i][j] << " ";
    cout << endl;
  }
}

void make_graph(int **g, int n) { // create not oriented graph without loops
  srand(time(NULL));

  for (int i = 0; i < n; i++)
    g[i] = new int[n];

  for (int i = 0; i < n; i++) {

    for (int j = 0; j < n; j++)
      g[i][j] = g[j][i] = rand()%100;

    g[i][i] = 0;
  }
}

int main(int argc, char *argv[]) {
  int start;
  cout << "Enter start vertex: " << endl;
  cin >> start;
  start--;
  int finish;
  cout << "Enter finish vertex: " << endl;
  cin >> finish;
  finish--;
  int n;
  cout << "Enter the number of vertex: ";
  cin >> n;
  int **g = new int*[n]; // initialize graph 'g'
  make_graph(g, n);
  print_graph(g, n);
  
  find_min_way(g, n, start, finish);
  return 0;
}
 
// int main()
// {

//     cout << remove_line("text.txt", 0);
//     ifstream fin;
//     fin.open("text.txt");
//     if (fin.is_open())
//     {   
//         B blk;
//         while (fin.read((char*)&blk, sizeof(B)))
//             cout << blk.x << endl;
//     }
//     fin.close();
    
 
//   return 0;
// }

