/* -----------------RISHABH VERMA------------*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/hash_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define FAST1 ios_base::sync_with_stdio(false);
#define FAST2 cin.tie(NULL);
#define ll long long
const ll M = 1e9 + 7;
#define sums accumulate

#define for_i(i, t, n) for (ll i = t; i < (ll)n; ++i)
#define for_j(j, i, n) for (ll j = i; j < (ll)n; ++j)
#define for_r(i, n, L, t) for (ll i = n - L; i >= t; --i)
#define for_s(i, vec) for (auto &i : vec)
#define dis(m) cout<<m<<endl
#define yes dis("YES")
#define no dis("NO")


#define all_v(vec) vec.begin(), vec.end()
#define all_a(vec, n) vec, vec + n
#define sz(v) (ll)(v.size())
#define mem(t,m) memset(t,m,sizeof t)
#define is_reverse greater<ll>

#define ve vector
#define se set

#define unmapll unordered_map<ll,ll>
#define unset unordered_set
#define pll pair<ll, ll>
#define mll map<ll, ll>
#define eb emplace_back
#define pqb priority_queue<ll>
#define pqs priority_queue<ll, ve<ll>, greater<ll>>
#define mnh priority_queue<pll, vector<pll>, greater<pll>>
#define setbits(res) __builtin_popcount(res)
#define pp pop_back
#define pb push_back
#define endl "\n"
#define mp make_pair

void __print(long t) {cerr << t;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {ll L = 0; cerr << '{'; for (auto &i : x) cerr << (L++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

void solve() {
    ll n;
    cin >> n;
    ve<ve<ll>> a(n, ve<ll>(2));
    vector<ll> t(n);
    set<ll> found;
    for_i(i, 1, n + 1)found.insert(i);
    for_i(i, 0, n) cin >> a[i][0] >> a[i][1];
    sort(all_v(a));

    for_i(i, 0, n)  {
        if (a[i][0] != a[i][1]) {
            for_i(j, a[i][0], a[i][1] + 1) {
                if (found.find(j) != found.end()) {
                    t[i] = j;
                    found.erase(t[i]);
                    break;
                }
            }
        }
        else {
            t[i] = a[i][0];
            found.erase(t[i]);
        }
    }
    for_i(i, 0, n) cout << a[i][0] << " " << a[i][1] << " " << t[i] << "\n";
    dis("");
}
int32_t main()
{
    ll t = 1;
    FAST1;
    FAST2;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}