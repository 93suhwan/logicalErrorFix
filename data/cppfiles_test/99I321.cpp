#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int long long int

#define pb push_back
#define mp make_pair
#define mii map<int,int>
#define pii pair<int,int>
#define vi  vector<int>
#define sii set<int,int>
#define pqb priority_queue<int>
#define pqs priority_queue<int,vi,greater<int>>
#define setbits(x) _builtin_popcountll(x)
#define zrobits(x) _builtin_ctzll(x)
#define mod 1000000007
#define inf 1e18
#define ps(x,y) fixed<<setprecision(y)<<x
#define mk(arr,n,type) type *arr=new type[n]
#define w(t) int t;  cin>>t;  while(t--)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
template<class T,class V> void _print(pair<T,V> p) {cerr<<"{"; _print(p.first);cerr<<","; _print(p.second);cerr<<"}";}
template<class T>void _print(vector<T> v) {cerr<<" [ "; for (T i:v){_print(i);cerr<<" ";}cerr<<"]";}
template<class T>void _print(set<T> v) {cerr<<" [ "; for (T i:v){_print(i); cerr<<" ";}cerr<<"]";}
template<class T>void _print(multiset<T> v) {cerr<< " [ "; for (T i:v){_print(i);cerr<<" ";}cerr<<"]";}
template<class T,class V>void _print(map<T, V> v) {cerr<<" [ "; for(auto i:v) {_print(i);cerr<<" ";} cerr<<"]";}

void dkj()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void solve()
{
    int n;  cin>>n;
    string s;  cin>>s;
    vi v;
    for(int i=0;i<n;i++) {
        if(s[i]=='2') v.pb(i);
    }

    if(v.size()==1 || v.size()==2) cout<<"NO"<<"\n";
    else if(v.size()!=0){
        cout<<"YES"<<"\n";
        char ans[n][n];
        ans[v[v.size()-1]][v[0]]='+';  ans[v[0]][v[v.size()-1]]='-';
        for(int i=0;i<v.size()-1;i++) {
            ans[v[i]][v[i+1]]='+';
            ans[v[i+1]][v[i]]='-';
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(i==j) ans[i][j]='X';
                else if(ans[i][j]!='+' && ans[i][j]!='-') ans[i][j]='=';
            }
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                cout<<ans[i][j];
            }
            cout<<"\n";
        }
    }
    else {
        cout<<"YES"<<"\n";
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(i==j) cout<<'X';
                else cout<<'=';
            }
            cout<<"\n";
        }
    }
    return;  
}


int32_t main()
{
    dkj();
    int t=1;
    cin>>t;
    while(t--) {
        solve();
    }
    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms/n";
    return 0;
}
