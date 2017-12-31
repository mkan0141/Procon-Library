#include <iostream>
#define INF 1000000000
using namespace std;


#define MAX_E 100 //辺の最大値
#define MAX_V 100

struct edge{int from, to, cost;};

edge es[MAX_E]; //辺

int d[MAX_V];
int V,E;

void shortage_path(int s){
  for(int i=0;i<V;i++) d[i]=INF;
  d[s]=0;
  bool update=true;
  while(update){
    update=false;
    for(int i=0;i<E;i++){
      edge e=es[i];
      if(d[e.from]!=INF&&d[e.to]>d[e.from]+e.cost){
	     d[e.to]=d[e.from]+e.cost;
	      update=true;
      }
    }
    if(!update)break;
  }
}
