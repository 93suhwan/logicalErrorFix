// #define INTLL
#define TESTS
// #define PREC
#include <cmath>
#include <functional>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <climits>
#include <map>
#include <stack>
#include <list>
#include <time.h>
#include <assert.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <chrono>
#include <cstring>
using namespace std;
#ifdef INTLL
#define        int               long long
#define        double            long long double
#endif
#define        ll                long long
#define        ld                long double
#define        pb                push_back
#define        mp                make_pair
#define        sz(v)             ((int)(v).size()) 
#define        nl                '\n'
#define        all(x)            (x).begin(),(x).end()
#define        sorta(x)          sort((x).begin(),(x).end())
#define        sortb(x)          sort((x).rbegin(),(x).rend())
#define        rall(x)           (x).rbegin(),(x).rend()
#define        rep(i,a,b)        for(int i=a;i<b;i++)
#define        per(i,a,b)        for(int i=b-1;i>=a;i--)
#define        trav(a,x)         for(auto &a:x)
#define        fs                first
#define        se                second
#define        vin(x)            trav(i,x){cin>>i;}
#define        sin(x,n)          rep(i,0,n){int ckf; cin >> ckf; x.insert(ckf);}
#define        vout(x)           trav(i,x){cout<<i<<' ';} cout << '\n';
#define        out(x)            cout << x;
#define        pout(a)           trav(i,a){cout << i.fs << '-' << i.se << '\n';}
#define        vec(a,v)          cin >> a; vi v; rep(i,0,a){cin >> v[i];}
#define        edgesin(m)        rep(i,0,m){int a,b; cin >> a >> b; --a; --b; adj[a].pb(b); adj[b].pb(a);}
typedef vector<int> vi;
typedef vector<pair<int,int>> vii;
typedef pair <int, int> pi;
typedef map<int, int> mi;
typedef set <int> si;
typedef set <pair<int,int>> sii;
typedef multiset <int> msi;
typedef multiset <pair<int,int>> msii;
template<typename... T>
void rd(T&... args) {
    ((cin >> args), ...);
}
template<typename... T>
void wr(T&&... args) {
    ((cout << args << ' '), ...);
}
template<typename... T>
void wt(T&&... args) {
    ((cout << args << '\n'), ...);
}
template<typename T,typename T1>T chkmax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T chkmin(T &a,T1 b){if(b<a)a=b;return a;}
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef nubskr
#define deb(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#define debv(a) cerr << #a << " : ("; trav(i,a){cerr << i << ',';}cerr << ')' << endl;
#define debp(a) cerr << #a << ": \n"; trav(i,a){cerr << i.fs << '-' << i.se << endl;}
#else
#define deb(...)
#define debv(a)
#define debp(a)
#endif

int vector_sum(vi v){
    int z = 0;
    trav(i,v){
        z+=i;
    }
    return z;
}

int gcd(int a, int b){
    return __gcd(a,b);
}

int lcm(int a, int b){
    return a*b/gcd(a,b);
}

const int MOD = 1e9 + 7;
// const int N = 1e5;

bool isprime(int n){
    if (n <= 1){
        return false;
    }
    if (n <= 3){
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0){
        return false;
    }
    for (int i = 5; i * i <= n; i = i + 6){
        if (n % i == 0 || n % (i + 2) == 0){
            return false;
        }
    }
    return true;
}

int modpower(int x,int y, int p = MOD){
    int res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1){
            res = (res * x) % p;
        }
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

// 1 3 4 2 2 3 1
void solve(int t){
    int n; cin >> n; vi v(n); vin(v);
    string s; cin >> s;
    priority_queue<pair<int,int>> zero;
    priority_queue<pair<int,int>> one;
    rep(i,0,n){
    	if(s[i]=='0'){
    		// cerr << 1;
    		zero.push({v[i],i});
    	}
    	else{
    		one.push({-v[i],i});
    	}
    }
    while(1){
    	if(!sz(zero) || sz(one)){
    		break;
    	}
    	int x = zero.top().fs;
    	int y = one.top().fs;
    	if(x<y){
    		break;
    	}
    	swap(v[(zero.top()).se],v[(one.top()).se]);
    	int a = zero.top().fs, b = zero.top().se;
    	int a1 = one.top().fs, b1 = one.top().se;
    	zero.pop();
    	one.pop();
    	one.push({-a,b});
    	one.push({-a1,b1});
    }
    trav(i,v){
    	cout << i << ' ';
    }
    cout << nl;
}

// Change approach if things start getting complicated
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef PREC
    prec();
#endif
    int t = 1;
#ifdef TESTS
cin >> t;
#endif
    while(t--){
        solve(t);
    }
#ifdef nubskr
    cerr << "\nTime Elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
#endif
    return 0;
}
