//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace __gnu_pbds;
/*--------------------------------------------------------------------------------------------*/

#define ll  long long int
#define ld  long double
#define eb emplace_back
#define pb push_back
#define UB upper_bound
#define LB lower_bound
#define BS binary_search
#define F first
#define S second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define mxe(v) *max_element(v.begin(), v.end())
#define mne(v) *min_element(v.begin(), v.end())
#define endl "\n"
#define pii pair<int,int>
#define sz(x) int((x).size())
#define fl(i,a,b) for (int i = (a); i < (b); ++i)
#define f0l(i,a) fl(i,0,a)
#define flex(i,a,b,c) for (int i = (a); i < (b); i += c)
#define lf(i,a,b) for (int i = (a)-1; i >= (b); --i)
#define xelf(i,a,b,c) for (int i = (a); i >= (b); i -= c)
#define l0f(i,a) lf(i,a,0)
#define rep(a) f0l(_,a)
#define each(a,x) for (auto& a: x)
#define cases ll t;cin>>t;f0l(i,t)
#define getunique(v) {sort(all(v)); v.erase(unique(all(v)), v.end());}


template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;


/*--------------------------------------------------------------------------------------------*/
template<class T> 
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update> ;
 
template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;
/*--------------------------------------------------------------------------------------------*/

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
template<typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());
 
    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}
template<class T> istream& operator >> (istream &is, vector<T>& V) { for(auto &e : V) is >> e; return is; }
template<class T> ostream& operator << (ostream &is, vector<T>& V) { for(auto &e : V) is << e <<' '; return is; }
template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.F>>a.S;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.F<<" "<<a.S;return out;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

/*--------------------------------------------------------------------------------------------------------------*/


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll lcm(ll a,ll b){
    ll x=a*b;
    return (x/__gcd(a,b));}
ll logint(ll a,ll b){
    ll i=0;
    ll k=1;
    while(a>=k)
    {
        i++;
        k*=b;
    }
    return i-1;}
ll fast_pow(ll x,ll y,ll m){
    ll ans=1,r=1;
    x%=m;
    while(r>0&&r<=y)
    {
        if(r&y)
        {
            ans*=x;
            ans%=m;
        }
        r<<=1;
        x*=x;
        x%=m;
    }
    return ans;}

/*---------------------------------------------GLOBALS--------------------------------------------------------------*/

ll tc,n,k,m;
const int MOD = 1e9+7; // 998244353;
const ld PI = acos((ld)-1);
const int N = 2e5 + 5;
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!
const int64_t INF = 1e18;

/*-----------------------------------PLEASE CHECK FOR ADV. BINARY SEARCH--------------------------------------------*/
vector<int> lis2(vector<int> &a){
    vector<int> v;
    for (int i = 0; i < n; i++) {
        if(a[i] == 1e9 + 5)
            continue;
        auto it = lower_bound(v.begin(), v.end(), a[i]);
        if (it != v.end()) *it = a[i];
        else v.push_back(a[i]);
    }
    return v;
}
void LogOutt()
{
    cin>> n>> k;
    vector<int> a(n);
    cin>> a;
    int mx = 1e9 + 5;
    vector<int> v;
    f0l(i, n){
        fl(j, i, n){
            if(a[j] == i + 1){
                v.eb(j - i);
                break;
            }
        }
    }
    m = sz(v);
    int ans = mx;
    vector<int> b(m, 1);
    f0l(i, m){
        fl(j, i+1, m){
            if(v[j] >= v[i])
                b[j] = b[i] + 1;
        }
        if(b[i] >= k){
            ans = amin(ans, v[i]);
        }
    }
    if(ans == mx)ans = -1;
    cout<<ans<<endl;
}



void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }
void setErr(string s) { freopen(s.c_str(),"w",stderr); }

int main(){
    setErr("errorrr.txt");
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cout<<fixed<<setprecision(25);
    cerr<<fixed<<setprecision(10);
    auto start = std::chrono::high_resolution_clock::now();
    tc=1;
    cases
    {
        LogOutt();
        tc++;
    }
    auto stop = std::chrono::high_resolution_clock::now(); 
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s "<<endl;    
}