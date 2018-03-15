/*
 *  Kruskall class
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Edge{
    int u, v, cost;
    Edge(int a, int b, int c){
        u = a;
        v = b;
        cost = c;
    }
    bool operator<(const Edge &e) const {
        return cost < e.cost;
    }
    bool operator>(const Edge &e) const {
        return cost > e.cost;
    }
};

class Kruskall{
    public:
        Kruskall(int V) {
            par.resize(V + 1);
            rank.resize(V + 1);
            init_union_find(V + 1);
        }

        void add_path(int u, int v, int cost) {
            es.push_back(Edge(u, v, cost));
        }

        long long create_spannig_tree() {
            long long ret = 0;
            sort(es.begin(), es.end());
            for(auto e : es){
                if(!same(e.u, e.v)){
                    unite(e.u, e.v);
                    ret += e.cost;
                }
            }
            return ret;
        }

    private:
        vector<int> par, rank;
        vector<Edge> es;

        /* union find */
        void init_union_find(int n) {
            for(int i = 0; i < n; i++){
                par[i] = i;
                rank[i] = 0;
            }
        }

        int find(int x) {
            if(par[x] == x){
                return x;
            }else{
                return par[x] = find(par[x]);
            }
        }


        void unite(int x,int y) {
            x = find(x);
            y = find(y);
            if(x == y) return ;
            if(rank[x] < rank[y]){
                par[x] = y;
            }else{
                par[y] = x;
                if(rank[x] == rank[y]) rank[x]++;
            }
        }

        bool same(int x,int y){
            return find(x) == find(y);
        }
};
