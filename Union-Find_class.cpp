#include <iostream>
#include <vector>
using namespace std;

class Union_Find{
private:
    vector<int> par, rank;

    int find(int x){
        if(par[x] == x){
            return x;
        }else{
            return par[x] = find(par[x]);
        }
    }
public:
    Union_Find(int Max_Node){
        par.resize(Max_Node);
        rank.resize(Max_Node);
        for(int i = 0; i < Max_Node; i++){
            par[i] = i;
            rank[i] = 0;
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
