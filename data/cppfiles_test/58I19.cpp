#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int mod = 998244353;
namespace math {
int inc(int x, int y) { return x + y >= mod ? x + y - mod : x + y; }
int qpow(int a, int x, int mo) {
  int res = 1;
  while (x) {
    if (x & 1) res = 1ll * res * a % mod;
    a = 1ll * a * a % mod;
    x >>= 1;
  }
  return res;
}
vector<int> Fac, invFac;
void Finit(int n) {
  Fac.resize(n + 1);
  invFac.resize(n + 1);
  Fac[0] = 1;
  invFac[0] = 1;
  for (int i = 1; i <= n; i++) Fac[i] = 1ll * Fac[i - 1] * i % mod;
  invFac[n] = qpow(Fac[n], mod - 2, mod);
  for (int i = n - 1; i >= 1; i--)
    invFac[i] = 1ll * invFac[i + 1] * (i + 1) % mod;
}
int C(int n, int m) {
  if (m == 0) return 1;
  if (n < m || m < 0) return 0;
  return (int)(1ll * Fac[n] * invFac[m] % mod * invFac[n - m] % mod);
}
int A(int n, int m) {
  if (n < m || m < 0) return 0;
  return (int)(1ll * Fac[n] * invFac[n - m] % mod);
}
}  // namespace math
using namespace math;
std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
struct FHQ {
  int ls[N], rs[N], siz[N], key[N], val[N], tag[N];
  int tcnt;
  int root;
  int Newnode(int x) {
    siz[++tcnt] = 1;
    val[tcnt] = x;
    key[tcnt] = rnd();
    tag[tcnt] = 0;
    ls[tcnt] = rs[tcnt] = 0;
    return tcnt;
  }
  void pushup(int pos) { siz[pos] = siz[ls[pos]] + siz[rs[pos]] + 1; }
  void split(int pos, int v, int &ll, int &rr) {
    if (!pos) {
      ll = 0, rr = 0;
      return;
    }
    if (siz[ls[pos]] + 1 <= v) {
      ll = pos;
      split(rs[pos], v - siz[ls[pos]] - 1, rs[pos], rr);
    } else {
      rr = pos;
      split(ls[pos], v, ll, ls[pos]);
    }
    pushup(pos);
  }
  int merge(int l, int r) {
    if (!l || !r) return l + r;
    if (key[l] < key[r]) {
      rs[l] = merge(rs[l], r);
      pushup(l);
      return l;
    } else {
      ls[r] = merge(l, ls[r]);
      pushup(r);
      return r;
    }
  }
  void init(int n) {
    for (int i = 0; i <= n; i++) {
      int pos = Newnode(i);
      root = merge(root, pos);
    }
  }
  void print(int pos) {
    if (!pos) return;
    print(ls[pos]);
    if (val[pos] <= 8) cout << val[pos] << " ";
    print(rs[pos]);
  }
} t;
void solve() {
  int n, m;
  cin >> n >> m;
  set<int> ans;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    int a, b, c, d, e;
    t.split(t.root, v + 1, b, c);
    t.split(b, v, a, b);
    t.split(c, u - v, c, e);
    t.split(c, u - v - 1, c, d);
    ans.insert(t.val[b]);
    t.root = t.merge(t.merge(a, d), t.merge(b, t.merge(c, e)));
  }
  cout << ans.size() << endl;
  cout << C(2 * n - 1 - ans.size(), n) << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int M = 2e5;
  math::Finit(M * 2);
  t.init(M);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
}
