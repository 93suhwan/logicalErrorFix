#include <bits/stdc++.h>
#include <x86intrin.h>
#include <ext/pb_ds/assoc_container.hpp>

// Defines
#define F               first
#define S               second
#define endl            "\n"
#define NO              "NO\n"
#define YES             "YES\n"
#define elif            else if
#define mp              make_pair
#define pp              pop_back
#define pb              push_back
#define int             long long
#define ld              long double
#define lb              lower_bound
#define ub              upper_bound
#define pii             pair<int,int>
#define sz(x)           int32_t(x.size())
#define all(x)          x.begin(),x.end()
#define rall(x)         x.rbegin(),x.rend()
#define pll             pair<long long,long long>
#define FOR(i,a,b)      for(int i = (a); i <= (b); i++)
#define REV(i,a,b)      for(int i = (a); i >= (b); i--)
#define precal(x)       fixed << setprecision(x)
#define IOS             ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define FILE            freopen("max.in", "r", stdin);freopen("max.out", "w", stdout)

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

// Constants
const int LOG = 23;
const int N = 400+23;
const int MOD = 1e9+7;
const int B = 318;
const long long INF = 2e18+1703;
const int dx[10] = {0,0,1,-1,0};
const int dy[10] = {0,1,0,0,-1};

//  [x-1,y-1] [x-1,y] [x-1,y+1];
//  [x,y-1]   [x, y]  [x,y+1];
//  [x+1,y-1] [x+1,y] [x+1,y+1];

// Functions
long long bp(long long a,long long b){
    long long res = 1;
    while(b > 0){
        if(b&1)res = (res*a)%MOD, b--;
        a = (a*a)%MOD, b >>= 1;
    }
    return res;
}
bool bit(long long x,int p){
    return (x >> p)&1;
}
long long gcd(long long a,long long b){
    return __gcd(a,b);
}
long long lcm(long long a,long long b){
    return (a*b)/__gcd(a,b);
}
bool prime(long long x){
    if((!(x&1) && x > 2) || (x <= 1))return 0;
    for(long long d = 3; d*d <= x; d += 2){
        if(!(x%d))return 0;
    }
    return 1;
}

/*
    CHECK LIMITS FOR -> N, MOD, INF ;)

    Don't forget this:
    Greedy, Dp, Tree, Dsu, Binary search, Bitmask, Brute Force, Data structures, Sort, Graphs, Games tactics, Graph matchings, Number theory, Shortest paths

    Bit operations:
    1) 1^1 = 0, 0^0 = 0, 1^0 = 1, 0^1 = 0
    2) 1&1 = 1, 0&0 = 0, 1&0 = 0, 0&1 = 0
    3) 1|1 = 1, 0|0 = 0, 1|0 = 1, 0|1 = 1

    Tricks to solve:
    1) Reverse the problem
    2) If it equation try to remake in a better way
    3) Draw some tests and solve them by drawing
    4) Maybe there is a regularity?
    5) Try from the opposite to prove the greediness
    6) You can use prefix, suffix arrays and solve with them
    7) Offline or online solutions?
*/

int n,m;
char a[N][N];
int pre[N][N],ver[N][N],hor[N][N];
int check(int i1,int i2,int j1,int j2){
    int res = pre[i2-1][j2-1]-(pre[i1][j2-1]+pre[i2-1][j1])+pre[i1][j1];
    res += (j2-j1-1)-(hor[i1][j2-1]-hor[i1][j1]);
    res += (j2-j1-1)-(hor[i2][j2-1]-hor[i2][j1]);
    res += (i2-i1-1)-(ver[i2-1][j1]-ver[i1][j1]);
    res += (i2-i1-1)-(ver[i2-1][j2]-ver[i1][j2]);
    return res;
}
void solve(){
    cin >> n >> m;
    FOR(i,1,n){
        FOR(j,1,m){
            cin >> a[i][j];
            pre[i][j] = pre[i][j-1]+(a[i][j] != '0');
            hor[i][j] = hor[i][j-1]+(a[i][j] != '0');
            ver[i][j] = ver[i-1][j]+(a[i][j] != '0');
        }
        FOR(j,1,m){
            pre[i][j] += pre[i-1][j];
        }
    }
    int ans = INF;
    FOR(i1,1,n){
        FOR(j1,1,m){
            FOR(i2,i1+4,n){
                if(j1+3 <= m){
                    int j2 = j1+3;
                    ans = min(ans,check(i1,i2,j1,j2));
                }
            }
        }
    }
    cout << ans << endl;
}
int32_t main(){
    IOS;
    int test_cases = 1; cin >> test_cases;
    while(test_cases--){
        solve();
    }
    return 0;
}
