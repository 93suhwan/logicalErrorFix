#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
class NTT {
 private:
  const int mod = 998244353;
  int root_pw;
  int roots[30];
  int inv_roots[30];
  int powmod(int n, int h) {
    return h ? h & 1 ? 1ll * powmod(1ll * n * n % mod, h >> 1) * n % mod
                     : powmod(1ll * n * n % mod, h >> 1)
             : 1;
  }
  int primitive_root(int m) {
    if (m == 2) return 1;
    vector<int> div = {2};
    int n = m - 1;
    n >>= __builtin_ctz(n);
    for (int i = 2; i * i <= n; i++) {
      while (n % i == 0) {
        div.push_back(i);
        while (n % i == 0) n /= i;
      }
    }
    if (n != 1) div.push_back(n);
    for (int i = 2; i < m; i++) {
      bool ok = true;
      for (int &x : div) {
        if (powmod(i, (m - 1) / x) == 1) {
          ok = false;
          break;
        }
      }
      if (ok) {
        return i;
      }
    }
    return -1;
  }
  void init() {
    root_pw = __builtin_ctz(mod - 1);
    roots[root_pw] =
        powmod(primitive_root(mod), (mod - 1) >> __builtin_ctz(mod - 1));
    inv_roots[root_pw] = powmod(roots[root_pw], mod - 2);
    for (int i = root_pw - 1; i >= 0; i--) {
      roots[i] = 1ll * roots[i + 1] * roots[i + 1] % mod;
      inv_roots[i] = 1ll * inv_roots[i + 1] * inv_roots[i + 1] % mod;
    }
  }
  void ntt(vector<int> &p, bool invert) {
    int n = (int)p.size(), bits = 31 - __builtin_clz((int)p.size());
    for (int i = 0; i < n; i++) {
      int j = 0;
      for (int k = 0; k < bits; k++) {
        j <<= 1;
        if (i & (1 << k)) j |= 1;
      }
      if (i < j) swap(p[i], p[j]);
    }
    for (int i = 2; i <= n; i <<= 1) {
      int r = __builtin_ctz(i);
      int w1 = invert ? inv_roots[r] : roots[r];
      for (int j = 0; j < n; j += i) {
        int w = 1;
        for (int k = j; k < j + (i >> 1); k++) {
          int a = p[k], b = 1ll * w * p[k + (i >> 1)] % mod;
          p[k] = a + b < mod ? a + b : a + b - mod;
          p[k + (i >> 1)] = a - b > 0 ? a - b : a - b + mod;
          w = 1ll * w * w1 % mod;
        }
      }
    }
    if (invert) {
      int inv = powmod(n, mod - 2);
      for (int i = 0; i < n; i++) {
        p[i] = 1ll * p[i] * inv % mod;
        if (p[i] < 0) p[i] += mod;
      }
    }
  }
  int get_degree(int n) {
    int x = 1;
    while (x < n) x <<= 1;
    return x;
  }

 public:
  NTT() { init(); }
  NTT(int mod) : mod(mod) { init(); }
  vector<int> multiply(vector<int> p1, vector<int> p2) {
    int deg = (int)p1.size() + (int)p2.size() - 1;
    int n = get_degree(deg);
    p1.resize(n, 0);
    p2.resize(n, 0);
    ntt(p1, false);
    ntt(p2, false);
    for (int i = 0; i < n; i++) p1[i] = 1ll * p1[i] * p2[i] % mod;
    ntt(p1, true);
    p1.resize(deg);
    return p1;
  }
  const int get_mod() const { return mod; }
};
NTT polymult;
const int maxn = (int)25e4 + 1;
long long fakt[maxn];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  fakt[0] = 1;
  for (int i = 1; i < maxn; i++) fakt[i] = fakt[i - 1] * i % mod;
  int n;
  cin >> n;
  vector<int> fok(n, -1);
  fok[0] = 0;
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    fok[x]++;
    fok[y]++;
  }
  vector<vector<int>> polys(n);
  for (int i = 0; i < n; i++) {
    polys[i] = {fok[i], 1};
  }
  while (polys.size() > 1) {
    vector<vector<int>> tmp;
    for (int i = 0; i < (int)polys.size() - 1; i += 2)
      tmp.push_back(polymult.multiply(polys[i], polys[i + 1]));
    if (polys.size() % 2 == 1) tmp.push_back(polys.back());
    swap(tmp, polys);
  }
  vector<int> v = polys[0];
  reverse(v.begin(), v.end());
  long long meg = 0;
  for (int i = 0; i < n; i++) {
    if (i & 1) {
      meg = (meg - (long long)v[i] * fakt[n - i]) % mod;
    } else {
      meg = (meg + (long long)v[i] * fakt[n - i]) % mod;
    }
  }
  if (meg < 0) meg += mod;
  cout << meg << '\n';
  return 0;
}
