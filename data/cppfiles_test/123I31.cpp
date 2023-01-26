#include <bits/stdc++.h>
using namespace std;
const long long Mod = 998244353;
long long poww(long long a, long long b, long long mod) {
  long long res = 1;
  if (b < 0 || b >= Mod) b = (b % (mod - 1) + mod - 1) % (mod - 1);
  for (; b; b >>= 1, a = 1ll * a * a % mod)
    if (b & 1) res = 1ll * res * a % mod;
  return res;
}
void Max(long long& x, long long y) { x = max(x, y); }
void Min(long long& x, long long y) { x = min(x, y); }
void OK(bool yes) { cout << (yes ? "YES\n" : "NO\n"); }
const long long N = 500300, M = 2010, LN = (1 << 24), K = 17, inf = 3e18,
                Mod1 = 1e9 + 7, Mod2 = 999997457;
const long double pi = acos(-1), eps = 1e-12;
long long Fact[N], iFact[N];
void init() {
  Fact[0] = iFact[0] = 1ll;
  for (long long i = 1; i < N; i++) Fact[i] = (1ll * Fact[i - 1] * i) % Mod;
  iFact[N - 1] = poww(Fact[N - 1], -1, Mod);
  for (long long i = N - 2; i; i--)
    iFact[i] = (1ll * iFact[i + 1] * (i + 1)) % Mod;
}
long long Cnk(long long x, long long y) {
  if (y > x) return 0;
  return (((Fact[x] * poww(Fact[y], -1, Mod)) % Mod) *
          poww(Fact[x - y], -1, Mod)) %
         Mod;
}
void Add(long long& x, long long y, long long j = 0) {
  long long mod = Mod;
  if (j == 1) mod = Mod1;
  if (j == 2) mod = Mod2;
  x %= mod;
  y %= mod;
  if (x < 0) x += mod;
  if (y < 0) y += mod;
  x = (x + y >= mod ? x + y - mod : x + y);
}
long long vis[N], par[N];
vector<long long> v[N], block;
vector<pair<long long, long long> > leaves;
void dfs(long long x, long long p = -1, long long dep = 1) {
  par[x] = p;
  if (x != 1 && v[x].size() == 1) leaves.push_back({x, dep + 1});
  for (auto pp : v[x]) {
    if (pp == p) continue;
    dfs(pp, x, dep + 1);
  }
}
bool cmp1(pair<long long, long long> x, pair<long long, long long> y) {
  return x.second > y.second;
}
long long cal(long long x) {
  if (vis[x]) return 0;
  vis[x] = 1;
  if (x == 1) return 1;
  return 1 + cal(par[x]);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  long long T = 1;
  long long Case = 1;
  while (T--) {
    long long n, k;
    cin >> n >> k;
    long long w = 0;
    for (int i = 1; i < n; i++) {
      long long x, y;
      cin >> x >> y;
      v[x].push_back(y);
      v[y].push_back(x);
    }
    dfs(1);
    if (k >= leaves.size()) {
      long long Ans = 0;
      for (long long i = 1; i <= n; i++) {
        Max(Ans, 1ll * i * (n - i));
      }
      cout << Ans << '\n';
      break;
    }
    sort(leaves.begin(), leaves.end(), cmp1);
    for (auto p : leaves) {
      long long b = cal(p.first);
      block.push_back(b);
    }
    sort(block.begin(), block.end());
    reverse(block.begin(), block.end());
    long long r = k;
    for (int i = 0; i < k; i++) {
      w += block[i] - 1;
    }
    long long Ans = w * (r - (n - r - w));
    for (int i = 0; i <= (n - w - r); i++) {
      Min(Ans, (n - r - i) * (r - (i)));
    }
    cout << Ans << '\n';
  }
  return 0;
}
