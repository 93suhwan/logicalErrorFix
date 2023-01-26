#include <bits/stdc++.h>
using namespace std;
template <class T>
istream& operator>>(istream& is, vector<T>& v) {
  for (T& x : v) is >> x;
  return is;
}
template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  if (!v.empty()) {
    os << v.front();
    for (int i = 1; i < (int)v.size(); ++i) os << ' ' << v[i];
  }
  return os;
}
void dbg_out() { cerr << "\b\b )" << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << H << ", ";
  dbg_out(T...);
}
mt19937 myrand(chrono::steady_clock::now().time_since_epoch().count());
const int N = 2e6 + 10;
const int M = 1e5 + 10;
const int INF = 2147483647;
const long long MOD = 1e9 + 7;
int TT = 1;
long long gcd(long long x, long long y) { return y == 0 ? x : gcd(y, x % y); }
long long qpow(long long base, long long x, long long mod = MOD) {
  long long res = 1;
  while (x) {
    if (x & 1) res = (res * base) % mod;
    base = (base * base) % mod;
    x >>= 1;
  }
  return res;
}
long long exgcd(long long a, long long b, long long& x, long long& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long d = exgcd(b, a % b, y, x);
  y -= a / b * x;
  return d;
}
int norm(int x) { return x >= MOD ? x - MOD : x; }
void add(int& x, int y) {
  if ((x += y) >= MOD) x -= MOD;
}
void sub(int& x, int y) {
  if ((x -= y) < 0) x += MOD;
}
int n;
set<int> G[N];
map<int, int> mp;
int a[N], use[N], vis[N], f[N], pre[N];
int tot = 0;
int ans, ansp, ansq;
int getid(int x) {
  if (mp.count(x)) return mp[x];
  ++tot;
  mp[x] = tot;
  return tot;
}
void dfs(int u) {
  int mx1 = -1, mx2 = -1, p = -1, q = -1;
  if (vis[u] == 1) {
    mx1 = 0;
    p = u;
  }
  for (auto v : G[u]) {
    dfs(v);
    if (f[v] + 1 > mx1) {
      q = p;
      p = pre[v];
      mx2 = mx1;
      mx1 = f[v] + 1;
    } else if (f[v] + 1 > mx2) {
      mx2 = f[v] + 1;
      q = pre[v];
    }
  }
  if (mx2 >= 0 && mx1 + mx2 > ans) {
    ans = mx1 + mx2;
    ansp = p;
    ansq = q;
  }
  f[u] = mx1;
  pre[u] = p;
}
void solve() {
  cin >> n;
  mp[0] = ++tot;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    mp[a[i]] = ++tot;
    vis[tot] = 1;
  }
  for (int i = 1; i <= n; i++) {
    int cnt = 0, p = 30;
    use[++cnt] = a[i];
    while (use[cnt] != 0) {
      int x = use[cnt];
      while (p > 0 && (1 << p) - x >= x) --p;
      use[++cnt] = (1 << p) - x;
    }
    for (int j = cnt; j > 1; j--) G[getid(use[j])].insert(getid(use[j - 1]));
  }
  dfs(1);
  cout << ansp << ' ' << ansq << ' ' << ans << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  cout << fixed << setprecision(8);
  while (TT--) solve();
  return 0;
}
