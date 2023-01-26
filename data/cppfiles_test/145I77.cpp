#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <random>
#include <chrono>
#include <ctime>
#include <unordered_map>
#include <queue>
#include <stack>
#include <deque>
#include <iomanip>
#include <map>
#include <cassert>
#include <functional>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using str = string;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using ld = long double;
const ld PI = acos(-1);

#define all(c) ((c).begin()), ((c).end())
#define ff first
#define ss second
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0)
#define debug(x) cerr<<#x<<": "<<x<<endl;
#define mp make_pair
#define forn(i, n) for (ll i = 0; i < n; ++i)
#define sz(a) (ll)a.size()


#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")


ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnd(31313121);
str Y = "YES\n";
str N = "NO\n";
const ll INF = 2e18 + 10;
const ll Mod = 1e9 + 7;
const ll Maxn = 2e5 + 10;

vll gr[Maxn];
bool used[Maxn];
ll tim[Maxn];
set<pll> timer;

void dfs(ll v) {
    used[v] = true;
    if (timer.contains({tim[v], v})) timer.erase({tim[v], v});
    for (ll adj : gr[v]) {
        if (!used[adj]) dfs(adj);
    }
}

void solve() {
    map<ll, vector<pll>> x;
    map<ll, vector<pll>> y;
    ll n, k;
    cin >> n >> k;
    forn (i, n) gr[i].clear();
    fill(used, used + n, false);
    timer.clear();
    forn (i, n) {
        ll xx, yy;
        ll t;
        cin >> xx >> yy;
        cin >> t;
        x[xx].pb({yy, i});
        y[yy].pb({xx, i});
        timer.insert({t, i});
        tim[i] = t;
    }
    for (auto [id, xs] : x) {
        sort(all(xs));
        forn (i, sz(xs) - 1) {
            if (xs[i + 1].ff - xs[i].ff <= k) {
                gr[xs[i + 1].ss].pb(xs[i].ss);
                gr[xs[i].ss].pb(xs[i + 1].ss);
            }
        }
    }

    for (auto [id, ys] : y) {
        sort(all(ys));
        forn (i, sz(ys) - 1) {
            if (ys[i + 1].ff - ys[i].ff <= k) {
                gr[ys[i + 1].ss].pb(ys[i].ss);
                gr[ys[i].ss].pb(ys[i + 1].ss);
            }
        }
    }
    ll ans = 0;
    while (!timer.empty()) {
        auto it = timer.end();
        --it;
        ll i = (*it).ss;
        if (!used[i]) {
            dfs(i);
        }
        while (!timer.empty() && (*timer.begin()).ff == ans) {
            dfs((*timer.begin()).ss);
        }
        ++ans;
    }
    cout << ans - 1 << '\n';
}

int main() {
    fast;
    ll t;
    cin >> t;
    forn (i, t) {
        solve();
    }
    return 0;
}