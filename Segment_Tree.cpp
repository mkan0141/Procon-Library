#include <iostream>
#include <numeric_limits>
#include <vector>
using namespace std;

class Segment_Tree {
private:
  int N;
  vector<int> dat;
public:
  Segment_Tree(int n){
    N = 1;
    while(N<n)N*=2;
    dat.resize(N * 2 - 1, INT_MAX);
  }

  // 0-indexed
  void update(int a, int x){
    a += (N - 1);
    dat[a] = x;
    while(a > 0){
      a = (a - 1) / 2;
      dat[a] = min(dat[a * 2 + 1], dat[a * 2 + 2]);
    }
  }

  int get_min(int a, int b, int k = 0, int left = 0, int right = -1){
    if(right < 0) right = N;
    
    if(right <= a || b <= left) return INT_MAX;
    if(a <= left && right <= b) return dat[k];
    else {
      int vl = get_min(a, b, 2 * k + 1, left, (left + right) / 2);
      int vr = get_min(a, b, 2 * k + 2, (left + right) / 2, right);
      return min(vl, vr);
    }
  }
};
