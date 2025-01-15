#include <iostream>       
#include <algorithm>       
#include <vector>       
#include <numeric>       
#include<iterator>       
#include <limits.h>       
#define MAXN 500020       
using namespace std;       
int p[MAXN];       
struct Graph{       
    int n1,n2,weight;       
};       
       
bool comp(Graph a, Graph b)        
{        
    if (a.weight == b.weight) {
        if (a.n1 == b.n1) {
            return a.n2 < b.n2;
        }
        return a.n1 < b.n1;
    }
    return a.weight < b.weight;      
}       
       
bool max_node(Graph a, Graph b)        
{        
    return (a.n2 < b.n2);        
}       
       
       
int find (int a) {       
    if(p[a] == a)       
        return a;       
    else       
        return p[a] = find(p[a]);       
}       
       
void kruskal(vector<Graph> &graph,int node) {       
            
    sort(graph.begin(), graph.end(), comp);       
    vector<Graph> MST;       
    int mincost = 0;       
    for(int i = 0; i < node+1; i++) p[i] = i;               
     for (Graph it: graph) {       
        int pn1 = find(it.n1);         
        int pn2 = find(it.n2);       
        if(pn1 != pn2){        
                p[pn2] = pn1;       
                mincost += it.weight;       
                MST.push_back(it);        
        }       
    }       
          
             
   cout <<"\n"<<"minimum spanning tree:"<<endl;       
    for (int i = 0; i < MST.size(); i++) {       
        cout << i+1 <<":"<<" "<<"<"<< MST[i].n1 <<","<< MST[i].n2<<">" << endl;       
    }       
    cout <<endl<<"The cost of minimum spanning tree: "<< mincost<<endl;       
}       
int main(){       
    vector<Graph> graph;       
    Graph act;       
    while (cin >> act.n1>> act.n2 >> act.weight) {       
        graph.push_back(act);           
        char ch = getchar();       
        if(ch == '\n')       
            break;       
    }   
    auto n = *std::max_element(graph.begin(),graph.end(),max_node);     
    int node = n.n2;     
       
     vector<vector<pair<int, int>>> adj_list(node+1);       
    for (int i = 0; i < graph.size(); ++i) {       
        int n1 = graph[i].n1;       
        int n2 = graph[i].n2;       
        int weight = graph[i].weight;       
        adj_list[n1].push_back(make_pair(n2, weight));       
        adj_list[n2].push_back(make_pair(n1, weight));       
    }       
       
    cout<<"Adjacency list:"<<endl;       
    for (int i = 0; i < adj_list.size(); ++i) {       
        cout << i << ": ";       
        for (auto it : adj_list[i]) {       
            cout << it.first << " -> ";       
        }       
        cout << "end" << endl;       
    }       
       
    kruskal(graph,node);       
    return 0;       
}  
