#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline int chkmin(T &x, const T &y) {
  return x > y ? x = y, 1 : 0;
}
template <typename T>
inline int chkmax(T &x, const T &y) {
  return x < y ? x = y, 1 : 0;
}
template <typename T>
inline T read(T &f) {
  f = 0;
  int x = 1;
  char c = getchar();
  while (!isdigit(c)) x = c == '-' ? -1 : 1, c = getchar();
  while (isdigit(c)) (f *= 10) += c & 15, c = getchar();
  return f *= x;
}
using int64 = long long;
using uint64 = unsigned long long;
const int N = 2500000 + 5, MOD = 998244353;
int n;
struct Edge {
  int to;
  Edge *next;
} E[N << 1], *pre[N];
inline void addedge(int u, int v) {
  static int cnt = 0;
  E[++cnt] = (Edge){v, pre[u]}, pre[u] = E + cnt;
  E[++cnt] = (Edge){u, pre[v]}, pre[v] = E + cnt;
}
int d[N];
void dfs(int u, int fa) {
  for (Edge *i = pre[u]; i; i = i->next) {
    int v = i->to;
    if (v == fa) {
      continue;
    }
    dfs(v, u);
    ++d[u];
  }
}
namespace NTT {
const int N = 400000 + 5, KCZ = 998244353, G = 3;
long long mp(long long x, long long y = KCZ - 2) {
  long long res = 1;
  while (y) {
    if (y & 1) res = res * x % KCZ;
    x = x * x % KCZ;
    y >>= 1;
  }
  return res;
}
int rev[N], lim, l;
void makerev(int n) {
  for (lim = 1, l = 0; lim < n; lim <<= 1, l++)
    ;
  for (int i = (0), ___ = (lim - 1); i <= ___; ++i)
    rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (l - 1));
}
void set(long long *A, int n) {
  for (int i = (n), ___ = (lim - 1); i <= ___; ++i) A[i] = 0;
}
long long add(long long x, const long long &y) {
  x += y;
  if (x >= KCZ) x -= KCZ;
  return x;
}
long long sub(long long x, const long long &y) {
  x -= y;
  if (x < 0) x += KCZ;
  return x;
}
void NTT(long long *A, int lim, int op) {
  for (int i = (0), ___ = (lim - 1); i <= ___; ++i)
    if (i < rev[i]) std::swap(A[i], A[rev[i]]);
  for (int mid = 1; mid < lim; mid <<= 1) {
    long long Wn = mp(G, (KCZ - 1) / (mid << 1));
    for (int R = mid << 1, j = 0; j < lim; j += R) {
      long long *x = A + j, *y = x + mid, w = 1;
      for (int k = 0; k < mid; ++k) {
        long long u = *x, v = *y * w % KCZ;
        *x = add(u, v);
        *y = sub(u, v);
        ++x, ++y, w = w * Wn % KCZ;
      }
    }
  }
  if (op == -1) {
    long long ginv = mp(lim);
    std::reverse(A + 1, A + lim);
    for (int i = (0), ___ = (lim - 1); i <= ___; ++i) A[i] = A[i] * ginv % KCZ;
  }
}
long long A[N], B[N];
void solve(vector<long long> &arr, int l, int r) {
  if (l == r) {
    arr = {1, d[l]};
    return;
  }
  int mid = (l + r) >> 1;
  vector<long long> cl, cr;
  solve(cl, l, mid);
  solve(cr, mid + 1, r);
  makerev(r - l + 2);
  set(A, 0), set(B, 0);
  long long *x = A, *y = B;
  for (long long v : cl) *(x++) = v;
  for (long long v : cr) *(y++) = v;
  NTT(A, lim, 0), NTT(B, lim, 0);
  for (int i = (0), ___ = (lim - 1); i <= ___; ++i) {
    A[i] = A[i] * B[i] % KCZ;
  }
  NTT(A, lim, -1);
  for (int i = 0; i <= r - l + 1; i++) {
    arr.push_back(A[i]);
  }
}
}  // namespace NTT
int fac[N], inv[N];
inline int inc(const int &x) { return x >= MOD ? x - MOD : x; }
inline void add(int &x, const int &y) { x = inc(x + y); }
inline int dec(const int &x) { return x < 0 ? x + MOD : x; }
inline void sub(int &x, const int &y) { x = dec(x - y); }
int main() {
  read(n);
  for (int i = 1; i < n; i++) {
    static int u, v;
    read(u), read(v);
    addedge(u, v);
  }
  dfs(1, 0);
  vector<long long> Ans;
  NTT::solve(Ans, 1, n);
  int ans = 0;
  fac[0] = 1;
  for (int i = 1; i <= n; i++) {
    fac[i] = 1ll * fac[i - 1] * i % MOD;
  }
  for (int i = 0; i <= n; i++) {
    if (i % 2 == 0) {
      add(ans, 1ll * Ans[i] * fac[n - i] % MOD);
    } else {
      sub(ans, 1ll * Ans[i] * fac[n - i] % MOD);
    }
  }
  cout << ans << endl;
  return 0;
}
