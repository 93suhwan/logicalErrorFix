#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 998244353
#define PI 3.141592653589793238462
#define all(vec) vec.begin(), vec.end()
#define minn(vec) *min_element(all(vec))
#define maxx(vec) *max_element(all(vec))
#define sum(vec) accumulate(all(vec), 0)
#define vpii vector<pii>
#define vi vector<int>
#define vll vector<ll>
#define pll pair<ll, ll>
#define vpll vector<pll>
#define vvi vector<vi>
#define vvll vector<vll>
#define sz(x) ((int)(x).size())

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " " << x << "\n";
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

const ll inf = LLONG_MAX;
const int N = 1e3 + 10;
const int M = 1e9;

int n,m,c;
int fx[]={-1,0,1,0};    
int fy[]={0,1,0,-1};    
bool vis[N][N];
vector<vector<int>> v(N,vi(N));
priority_queue<int> q;
void dfs(int i,int j){
    c++;
    vis[i][j]=true;
    for(int k=0;k<4;k++){
        if(v[i][j]&(1<<k))
        continue;
        else if(j+fx[k]<m && j+fx[k]>=0 && i+fy[k]<n && i+fx[k]>=0 && !vis[i+fy[k]][j+fx[k]])
        dfs(i+fy[k],j+fx[k]);
    }
}

void solve()
{
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> v[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j])
            c=0;
            dfs(i,j);
            q.push(c);
        }
    }
    while(!q.empty()){
        cout << q.top() << " ";
        q.pop();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("Input.txt", "r", stdin);
    //     freopen("Output.txt", "w", stdout);
    //     freopen("Error.txt", "w", stderr);
    // #endif
    int T;
    //cin >> T;
    T = 1;
    for (int t = 0; t < T; t++)
    {
        solve();
    }
    return 0;
}