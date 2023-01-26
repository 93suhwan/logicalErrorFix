#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
typedef unsigned long long ull;
typedef long double lld;
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007
#define endl  '\n'
#define MOD1 998244353
#define setbits(x)      __builtin_popcountll(x)
#define leadzerobits(x)      __builtin_clzll(x)
#define trailzerobits(x)      __builtin_ctzll(x)
#define INF 1e18
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.1415926535897932384626
#define sz(x) ((int)(x).size())
#define vs vector<string>
#define token(str,ch)	(std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;)
vs tokenizer(string str,char ch) {std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;}

#ifndef ONLINE_JUDGE
#define debug(x) cout << #x <<" "; _print(x); cout << endl;
#define debugarr(x,n) cout << #x <<" "; _print(x,n); cout << endl;
#else
#define debug(x)
#define debugarr(x,n)
#endif
void _print(ll t) {cout << t;}
//void _print(int t) {cout << t;}
void _print(string t) {cout << t;}
void _print(bool t) {cout << (t ? "True" : "False");}
void _print(char t) {cout << t;}
void _print(lld t) {cout << t;}
void _print(double t) {cout << t;}
void _print(ull t) {cout << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T,class V> void _print(T v[],V n);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T> void _print(multiset <T> v);
template <class T> void _print(unordered_set <T> v);
template <class T> void _print(unordered_multiset <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T, class V> void _print(multimap <T, V> v);
template <class T, class V> void _print(unordered_map <T, V> v);
template <class T, class V> void _print(unordered_multimap <T, V> v);
template <class T, class V> void _print(pair <T, V> p) {cout << "{"; _print(p.first); cout << ","; _print(p.second); cout << "}";}
template <class T,class V> void _print(T v[],V n) {cout << "[ "; for (V i=0;i<n;i++) {_print(v[i]); cout << " ";} cout << "]";}
template <class T> void _print(vector <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T> void _print(set <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T> void _print(multiset <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T> void _print(unordered_set <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T> void _print(unordered_multiset <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T, class V> void _print(map <T, V> v) {cout << "[ "; for (auto i : v) {_print(i); cout << " ";} cout << "]";}
template <class T, class V> void _print(multimap <T, V> v) {cout << "[ "; for (auto i : v) {_print(i); cout << " ";} cout << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cout << "[ "; for (auto i : v) {_print(i); cout << " ";} cout << "]";}
template <class T, class V> void _print(unordered_multimap <T, V> v) {cout << "[ "; for (auto i : v) {_print(i); cout << " ";} cout << "]";}

void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}



void solve()
{
    int n,k;
    cin>>n>>k;
    vector<pair<int,int>>v;
    vector<int>v1;
    bool free123[n+1]{0};
    
    for(int i=0;i<k;i++)
    {
        int a,b;cin>>a>>b;
        v.push_back({a,b});
        free123[a]=1;free123[b]=1;
        v1.push_back(a);
        v1.push_back(b);
    }
    sort(all(v1));
    int rem = n-k;
    int ans=0;
    ans+=(((n-k)*(n-k-1))/2);   // (n-k)C2
    
    for(int i=0;i<v.size();i++)
    {
        int a = v[i].first;
        int b = v[i].second;
        if(a>b)
        {
            swap(a,b);
        } // b -> max
        for(int j=i+1;j<v.size();j++)
        {
            int check=0;
            int a1 = v[j].first;
            int b1 = v[j].second;
            if(a1>a && a1<b)
            {
                check++;
            }
            if(b1>a && b1<b)
            {
                check++;
            }
            if(check==1)
            {
                ans++;
            }
            
        }
    }
    // debug(ans);
    // still we need to add min(x,y) as by UG (but here we specify we need to add for each chord)

    for(int i=0;i<v.size();i++)
    {
        int a = v[i].first;
        int b = v[i].second;
        if(a>b)
        {
            swap(a,b);
        }
        int x =0;
        for(int i=a;i<=b;i++)
        {
            if(free123[i]==0)
            {
                x++;
            }
        }
        int y = (2*(n-k))-x;
        // debug(x);
        // debug(y);
        ans+=(min(x,y)); 
    }
    cout<<ans<<endl;
    return;
}

int32_t main()
{
    fast_io();
    ll testcases=1;ll cse = 0;
    cin >> testcases;
    // InverseofNumber(MOD);InverseofFactorial(MOD);factorial(MOD); 
    while (testcases--)
    {
        //cse++;
        //cout<<"Case #"<<cse<<": ";
        //cout<<fixed<<setprecision(10)<< <<endl;
        solve();
    }
    return 0;
}


