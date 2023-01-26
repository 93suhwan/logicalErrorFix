#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ld long double
#define ull unsigned long long
#define ll long long
#define pb push_back
#define ppb pop_back
#define eb emplace_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fast_io cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0)

using namespace std;

#define dbg(args...) { cout << '\n'; string _s = #args; \
replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); \
istream_iterator<string> _it(_ss); err(_it, args); }
void err(const istream_iterator<string>& it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << '\n';
  err(++it, args...);
}
#define show_time cerr << '\n' << "Time execute: " \
<< clock() / (double)CLOCKS_PER_SEC << " sec" << '\n';

//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("O3")

using namespace __gnu_pbds;
typedef tree<ll, null_type, less_equal<>, rb_tree_tag,
    tree_order_statistics_node_update> ordered_set;

ld eps = (ld) 1 / 1e6;
ll inf_ll = 1e18 + 1, mod1 = 1e9 + 7, mod2 = 998244353;
ll mersen_mod = 2305843009213693951;

ll sqr(ll a) { return a * a; }
ll qb(ll a) { return a * a * a; }
ll gcd(ll a, ll b) { return !a ? b : gcd(b % a, a); }
ll add(ll a, ll b, ll mod) {
  a += b;
  if (a >= mod) a -= mod;
  return a;
}
ll sub(ll a, ll b, ll mod) {
  a -= b;
  if (a < 0) a += mod;
  return a;
}
ll binpow(ll a, ll b, ll mod) {
  return b ? (b % 2 ? (a * (sqr(binpow(a, b / 2, mod)) % mod)) % mod :
              sqr(binpow(a, b / 2, mod)) % mod) : 1;
}
ll binmult(ll a, ll b, ll mod) {
  return b ? (b % 2 ? (2 * binmult(a, b / 2, mod) + a) % mod :
              (2 * binmult(a, b / 2, mod)) % mod) : 0;
}

/// Code here
const ll N = 3e5 + 5;
ll a[N], ans[N], new_st[4 * N], lim = 3e5;
struct node { ll rzm, v, st, d; };
node seg_tree[4 * N];
ordered_set os;
void push(ll v) {
  seg_tree[2 * v].st += seg_tree[v].st;
  seg_tree[2 * v].d += seg_tree[v].d;
  seg_tree[2 * v + 1].st += seg_tree[v].st + seg_tree[2 * v].rzm * seg_tree[v].d;
  seg_tree[2 * v + 1].d += seg_tree[v].d;
  seg_tree[v].st = seg_tree[v].d = 0;
}
void build(ll l, ll r, ll v) {
  seg_tree[v].rzm = r - l + 1;
  if (l == r) return;
  ll m = (l + r) / 2;
  build(l, m, 2 * v);
  build(m + 1, r, 2 * v + 1);
}
void update(ll l, ll r, ll tl, ll tr, ll v, ll start, ll dist) {
  if (l == tl && r == tr) {
    seg_tree[v].st += start;
    seg_tree[v].d += dist;
    return;
  }
  push(v);
  ll m = (l + r) / 2;
  if (tr <= m) update(l, m, tl, tr, 2 * v, start, dist);
  else if (tl > m) update(m + 1, r, tl, tr, 2 * v + 1, start, dist);
  else {
    update(l, m, tl, m, 2 * v, start, dist);
    update(m + 1, r, m + 1, tr, 2 * v + 1, start + seg_tree[2 * v].rzm * dist, dist);
  }
}
ll get(ll l, ll r, ll v, ll pos) {
  if (l == r) return seg_tree[v].st;
  push(v);
  ll m = (l + r) / 2;
  if (pos <= m) return get(l, m, 2 * v, pos);
  else return get(m + 1, r, 2 * v + 1, pos);
}
void update1(ll l, ll r, ll v, ll pos) {
  if (l == r) {
    new_st[v] += l;
    return;
  }
  ll m = (l + r) / 2;
  if (pos <= m) update1(l, m, 2 * v, pos);
  else update1(m + 1, r, 2 * v + 1, pos);
  new_st[v] = new_st[2 * v] + new_st[2 * v + 1];
}
ll get1(ll l, ll r, ll tl, ll tr, ll v) {
  if (l == tl && r == tr) return new_st[v];
  ll m = (l + r ) / 2;
  if (tr <= m) return get1(l, m, tl, tr, 2 * v);
  else if (tl > m) return get1(m + 1, r, tl, tr, 2 * v + 1);
  else return get1(l, m, tl, m, 2 * v) + get1(m + 1, r, m + 1, tr, 2 * v + 1);
}

int main() {
  fast_io;
  ll n, i, j;
  cin >> n;
  for (i = 1; i <= n; i++) cin >> a[i];
  build(1, lim, 1);
  for (i = 1; i <= n; i++) {
    ans[i] = (i - os.order_of_key(a[i]) - 1) * a[i] + get(1, lim, 1, a[i]);
    ans[i] += get1(1, lim, 1, a[i], 1) + get1(1, lim, a[i], lim, 1) % a[i];
//    cout << (i - os.order_of_key(a[i]) - 1) * a[i] << '\n';
//    cout << get(1, lim, 1, a[i]) << '\n';
//    cout << get1(1, lim, 1, a[i], 1) << '\n';
//    cout << get1(1, lim, a[i], lim, 1) % mod1 << '\n';
//    cout << '\n';
    if (a[i] > 1) {
      for (j = a[i] + 1; j <= lim; j += a[i]) {
        update(1, lim, j, min(lim, j + a[i] - 2), 1, 1, 1);
      }
    }
    update1(1, lim, 1, a[i]);
    os.insert(a[i]);
  }
  for (i = 1; i <= n; i++) ans[i] += ans[i - 1];
  for (i = 1; i <= n; i++) cout << ans[i] << ' ';
  return 0;
}