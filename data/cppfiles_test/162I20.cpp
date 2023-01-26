#include<bits/stdc++.h>
using namespace std;
//common file for PBDS
#include<ext/pb_ds/assoc_container.hpp>
//including tree_order_statistics_node_update
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
//macro definition
template <typename T>
using ordered_set= tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set

//Optimisations (Black Magic 🌑)
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#define ll long long
#define lld long double
#define ull unsigned long long
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repk(i, k, n) for (ll i = k; k < n ? i < n : i > n; k < n ? i++ : i--)
#define input(vec) for (auto &el : vec) cin >> el;
#define print(vec) for (auto &el : vec) cout << el ; cout << endl;
#define bit(x) __builtin_popcount(x)
#define bitll(x) __builtin_popcountll(x)
#define popb pop_back
#define pb push_back
#define eb emplace_back
#define ub upper_bound
#define lb lower_bound
#define ff first
#define ss second
#define um unordered_map
#define om ordered_map
#define uniq(x) (x).erase(unique(all(x)), (x).end())
#define precision(x, y) fixed << setprecision(y) << x
#define PI 3.1415926535897932384626
#define sz(x) ((ll)(x).size())
#define present(b, a) ((a).find((b)) != (a).end())  //if b is present in a
#define nl '\n'
const ll mod = 1e9 + 7; //1000000007
const ll mod2 = 998244353;
const ll inf = LLONG_MAX;
const lld epsilon = 1e-12;
typedef pair<ll, ll> pl;
typedef pair<int, int> pi;
typedef pair<lld, lld> pd;
typedef vector<ll> vl;
typedef vector<pl> vpl;
typedef vector<vl> vvl;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
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

// ------------------------Do not write above this line-----------------------------------------------------------------------------------------------------------------
bool check(vl vec,ll mid){
    ll n=vec.size();
    for(int i=2;i<n;i++){
        if(vec[i-2]<mid){
            ll need=mid-vec[i-2];
            ll d=ceil(double(need)/(double)2);
            // cout<<d<<" ";
            vec[i]-=3*d;
            if(vec[i]<0){
                return 0;
            }
            vec[i-2]+=2*d;
            vec[i-1]+=d;
        }
    }

    for(int i=0;i<n;i++){
        if(vec[i]<mid){
            return 0;
        }
    }
    return 1;
}
void solve(){
    ll n;
    cin>>n;
    vl arr(n);
    ll mn=INT_MAX;
    ll mx=INT_MIN;
    rep(i,n){
        cin>>arr[i];
        mn=min(mn,arr[i]);
        mx=max(mx,arr[i]);
    }

    ll l=mn,r=mx;

    // cout<<mn<<" "<<mx<<nl;
    ll ans=1;
    while(l<=r){
        ll mid=(l+r)/2;
        vl temp=arr;
        bool f=check(temp,mid);
        if(f==1){
            ans=mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }

    cout<<ans<<nl;
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll t;
    t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}