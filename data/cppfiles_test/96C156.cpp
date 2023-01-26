#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353, N = 500 + 10;
inline ll add(ll a, ll b, ll mod = MOD) {
  a += b;
  return a >= mod ? a - mod : a;
}
inline ll sub(ll a, ll b, ll mod = MOD) {
  a -= b;
  return a < 0 ? a + mod : a;
}
inline ll mul(ll a, ll b, ll mod = MOD) { return ll((long long)a * b % mod); }
inline ll power(ll base, long long ex, ll mod = MOD) {
  ll res = 1;
  for (; ex > 0; ex >>= 1) {
    if (ex & 1) res = mul(res, base, mod);
    base = mul(base, base, mod);
  }
  return res;
}
inline ll inv(ll a, ll mod = MOD) { return power(a, mod - 2, mod); }
inline ll mdiv(ll a, ll b, ll mod = MOD) {
  return mul(a, power(b, mod - 2, mod));
}
inline void adds(ll &a, ll b, ll mod = MOD) {
  a += b;
  if (a >= mod) a -= mod;
}
inline void subs(ll &a, ll b, ll mod = MOD) {
  a -= b;
  if (a < 0) a += mod;
}
inline void muls(ll &a, ll b, ll mod = MOD) { a = ll((long long)a * b % mod); }
inline void mdivs(ll &a, ll b, ll mod = MOD) { a = mdiv(a, b, mod); }
vector<ll> fact, ifact;
void prep_fact(ll mx = 1e6 + 40) {
  fact.assign(mx, 0);
  ifact.assign(mx, 0);
  fact[0] = 1;
  for (ll i = 1; i < mx; ++i) fact[i] = mul(i, fact[i - 1]);
  ifact[mx - 1] = inv(fact[mx - 1]);
  for (ll i = mx - 1; i > 0; --i) ifact[i - 1] = mul(i, ifact[i]);
}
inline ll ncr(ll n, ll r) {
  if (n < r || r < 0 || n < 0) return 0;
  return mul(fact[n], mul(ifact[n - r], ifact[r]));
}
ll n, x;
ll dp[N][N];
ll dfs(ll alive, ll low) {
  if (alive == 0) return 1;
  if (low > x) return 0;
  if (alive < 0) return 0;
  ll &ans = dp[alive][low];
  if (ans != -1) return ans;
  ll damage = (alive - 1);
  ans = 0;
  for (ll rem = 0; rem <= alive; ++rem) {
    if (rem == 1) continue;
    ll kill = alive - rem;
    ll val = dfs(rem, low + alive - 1);
    muls(val, power(min(alive - 1, x - low + 1), kill));
    muls(val, ncr(alive, rem));
    adds(ans, val);
  }
  return ans;
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  prep_fact();
  cin >> n >> x;
  memset(dp, -1, sizeof dp);
  cout << dfs(n, 1) << '\n';
  return 0;
}
