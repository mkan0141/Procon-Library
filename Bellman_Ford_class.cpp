#include <iostream>
#include <vector>
using namespace std;

struct Edge{
    long long to, cost;
    Edge(long t, long c){
        to = t;
        cost = c;
    }
};

class Bellman_Ford{
    private:
        const long long Inf = 1LL << 50;
        vector<long long> dist;
        vector<vector<Edge> > adj;
    public:
        Bellman_Ford(int v){
            dist = vector<long long>(v + 1);
            adj = vector<vector<Edge> >(v + 1);
        }

        void add_edge(int from, int to, int cost){
            adj[from].push_back(Edge(to, cost));
        }

        bool shortest_path(int s){
            for(int i = 0; i < (int)dist.size(); i++)dist[i] = Inf;
            dist[s] = 0;
            int cnt = 0;
            bool update = true;
            while(update){
                if(cnt > (int)dist.size())return false;
                cnt++;
                update = false;
                for(int i = 0; i < (int)dist.size(); i++){
                    for(int  j = 0; j < (int)adj[i].size(); j++){
                        Edge e = adj[i][j];
                        if(dist[e.to] > dist[i] + e.cost && dist[i] != Inf){
                            dist[e.to] = dist[i] + e.cost;
                            update = true;
                        }
                    }
                }
            }
            return true;
        }

        long long get_distance(int x){
            return dist[x];
        }

        void DEBUG(){
            for(int i = 0; i < (int)dist.size(); i++){
                cout << 1 << " --> " << i << " = " << dist[i] << endl;
            }
        }
};

