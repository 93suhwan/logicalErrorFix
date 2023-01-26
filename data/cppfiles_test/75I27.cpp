#include <bits/stdc++.h>
using namespace std;

#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace __gnu_pbds;

template<class T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update> ;

template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;

#define int         long long
typedef vector<int> vi;
typedef pair<int, int> pii;
mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
#define For(i,n)    for(int i = 0; i < (int) n; ++i)
#define rep(i,a,b)  for(int i=a;i<b;i++)


#define ll          long long
#define sz(x)       (int)((x).size())
#define lld         long double
#define fr          first
#define sc          second
#define pb          push_back
#define endl        "\n"
#define ar          array
#define INF         1e18;
#define all(v)      (v).begin(),(v).end()
#define mem1(a)     memset(a,-1,sizeof(a))
#define mem0(a)     memset(a,0,sizeof(a))
#define ppc         __builtin_popcount
#define ppcll       __builtin_popcountll

#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
/**************DEBUG**************************/

void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}


template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.fr); cerr << ","; _print(p.sc); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}


void usaco(string filename) {
    // #pragma message("be careful, freopen may be wrong")
    freopen((filename + ".in").c_str(), "r", stdin);
    freopen((filename + ".out").c_str(), "w", stdout);
}

/*********************************MAIN_CODE****************************/


const int N = 5e5 + 5;
const int M = 1e9 + 7;
const int M2 = 998244353;
pii a[N];
int n;
int go(int m){
    int val=m;
    For(i,n){
        if(val<a[i].fr){
            return 0;
        }
        val+=a[i].sc;
    }
    return 1;
}
bool comp(pii p,pii q){
    if(p.fr==q.fr){
        return p.sc>q.sc;
    }
    return p.fr<q.fr;
}

void solve() {  
    //int n;
    cin>>n;
    
    For(i,n){
        int k;
        cin>>k;
        int val=0;
        For(j,k){
            int x;
            cin>>x;
            val=max(val,x);
        }
        a[i]={val,k};

    }
    // For(i,n)cout<<a[i].fr<<" ";
    // cout<<endl;
    sort(a,a+n,comp);
    int l=0,r=1e9;
    int ans=1e9+1;
    while(l<r){
        int m=(l+r)/2;
        if(go(m)){
            r=m-1;
            ans=m;
        }
        else{
            l=m+1;
        }
    }
    cout<<ans<<endl;

}
signed main() {
    //usaco("milkvisits");
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
#ifdef NCR
    init();
#endif

    int t = 1;
    cin >> t;

    int a = 1;
    while (t--) {
        //cout<<"Case #"<<a<<": ";
        solve();
        a += 1;
    }
}
