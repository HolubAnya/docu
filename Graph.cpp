#include <iostream>
#include "List.cpp"

using namespace std;
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

