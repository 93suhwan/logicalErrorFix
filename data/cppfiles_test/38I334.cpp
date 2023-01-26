#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define gcd __gcd
#define grt(x) greater<x>
#define mx3 INT32_MAX
#define mn3 INT32_MIN
#define mx6 INT64_MAX
#define mn6 INT64_MIN
#define pi 3.141592653589793238462
#define all(x) (x).begin(), (x).end()
#define mset(x,y) memset(x,y,sizeof(x))
#define setcnt(x) __builtin_popcount(x)
#define setcntll(x) __builtin_popcountll(x)

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
 
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
#else
#define debug(x);
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
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]\n";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

const int M = 1000000007;

long long modpow(long long a,long long b){
    long long res=1;
    while(b>0){
        if(b&1)
        res = (res*a)%M;
        a = (a*a)%M;
        b = b>>1;
    }
    return res;
}
long long power(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
ll lcm(ll a,ll b){
    return ((a*b)/gcd(a,b));
}

/*-----------------------------------------------------------------------------------------------------*/



int main(){
    #ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /*--------------------------------------------------------------------------------------------------*/
    
    int n,m,i,j;
    cin>>n>>m;

    string arr[n];

    for(i=0 ; i<n ; i++)
    cin>>arr[i];

    vector<int>v(m,0);

    for(j=0 ; j<m-1 ; j++){
        bool chk = false;
        if(arr[0][j+1]=='X')
        chk = true;

        for(i=1 ; i<n ; i++){
            if(arr[i][j]=='X' && chk){
                v[j]++;
                break;
            }
            if(arr[i][j+1]=='X')
            chk = true;
        } 
    }

    for(i=1 ; i<m ; i++)
    v[i] += v[i-1];

    debug(v);

    int q,x1,x2;
    cin>>q;

    while(q--){
        cin>>x1>>x2;
        if(x2==1){
            cout<<"YES"<<endl;
            continue;
        }
        if(x1==1){
            if(v[x2-2])
            cout<<"NO\n";
            else
            cout<<"YES\n";
            continue;
        }
        if(v[x2-2]-v[x1-2])
        cout<<"NO\n";
        else
        cout<<"YES\n";
    }

    return 0;
}

//segment-tree

//exchange-argument ,game-theory

//the net ninja,traversy media,code blocks(arnav gupta),hitesh chaudhary.

//ford fulkerson's algo ,z algo,kmp,rolling hash.