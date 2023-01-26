/// Coded by Arman Hossain (IIUC)

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define    F           first
#define    S           second
#define    pb          push_back
#define    popb        pop_back
#define    pf          push_front
#define    popf        pop_front
#define    lcm(a,b)    (a*b)/gcd(a,b)
#define    gcd(a,b)    __gcd(a,b)
#define    pi          2*acos(0)
#define    elif        else if
#define    ll          long long
#define    nl          '\n'
#define    endl        '\n'
#define    fori(i,b,e) for(int (i)=(b); (i) <= (e); (i)++)
#define    for0(i,n)   for(int (i)=0; (i) < (n); (i)++)
#define    sp          fixed << setprecision
#define    all(x)      x.begin(),x.end()
#define    power(n,p)  pow_mod(n, p, (1LL<<62))
#define    MOD         1000000007
typedef tree<int , null_type, less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;


// ===================== DEBUG  ==========================

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
// ===================== custom function ==========================
ll pow_mod(ll nn, ll pp, ll mm) { ll res = 1; while(pp > 0) { if(pp&1) res = (res * nn) % mm; pp = pp >> 1; nn = (nn * nn) % mm; } return res; }
ll Pow(ll c, ll d) {return d == 0 ? 1 : c * pow(c, d - 1);}

void solve();
// ===================== Main function ==========================
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
    int t=1;
    cin >> t;
    while(t--){
        //printf("Case %d: \n", t);
        solve();
    }
    return 0;
}
void solve(){
    int n;
    cin>>n;
    int a[n+1];
    a[0]=0;
    int l=1,f=0;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        if(a[i-1]==1 && a[i]==1)l+=5;
        else if(a[i]==1)l++;
        else if(a[i]==0 && a[i-1]==0 && i>1){
            cout << -1 << endl;
            f=1;
        }
    }
    if(!f)cout << l << endl;
}
// Contact : a.h.niloy444@gmail.com
 