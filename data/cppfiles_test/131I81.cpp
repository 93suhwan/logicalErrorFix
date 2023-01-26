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
const int N = 6000001;
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
int a[N], use[N], vis[N], f[N], pre[N], mrk[N];
int tot = 0;
int ans, ansp, ansq;
inline void dfs(int x) {
  int Max1 = -1, Max2 = -1, P1 = 0, P2 = 0;
  if (f[x]) Max1 = 0, P1 = x;
  for (auto y : G[x]) {
    dfs(y);
    if (f[y] >= 0)
      if (f[y] + 1 > Max1)
        Max2 = Max1, P2 = P1, Max1 = f[y] + 1, P1 = pre[y];
      else if (f[y] + 1 > Max2)
        Max2 = f[y] + 1, P2 = pre[y];
  }
  if (Max2 >= 0 && Max1 + Max2 > ans) ans = Max1 + Max2, ansp = P1, ansq = P2;
  f[x] = Max1;
  pre[x] = P1;
}
void solve() {
  cin >> n;
  mp[0] = ++tot;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    mp[a[i]] = ++tot;
    mrk[tot] = i;
    vis[tot] = 1;
  }
  for (int i = 1; i <= n; i++) {
    int x = a[i];
    while (x) {
      int y = 1;
      for (; y < x; y *= 2)
        ;
      int z = y - x;
      if (!mp.count(z)) mp[z] = ++tot;
      G[mp[z]].insert(mp[x]);
      x = z;
    }
  }
  memset(f, 128, sizeof f);
  dfs(1);
  cout << mrk[ansp] << ' ' << mrk[ansq] << ' ' << ans << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  cout << fixed << setprecision(8);
  while (TT--) solve();
  return 0;
}
