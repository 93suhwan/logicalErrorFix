#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <ctime>
#include <vector>
#include <set>
#include <iterator>
#include <map>
#include <functional>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <queue>
#include <deque>
#include <time.h>
#include <bitset>
#include <tuple>
#include <random>
#include <chrono>

#pragma GCC optimize("O3")

#define ll long long
#define ld long double
#define y1 abc
#define endl '\n'
#define fi first
#define se second
#define m_p make_pair
#define m_t make_tuple
#define pb push_back
#define pf push_front
#define INF 9000000000000000000LL
#define inf 2000000000
#define pll pair < ll, ll >
#define pii pair < int, int >

using namespace std;
using namespace __gnu_pbds;

typedef tree< int, null_type, less< int >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

const ld pi = acos(-1);
const ll md = 998244353;
clock_t start_time = clock();

ll n, i, ef, bf, bw, bb, ew, eb, ans, fact[200501], cb, cw, c1, c2, c3, c4;

string s;

ll mod(ll a)
{
    if (a < 0) return (a % md) + md;
    else return a % md;
}

ll bin_pow(ll a, ll b)
{
    ll res = 1;
    while (b > 0){
        if (b & 1) res = (res * a) % md;
        b >>= 1;
        a = (a * a) % md;
    }
    return res;
}

ll C(ll n, ll k)
{
    if (k > n || k < 0) return 0;
    return (((fact[n] * bin_pow(fact[k], md - 2)) % md) * bin_pow(fact[n - k], md - 2)) % md;
}

void solve()
{
    cin >> n;

    fact[0] = 1;
    c2 = 1;
    for (i = 1; i <= 2 * n; i++){
        fact[i] = (fact[i - 1] * i) % md;
    }

    for (i = 1; i <= n; i++){
        cin >> s;
        cb += (s[0] == 'B') + (s[1] == 'B');
        cw += (s[0] == 'W') + (s[1] == 'W');
        if (s == "WW" || s == "BB") c1++;
        if (s == "??") c2 = mod(c2 * 2);
        if (s == "?W" || s == "B?" || s == "BW") c3++;
        if (s == "?B" || s == "W?" || s == "WB") c4++;
    }

    if (cb > n || cw > n){
        cout << 0 << endl;
        return;
    }
    ans = C(n * 2 - cb - cw, n - cb);

    if (!c1){
        ans = mod(ans - c2);
        if (c3 == 0 || c4 == 0) ans = mod(ans + 1);
    }

    cout << ans << endl;
}

int main()
{
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
//        freopen("dreamrun.in", "r", stdin);
//        freopen("dreamrun.out", "w", stdout);
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    ll q = 1;
//    cin >> q;

    while (q--){
        solve();
    }

    #ifdef LOCAL
        cout << endl;
        cout << "Time = " << (ld)(clock() - start_time) / CLOCKS_PER_SEC << endl;
    #endif

    return 0;
}
