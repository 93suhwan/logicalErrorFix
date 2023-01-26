#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vii = vector<pii>;
using vll = vector<pll>;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
vector<int> sieve;
void calc_sieve(int n) {
  sieve.reserve(n + 1);
  for (int i = 0, nnnn = (n + 1); i < nnnn; ++i) sieve[i] = i;
  for (int i = 2, nnnn = (n + 1); i < nnnn; ++i) {
    if (sieve[i] == i) {
      for (ll j = i * i; j <= n; j += i) {
        if (sieve[j] == j) sieve[j] = i;
      }
    }
  }
}
ll norm(ll a, ll P) {
  while (a >= P) a -= P;
  while (a < 0) a += P;
  return a;
}
ll mul_mod(ll a, ll b, ll P) { return a * b % P; }
ll pow_mod(ll a, ll b, ll P) {
  ll curr = a, ans = 1;
  while (b != 0) {
    if (b & 1) {
      ans *= curr;
      ans %= P;
    }
    curr *= curr;
    curr %= P;
    b >>= 1;
  }
  return ans;
}
ll inv_mod(ll a, ll P) { return pow_mod(a, P - 2ll, P); }
ll div_mod(ll a, ll b, ll P) { return a * inv_mod(b, P) % P; }
int msb(ll a) {
  for (int i = 62; i >= 0; i--) {
    if (a & ((ll)1 << i)) return i + 1;
  }
  return 0;
}
vector<ll> fact;
void calc_fact(int n, ll P) {
  if (fact.size() < 1) fact.push_back(1);
  for (int i = fact.size(), nnnn = (n + 1); i < nnnn; ++i)
    fact.push_back(fact[i - 1] * i % P);
}
vector<ll> fact_inv;
void calc_fact_inv(int n, ll P) {
  if (fact_inv.size() < 1) fact_inv.push_back(1);
  for (int i = fact_inv.size(), nnnn = (n + 1); i < nnnn; ++i)
    fact_inv.push_back(fact_inv[i - 1] * inv_mod(i, P) % P);
}
ll nCr(int n, int r, ll P) {
  if (r > n) return 0;
  calc_fact(n, P);
  calc_fact_inv(n, P);
  return (fact[n] * fact_inv[r] % P) * fact_inv[n - r] % P;
}
ll nCr_inv(int n, int r, ll P) {
  if (r > n) return 0;
  calc_fact(n, P);
  calc_fact_inv(n, P);
  return (fact_inv[n] * fact[r] % P) * fact[n - r] % P;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long double eps = 1e-9;
const long long mod = 1000000007;
const int MAXN = 100;
vector<int> adjlist[MAXN];
map<ll, ll> counter;
ll ans;
int n, k;
ll dfs(int curr, int dist, int p) {
  if (p == -1) {
    int c[MAXN], t[MAXN];
    memset(c, 0, sizeof c);
    memset(t, 0, sizeof t);
    for (int i : adjlist[curr]) {
      if (i != p) {
        counter.clear();
        dfs(i, dist + 1, curr);
        for (auto it = counter.begin(); it != counter.end(); ++it) {
          if (it->second > 0) c[it->first]++;
          t[it->first] += it->second;
        }
      }
    }
    ll ans = 0;
    for (int i = 0, nnnn = (MAXN); i < nnnn; ++i)
      ans += nCr(c[i], 2, mod) * nCr(t[i] - 2, k - 2, mod) % mod *
             inv_mod(k, mod) % mod,
          ans %= mod;
    return ans;
  } else {
    counter[dist]++;
    for (int i : adjlist[curr]) {
      if (i != p) {
        dfs(i, dist + 1, curr);
      }
    }
    return 0;
  }
}
void solve() {
  cin >> n >> k;
  for (int i = 0, nnnn = (n); i < nnnn; ++i) adjlist[i].clear();
  for (int i = 0, nnnn = (n - 1); i < nnnn; ++i) {
    int a, b;
    cin >> a >> b;
    adjlist[a - 1].push_back(b - 1);
    adjlist[b - 1].push_back(a - 1);
  }
  if (k == 2) {
    cout << (n - 1) * n / 2 << endl;
  } else {
    ans = 0;
    for (int i = 0, nnnn = (n); i < nnnn; ++i) {
      ans += dfs(i, 0, -1);
    }
    cout << ans % mod << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout << setprecision(12) << fixed;
  int t;
  cin >> t;
  while (t--) solve();
}
