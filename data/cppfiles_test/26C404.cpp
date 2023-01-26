#include <bits/stdc++.h>
using namespace std;
const double PI = 3.141592653589793;
const int Mod[] = {998244353, (int)1e9 + 7, 1223456789, 1234567891, 2147483647};
const int mod = Mod[1];
const int N = 2e6 + 5;
const int NN = 1e7 + 5;
const int M = 1e3 + 5;
const int MM = 1e4;
const long long oo = 9223372036854775807ll;
typedef bool (*func)(int &, int);
typedef bool (*funcl)(long long &, long long);
template <class t>
bool add(t &x, t y) {
  x += y;
  if (x >= mod) {
    x -= mod;
    return 0;
  }
  return 1;
}
template <class t>
bool mius(t &x, t y) {
  x -= y;
  if (x < 0) {
    x += mod;
    return 0;
  }
  return 1;
}
template <class t>
bool mini(t &x, t y) {
  if (x > y) {
    x = y;
    return 1;
  }
  return 0;
}
template <class t>
bool maxi(t &x, t y) {
  if (x < y) {
    x = y;
    return 1;
  }
  return 0;
}
template <class t>
bool doxor(t &x, t y) {
  x ^= y;
  return (x > 0);
}
template <class T>
class DSU {
 private:
  T n;
  vector<T> cha;

 public:
  DSU(const T &n = 0) : n(n + 7), cha(n + 7, -1) {}
  T root(T u) { return (cha[u] < 0 ? u : cha[u] = root(cha[u])); }
  bool join(T u, T v) {
    if ((v = root(v)) == (u = root(u))) return 0;
    if (cha[u] > cha[v]) swap(u, v);
    cha[u] += cha[v];
    cha[v] = u;
    return 1;
  }
};
template <class T, class TT, class up>
class FenWick {
 private:
  T n;
  TT init;
  vector<TT> bit;
  up update;

 public:
  FenWick(const T &n = 0, const up &update = nullptr, const TT &init = 0)
      : n(n + 7), init(init), bit(n + 7, init), update(update) {}
  void adj(T x, TT val) {
    for (; x <= n; x += x & -x) update(bit[x], val);
  }
  TT get(T x) {
    TT res = init;
    for (; x > 0; x -= x & -x) update(res, bit[x]);
    return res;
  }
};
void file(string name = "") {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  return;
}
long long gt[N], rgt[N];
long long power(long long a, long long b) {
  if (b == 0) return 1ll;
  if (b == 1) return a;
  long long tam = 1ll * power(a, b / 2);
  tam = 1ll * tam * tam % mod;
  if (b & 1) return 1ll * tam * a % mod;
  return tam;
}
void prepare() {
  gt[0] = 1;
  for (int i = 1; i <= N; i++) gt[i] = 1ll * gt[i - 1] * i % mod;
}
int nCk(int n, int k) {
  return 1ll * gt[n] * power(gt[n - k], mod - 2) % mod * power(gt[k], mod - 2) %
         mod;
}
void solve(int test = -1) {
  int n;
  cin >> n;
  long long res = 1;
  for (int i = 1; i <= n; i++) {
    res *= n * 2 - i;
    res %= mod;
  }
  res *= gt[n];
  res %= mod;
  cout << res;
  return;
}
int32_t main() {
  file();
  int T = 1;
  prepare();
  cin >> T;
  for (int i = 1; i <= T; i++) {
    solve(i);
    cout << '\n';
  }
  return 0;
}
