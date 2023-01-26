#pragma GCC optimize("Ofast") 
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define int long long
// #define segt
// #define fibbo
// #define fact
// #define divi

const int mod=1e9+7;

#ifdef fibbo
unordered_map<int,int> Fib;
int fib(int n){
    // f(0)=1, f(1)=1 , f(2)=2   // fibonacci in logn time
    if(n<2) return 1;
    if(Fib.find(n) != Fib.end()) return Fib[n];
    Fib[n] = (fib((n+1) / 2)*fib(n/2) + fib((n-1) / 2)*fib((n-2) / 2)) % mod;
    return Fib[n];
}
#endif

bool isPerfectSquare(long double x){
	if(x>=0){
		int sr=sqrt(x);
		return (sr*sr==x);
	}
	return false;
}

bool isExponentOfTwo(int n){
    while(n%2==0){
        n/=2;
    }
    return n==1;
}

int power(int x, int y){
    int res = 1;
    x = x % mod;
    if (x == 0) return 0; 
    while (y > 0){
        if (y & 1)
            res = (res*x) % mod;
        y = y>>1;
        x = (x*x) % mod;
    }
    return res;
}
int inv(int n){
    return power(n,mod-2);
}
 
#ifdef fact 
vector<int> fac;
void factorial(int n){
    fac.resize(n+1);
    fac[0]=1;
    for(int i=1;i<=n;i++){
        fac[i]=(fac[i-1]*i)%mod;
    }
}
vector<int> ifac;
void ifactorial(int n){
    ifac.resize(n+1);
    for(int i=0;i<=n;i++){
        ifac[i]=inv(fac[i]);
    }
}
int ncr(int n,int r){
    if(n<r)return 0;
    if(r==0)return 1;
    return (((fac[n]*ifac[r])%mod)*ifac[n-r])%mod;
}
#endif
 
#ifdef divi 
vector<int> prime;
void div(int n){
    prime.resize(n+1,0);
    prime[1]=1;
    for(int i=2;i<=n;i++){
        if(prime[i]==0){
            for(int j=1;j*i<=n;j++){
                if(prime[i*j]==0)prime[j*i]=i;
            }
        }
    }
}
#endif

#ifdef segt
int changingFun(int x,int y){
    return (x+y); //res bhi change krna h......
}

const int N = 2e5;  // limit for array size
int n;  // array size
int t[2 * N];
 
void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) t[i] = changingFun(t[i<<1] , t[i<<1|1]);
}
 
void modify(int p, int value) {  // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = changingFun(t[p] , t[p^1]);
}
 
int query(int l, int r) {  // sum on interval [l, r)
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = changingFun(res,t[l++]);
    if (r&1) res =changingFun(res,t[--r]);
  }
  return res;
}
#endif

//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//
//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//

// #define google
#define testcases
// #define tle
// #define file
struct lrdu{
    int l,r,d,u;
};
void solve(){
    int n,m; cin>>n>>m;
    string s; cin>>s;
    int x=s.size(),i;
    vector<lrdu> v(x+1);
    v[0]={0,0,0,0};
    pair<int,int> pos={0,0};
    for(i=0;i<x;i++){
        v[i+1]=v[i];
        if(s[i]=='L'){
            pos.second--;
            if(pos.second<0)v[i+1].l=max(v[i+1].l,abs(pos.second));
        }

        if(s[i]=='R'){
            pos.second++;
            if(pos.second>0)v[i+1].r=max(v[i+1].l,pos.second);
        }

        if(s[i]=='D'){
            pos.first++;
            if(pos.first>0)v[i+1].d=max(v[i+1].d,pos.first);
        }

        if(s[i]=='U'){
            pos.first--;
            if(pos.first<0)v[i+1].u=max(v[i+1].d,abs(pos.first));
        }
    }
    for(i=x;i>0;i--){
        if(v[i].l+v[i].r<m && v[i].d+v[i].u<n){
            cout<<v[i].u+1<<" "<<v[i].l+1; return;
        }
    }
    cout<<"1 1";
}
signed main(){
    #ifdef tle
    time_t start, end;
    time(&start);
    #endif
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    #ifdef file
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
    #endif
    int tt=1,t=1;
    #ifdef testcases
        cin>>tt;
    #endif
    while(t<=tt){
        #ifdef google
            cout<<"Case #"<<t<<": ";
        #endif
        solve();
        cout<<"\n";
        t++;
    }
    #ifdef tle
    time(&end);
    double time_taken = double(end - start);
    cout << "Time taken by program is : " << fixed << time_taken << setprecision(5);
    cout << " sec " << endl;
    #endif
    return 0;
}

#ifdef v_s_codes                                                                                                                                                                             
                                                                                                      ,---,                           
                                                                                     ,---.           ,---.|                           
             .---.                      .--.--.                                     '   ,'\         |   | :                    .--.--.    
           /.  ./|                     /  /    '                        ,---.      /   /   |        |   | |       ,---.       /  /    '   
         .-' . ' |                    |  :  /`./                       /     \    .   ; ,. :      ,--.__| |      /     \     |  :  /`./   
        /___/ \: |                    |  :  ;_                        /    / '    '   | |: :     /   ,'   |     /    /  |    |  :  ;_     
        .   \  ' .                     \  \    `.                    .    ' /     '   | .; :    .   '  /  |    .    ' / |     \  \    `.  
         \   \   '            ___       `----.   \           ___     '   ; :__    |   :    |    '   ; |:  |    '   ;   /|      `----.   \ 
          \   \            .'  .`|     /  /`--'  /        .'  .`|    '   | '.'|    \   \  /     |   | '/  '    '   |  / |     /  /`--'  / 
           \   \ |      .'  .'   :    '--'.     /      .'  .'   :    |   :    :     `----'      |   :    :|    |   :    |    '--'.     /  
            '---"    ,---, '   .'       `--'---'    ,---, '   .'      \   \  /                   \   \  /       \   \  /       `--'---'   
                     ;   |  .'                      ;   |  .'          `----'                     `----'         `----'               
                     `---'                          `---'                                                                 
#endif