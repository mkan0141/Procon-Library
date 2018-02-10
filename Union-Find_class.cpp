#include <iostream>
#include <vector>
using namespace std;

class Union_Find{
private:
    vector<int> par, rank;
public:
    Union_Find(int Max_Node){
        par = vector<int>(Max_Node);
        rank = vector<int>(Max_Node);
    }

    int find(int x){
        if(par[x] == x){
            return x;
        }else{
            return par[x] = find(par[x]);
        }
    }

    void unite(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y)return ;

        if(rank[x] < rank[y]){
            par[x] = y;
        }else{
            par[y] = x;
            if(rank[x] == rank[y])rank[x]++;
        }
    }

    bool same(int x, int y){
        return (find(x) == find(y));
    }
};
