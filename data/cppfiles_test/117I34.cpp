#include <bits/stdc++.h>
using namespace std;
#define mod  998244353
#define maxn 200001
#define el "\n"
#define pi acos(-1.0)
#define doshomik  cout<<fixed<<showpoint<<setprecision(10)
#define lcm(a, b) (a/__gcd(a,b))*b
#define fast_io  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ff first
#define ss second
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << el;
#else
#define debug(x)
#endif
// find_by_order(x) find the number in  index x [ 0 based]
// order_of_key(y) count the numbers that are strictly less than y
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
typedef tree< int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<pair<int, int>,null_type,less<pair<int, int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_set_pair;
void _print(ll t) {cerr << t;}void _print(int t) {cerr << t;}void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}void _print(lld t) {cerr << t;}void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
vector<ll>adj[maxn+1];
ll vis[maxn+1];
void bfs(int s)
{
    queue<ll>q;
    q.push(s);
    vis[s]=1;
    while(!q.empty())
    {
        ll x,y;
        x=q.front();
        q.pop();
        for(int i=0; i<adj[x].size(); i++)
        {
            if(vis[adj[x][i]]==0)
            {
                y=adj[x][i];
                vis[y]=1;
                q.push(y);
            }
        }
    }
}
int main()
{
    fast_io;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
#endif
    // shortcut : ctrl+alt+l for format text
    ll t=1,caseno=1;
    cin>>t;
    while(t--) {
       ll n,m;
       cin>>n>>m;
       string s[n];
       for(int i=0;i<n;i++) cin>>s[i];
        pair<ll,ll> source;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(s[i][j]=='L'){
                    source.ff=i;
                    source.ss=j;
                    break;
                }
            }
        }
        ll vis[n][m];
        memset(vis,0,sizeof vis);
        queue<pair<ll,ll>>q;
        q.push(source);
        vis[source.ff][source.ss]=1;
        while(!q.empty()){
            source=q.front();
            q.pop();
            if(s[source.ff][source.ss]=='.'){
                ll cnt1=0,cnt2=0;
                if(source.ss+1<m&&s[source.ff][source.ss+1]!='#'){
                    cnt1++;
                    if(s[source.ff][source.ss+1]!='.') cnt2++;
                }
                if(source.ss-1>=0&&s[source.ff][source.ss-1]!='#'){
                    cnt1++;
                    if(s[source.ff][source.ss-1]!='.') cnt2++;
                }
                if(source.ff+1<n&&s[source.ff+1][source.ss]!='#'){
                    cnt1++;
                    if(s[source.ff+1][source.ss]!='.') cnt2++;
                }
                if(source.ff-1>=0&&s[source.ff-1][source.ss]!='#'){
                    cnt1++;
                    if(s[source.ff-1][source.ss]!='.') cnt2++;
                }
                if(cnt1<=2&&cnt2){
                    //debug(cnt1)
                    //debug(cnt2)
                    s[source.ff][source.ss]='+';
                }
            }
            if(source.ss+1<m&&s[source.ff][source.ss+1]=='.'){
                if(!vis[source.ff][source.ss+1]){
                    q.push({source.ff,source.ss+1});
                    vis[source.ff][source.ss+1]=1;
                }
            }
            if(source.ss-1>=0&&s[source.ff][source.ss-1]=='.'){
                if(!vis[source.ff][source.ss-1]){
                    q.push({source.ff,source.ss-1});
                    vis[source.ff][source.ss-1]=1;
                }
            }
            if(source.ff+1<n&&s[source.ff+1][source.ss]=='.'){
                if(!vis[source.ff+1][source.ss]){
                    q.push({source.ff+1,source.ss});
                    vis[source.ff+1][source.ss]=1;
                }
            }
            if(source.ff-1>=0&&s[source.ff-1][source.ss]=='.'){
                if(!vis[source.ff-1][source.ss]){
                    q.push({source.ff-1,source.ss});
                    vis[source.ff-1][source.ss]=1;
                }
            }
        }
        for(int i=0;i<n;i++) cout<<s[i]<<el;
    }
    return 0;
}