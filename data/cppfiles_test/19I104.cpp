/**
    author: _Octal_
    created: 30.09.2021


    ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
    ░░░░░░░░░░▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄░░░░░░░░░
    ░░░░░░░░▄▀░░░░░░░░░░░░▄░░░░░░░▀▄░░░░░░░
    ░░░░░░░░█░░▄░░░░▄░░░░░░░░░░░░░░█░░░░░░░
    ░░░░░░░░█░░░░░░░░░░░░▄█▄▄░░▄░░░█░▄▄▄░░░
    ░▄▄▄▄▄░░█░░░░░░▀░░░░▀█░░▀▄░░░░░█▀▀░██░░
    ░██▄▀██▄█░░░▄░░░░░░░██░░░░▀▀▀▀▀░░░░██░░
    ░░▀██▄▀██░░░░░░░░▀░██▀░░░░░░░░░░░░░▀██░
    ░░░░▀████░▀░░░░▄░░░██░░░▄█░░░░▄░▄█░░██░
    ░░░░░░░▀█░░░░▄░░░░░██░░░░▄░░░▄░░▄░░░██░
    ░░░░░░░▄█▄░░░░░░░░░░░▀▄░░▀▀▀▀▀▀▀▀░░▄▀░░
    ░░░░░░█▀▀█████████▀▀▀▀████████████▀░░░░
    ░░░░░░████▀░░███▀░░░░░░▀███░░▀██▀░░░░░░
    ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
**/

#include <bits/stdc++.h>

using namespace std;

#define PLEASE_ACCEPT ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

//#define FILE_IO

#pragma GCC target ("arch=sandybridge")
#pragma GCC target ("popcnt")
#pragma comment(linker, "/STACK:16777216")

//#define lol_set

#ifdef lol_set
    // this hate "#define int long long"
    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>
    using namespace __gnu_pbds;
    typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
    /**
        ordered_set o_set;
        find_by_order; //give ind, get elem
        order_of_key;  //give elem, get ind
    **/
#endif // lol_set

#define endl '\n'
#define pb push_back
#define pf push_front
#define mp make_pair
#define F first
#define S second
#define all(q) (q).begin(), (q).end()
#define __pop(q, k) q.erase(q.begin()+k)
#define gcd __gcd
#define flush fflush(stdout)
#define debug cout << "lol\n"

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
typedef pair <int, int> Pair;
const long double pi = 3.14159265;
const int MOD = 1e9+7;
const int INF = INT_MAX;

int to_digit(string s){
    stringstream ss(s);
    int ans;
    ss >> ans;
    return ans;
}

int lcm(int x, int y){
    return x/gcd(x, y)*y;
}

void solve() {
    ll n;
    cin >> n;
    vector <ll> q(n+1);
    for (ll i=1; i<=n; i++) cin >> q[i];
    vector <vector <ll>> dp(n+1, vector <ll> (1100, INF));
    for (ll i=0; i<=1000; i++) dp[0][i]=i;
    for (ll i=1; i<=n; i++){
        for (ll j=0; j<=1000; j++){
            if (j-q[i]>=0) dp[i][j]=min(dp[i][j], max(j, dp[i-1][j-q[i]]));
            if (j+q[i]<=1000) dp[i][j]=min(dp[i][j], max(j, dp[i-1][j+q[i]]));
        }
    }
    ll ans=INF;
    for (ll i=0; i<=1000; i++) ans=min(ans, dp[n][i]);
    cout << ans << endl;
    return;
}

signed main(){
    #ifdef FILE_IO
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        PLEASE_ACCEPT;
    #endif
    cout << fixed << setprecision(12);
    int t=1;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}
