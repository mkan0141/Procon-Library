#include <iostream>
#include <vector>
#define mod 1000000007
#define rep(i,x) for(int i=0;i<(x);i++)
using ll = long long;
using namespace std;

// gcd
int gcd(int a,int b){
  if ( ( 0 == a ) || ( 0 == b ) )
    return 0;
  while( a != b ){
    if ( a > b ) a = a - b;
    else n = b - a;
  }
  return a;
}

//lcm
int lcm(int a,int b){
  if ( ( 0 == a ) || ( 0 == b ) )
    return 0;
  
  return ((a / gcd(a, b)) * b); 
}

//高速累乗計算  
long long Pow(long long x,long long n){
    long long res=1;
    while(0<n){
        if(n&1)res*=res*x%mod;
        x=x*x%mod;
        n>>=2;
    }
    return res;
}

//素数判定
bool is_prime(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0)return false;
    }
    return true;
}


//n以下の数で何個素数があるか
int sieve(int n){
    int prime[10000];
    bool is_prime[100000];
    int p=0;
    for(int i=0;i<100000;i++)is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<100000;i++){
        if(is_prime[i]){
            prime[p++]=i;
            for(int j=2*i;j<=n;j+=i)is_prime[j]=false;
        }
    }
    return p;
}

// nCr
ll C[55][55];
void comb_table(int n){
rep(i,n+1){
        rep(j,n+1){
            if(j==0||j==i)C[i][j]=(ll)1;
            else C[i][j]=C[i-1][j-1]+C[i-1][j];
        }
    }
}

class Combination{
public:
  Combination(int n, int m){
    fact.resize(n+1);
    rfact.resize(n+1);
    MOD=m;
    fact[0] = rfact[0] = 1;
    for (int i = 1; i < n + 1; ++i) {
        fact[i] = (fact[i - 1] * i) % MOD;
        rfact[i] = (rfact[i - 1] * mod_inv(i)) % MOD;
    }
  }

  ll mod_pow(ll x, int p){
    ll res = 1;
    while(p){
      if(p&1)res = (ll)1 * res * x % MOD;
      x = ll(1) * x * x % MOD;
      p >>= 1;
    }
    return res;
  }

  ll mod_inv(int x){
    return mod_pow(x, MOD - 2);
  }

  ll nCr(int n, int r){
    if (!(0 <= r && r <= n)) return 0;
    return (((fact[n] * rfact[r]) % MOD) * rfact[n - r]) % MOD;
  }

  void DEBUG(){
    rep(i,5){
      rep(j,5)
    cout<<i << " " << j << " " << nCr(i,j)<<endl;
      }
  }
  
private:
  vector<ll> fact;
  vector<ll> rfact;
  int MOD;
};

