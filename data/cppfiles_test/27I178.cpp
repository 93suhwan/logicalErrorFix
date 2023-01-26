#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define f(i,x,n) for(int i=x;i<=n;i++)
#define all(c) c.begin(),c.end()
#define rall(c) c.rbegin(),c.rend()
#define pb push_back
#define pu push
#define vi vector<int>
#define vvi vector<vector<int>>
#define ss second
#define ff first
#define int int64_t
#define pi pair<int,int>
#define countbits __builtin_popcount
template<typename T> using pbds = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update> ;
/*find_by_order and order_of_key*/
const int Nmax=1e6 + 7;
const int mod=1000000007;
vector<int>prime,fact,invfact;


int is_power_of_two(int a){
    return a && (!(a&(a-1)));
}


int isperfectsquare(int a){
    double b=sqrt(a);
    return (b-ceil(b)==0);
}

/* POWER FUNCTION*/


int pow(int a,int b,int m){
    a=a%m;
    int res=1;
    while(b>0){
        if(b&1){
            res=res * a%m;
        }
        a=a * a %m;
        b=b/2;
    }
return res;
}


int mod_add(int a, int b, int m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int mod_mul(int a, int b, int m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
int mod_sub(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
int mod_div(int a, int b, int m) {a = a % m; b = b % m; return (mod_mul(a , pow(b , m-2 , m), m));}


/* SIEVE OF ERATOSTHENES FOR PRIME */
void sieve(int n){
    bool isprime[n+1];
    memset(isprime,true,sizeof(isprime));
    prime.push_back(2);
    for(int i=3;i<=sqrt(n);i+=2){
        if(isprime[i]){
            for(int j=i*i;j<=n;j+=i){
                isprime[j]=false;
            }
        }
    }
    for(int i=3;i<=n;i+=2){
        if(isprime[i]){
            prime.push_back(i);
        }
    }
}


/* FACTORIAL*/
void factorial() {
  fact.resize(Nmax+1);
  invfact.resize(Nmax+1);
  fact[0] = 1;
  for(int i = 1; i <1000004; i++) {
      fact[i] = (fact[i-1] * i);
      fact[i] %= mod;
  }
  invfact[1000002]=pow(fact[1000002],mod-2,mod);
  for(int i=1000001;i>=0;i--){
      invfact[i]=(i+1)*invfact[i+1]%mod;
  }
}


/*NCR*/
int ncr(int n,int r,int p){
  return (((fact[n]*invfact[n-r])%p)*invfact[r])%p;
}


vector<pair<int,int>> Getprimefactors(int n){
    vector<pair<int,int>>pr;
    f(i,2,sqrt(n)){
        int cnt=0;
        while(n%i==0){
            cnt++;
            n/=i;
        }
        if(cnt)pr.push_back({i,cnt});
    }
    if(n>1){
        pr.push_back({n,1});
    }
    return pr;
}


/*YOU CAN SOLVE IT*/

void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    if(m<n-1 && m>(n*(n-1))/2){
        cout<<"NO\n";return;
    }
    int val=(n*(n-1))/2;
    int val2=val-m+1;
    if(val2<(k-1)){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
}


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}