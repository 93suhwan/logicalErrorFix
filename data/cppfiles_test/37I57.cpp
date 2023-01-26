#include <bits/stdc++.h>
using namespace std;
template <typename T>
void rd(T& x) {
  int f = 0, c;
  while (!isdigit(c = getchar())) f ^= !(c ^ 45);
  x = (c & 15);
  while (isdigit(c = getchar())) x = x * 10 + (c & 15);
  if (f) x = -x;
}
template <typename T>
void pt(T x, int c = -1) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) pt(x / 10);
  putchar(x % 10 + 48);
  if (c != -1) putchar(c);
}
const int P = 998244353;
int ad(int k1, int k2) { return k1 += k2 - P, k1 += k1 >> 31 & P; }
int su(int k1, int k2) { return k1 -= k2, k1 += k1 >> 31 & P; }
int mu(int k1, int k2) { return 1LL * k1 * k2 % P; }
void uad(int& k1, int k2) { k1 += k2 - P, k1 += k1 >> 31 & P; }
void usu(int& k1, int k2) { k1 -= k2, k1 += k1 >> 31 & P; }
template <typename... T>
int ad(int k1, T... k2) {
  return ad(k1, ad(k2...));
}
template <typename... T>
void uad(int& k1, T... k2) {
  return uad(k1, ad(k2...));
}
template <typename... T>
void usu(int& k1, T... k2) {
  return usu(k1, ad(k2...));
}
template <typename... T>
int mu(int k1, T... k2) {
  return mu(k1, mu(k2...));
}
int po(int k1, int k2) {
  int k3 = 1;
  for (; k2; k2 >>= 1, k1 = mu(k1, k1))
    if (k2 & 1) k3 = mu(k3, k1);
  return k3;
}
namespace ntt {
int base = 1, root = -1, maxbase = -1;
std::vector<int> roots = {0, 1}, rev = {0, 1};
void init() {
  int tmp = P - 1;
  maxbase = 0;
  while (!(tmp & 1)) tmp >>= 1, maxbase++;
  root = 2;
  while (1) {
    if (po(root, 1 << maxbase) == 1 && po(root, 1 << (maxbase - 1)) != 1) break;
    root++;
  }
}
void ensure_base(int nbase) {
  if (maxbase == -1) init();
  if (nbase <= base) return;
  rev.resize(1 << nbase);
  for (int i = 1; i < (1 << nbase); ++i)
    rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (nbase - 1));
  roots.resize(1 << nbase);
  while (base < nbase) {
    int z = po(root, 1 << (maxbase - base - 1));
    for (int i = (1 << (base - 1)); i < (1 << base); ++i)
      roots[i << 1] = roots[i], roots[i << 1 | 1] = mu(roots[i], z);
    base++;
  }
}
void dft(std::vector<int>& a) {
  int n = a.size(), zeros = __builtin_ctz(n);
  ensure_base(zeros);
  int shift = base - zeros;
  for (int i = 0; i < n; ++i)
    if (i < (rev[i] >> shift)) std::swap(a[i], a[rev[i] >> shift]);
  for (int mid = 1; mid < n; mid <<= 1)
    for (int i = 0; i < n; i += (mid << 1))
      for (int j = 0; j < mid; ++j) {
        int x = a[i + j], y = mu(a[i + j + mid], roots[mid + j]);
        a[i + j] = ad(x, y);
        a[i + j + mid] = su(x, y);
      }
}
std::vector<int> operator*(std::vector<int> a, std::vector<int> b) {
  if (((int)(a).size()) <= 50 && ((int)(b).size()) <= 50) {
    vector<int> c(((int)(a).size()) + ((int)(b).size()) - 1);
    for (int i = (0); i <= (((int)(a).size()) - 1); ++i)
      for (int j = (0); j <= (((int)(b).size()) - 1); ++j)
        uad(c[i + j], mu(a[i], b[j]));
    return c;
  }
  int need = a.size() + b.size() - 1, nbase = 0;
  while ((1 << nbase) < need) nbase++;
  ensure_base(nbase);
  int size = 1 << nbase;
  a.resize(size);
  b.resize(size);
  dft(a);
  dft(b);
  int inv = po(size, P - 2);
  for (int i = 0; i < size; ++i) a[i] = mu(a[i], mu(b[i], inv));
  std::reverse(a.begin() + 1, a.end());
  dft(a);
  a.resize(need);
  return a;
}
}  // namespace ntt
using ntt::operator*;
const int N = 100005;
int T, n, K, deg[N], f[N], dp[N][2];
int pp, lnk[N], nxt[N * 2], to[N * 2];
vector<int> e;
void ae(int k1, int k2) { to[++pp] = k2, nxt[pp] = lnk[k1], lnk[k1] = pp; }
vector<int> prod(int l, int r) {
  if (l == r) {
    if (K == 1) return {ad(dp[e[l]][1], dp[e[l]][0])};
    return {dp[e[l]][1], dp[e[l]][0]};
  }
  int mid = (l + r) >> 1;
  auto res = prod(l, mid) * prod(mid + 1, r);
  while (((int)(res).size()) > K) {
    uad(res[((int)(res).size()) - 1 - K], res.back());
    res.pop_back();
  }
  return res;
}
void dfs(int k1, int k2) {
  for (int i = lnk[k1]; i; i = nxt[i])
    if (to[i] != k2) {
      dfs(to[i], k1);
    }
  dp[k1][0] = dp[k1][1] = 0;
  if (deg[k1] >= K) {
    e.clear();
    int pos = 0, val = 1;
    for (int i = lnk[k1]; i; i = nxt[i])
      if (to[i] != k2) {
        if (dp[to[i]][1] == 0) {
          if (++pos == K) pos = 0;
          val = mu(val, dp[to[i]][0]);
        } else
          e.push_back(to[i]);
      }
    if (e.empty()) {
      dp[k1][0] = pos == 0 ? val : 0, dp[k1][1] = pos == K - 1 ? val : 0;
    } else {
      auto v = prod(0, ((int)(e).size()) - 1);
      dp[k1][0] = v[(K - pos) % K], dp[k1][1] = v[(K - 1 - pos) % K];
    }
  } else {
    dp[k1][0] = 1;
    for (int i = lnk[k1]; i; i = nxt[i])
      if (to[i] != k2) {
        dp[k1][0] = mu(dp[k1][0], dp[to[i]][1]);
      }
  }
}
int main() {
  rd(T);
  while (T--) {
    rd(n);
    for (int i = (1); i <= (n); ++i) lnk[i] = 0, deg[i] = 0, f[i] = 0;
    pp = 0;
    for (int i = (2); i <= (n); ++i) {
      int k1, k2;
      rd(k1), rd(k2);
      ae(k1, k2), ae(k2, k1);
      ++deg[k1], ++deg[k2];
    }
    int lim = n;
    for (int k1 = (1); k1 <= (n); ++k1)
      for (int i = lnk[k1]; i; i = nxt[i]) {
        lim = min(lim, max(deg[k1], deg[to[i]]));
      }
    for (K = 1; K <= lim; ++K)
      if ((n - 1) * 2 % K == 0) {
        ((void)0);
        dfs(1, 0);
        f[K] = dp[1][0];
      }
    for (int i = (lim); i >= (1); --i) {
      for (int j = i + i; j <= lim; j += i) {
        usu(f[i], f[j]);
      }
    }
    for (int i = (1); i <= (n); ++i) pt(f[i], i == n ? '\n' : ' ');
  }
  return 0;
}
