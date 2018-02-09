#include <iostream>
#define mod 1000000007
#define rep(i,x) for(int i=0;i<(x);i++)
using ll = long long;
using namespace std;

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


int main(){
  int a,b,n;
  cin>>n;
  //cin>>a>>b;
  //cout<<"is_prime:("<<n<<") ---> "<<is_prime(n)<<endl;
  cout<<"sieve:("<<n<<") ---> "<<sieve(n)<<endl;
  //cout<<"pow:("<<a<<","<<b<<") ---> "<<Pow(a,b)<<endl;
  return 0;
}
