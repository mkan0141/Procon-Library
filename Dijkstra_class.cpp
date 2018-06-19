#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;


using type = long long;
using P = pair<type, type>;

struct Edge{
    int to, cost;
    Edge(int a, long long b){
        to = a;
        cost = b;
    }
};

class Dijkstra{
private:
    const type _INF = 100000000;
    int V; // 頂点数
    vector<type> d;
    vector<int> prev;
    vector<vector<Edge> > G;
public:
    Dijkstra(int v){
        V = v + 1;
        d.resize(V);
        G.resize(V);
        prev.resize(V);
    }

    void shortest_path(int s){
        priority_queue<P, vector<P>, greater<P>> que;
        d.assign(V, _INF);
        prev.assign(V, -1);
        d[s] = 0;
        que.push(P(0, s));
        while(que.size()){
            P p = que.top(); que.pop();
            int v = p.second;
            if(d[v] < p.first) continue;
            for(auto e : G[v]){
                if(d[v] + e.cost < d[e.to]){
                    d[e.to] = d[v] + e.cost;
                    prev[e.to] = v;
                    que.push(P(d[e.to], e.to));
                }
            }
        }
    }
    
    void add_path(int from, int to, type cost){
        G[from].push_back(Edge(to, cost));
    }

    type get_cost(int t){
        return d[t];
    }

    vector<int> get_path(int t){
        vector<int> path;
        for(; t != -1; t = prev[t])
            path.push_back(t);
        reverse(path.begin(), path.end());
        return path;
    }
};

int main(){
        
    return 0;
}
