#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void Read(T &x) {
  int c = getchar();
  bool f = false;
  for (x = 0; !isdigit(c); c = getchar())
    if (c == '-') f = true;
  for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
  if (f) x = -x;
}
inline int read() {
  int s = 0, ch = getchar(), w = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
  return s * w;
}
inline long long Read() {
  long long s = 0;
  int ch = getchar(), w = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
  return s * w;
}
inline void swap(int &x, int &y) { x ^= y ^= x ^= y; }
const int kcz = 998244353;
const int G = 3, GI = 332748118;
inline int qpow(int x, int y = kcz - 2) {
  int ret = 1;
  while (y) {
    if (y & 1) ret = int(1ll * (ret) * (x) % kcz);
    x = int(1ll * (x) * (x) % kcz), y >>= 1;
  }
  return ret;
}
inline int qpow(int x, int y, const int &ljc) {
  int ret = 1;
  while (y) {
    if (y & 1) ret = int(1ll * ret * x % ljc);
    x = int(1ll * x * x % ljc), y >>= 1;
  }
  return ret;
}
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int N = 4e5 + 10;
namespace MAIN {
int n;
vector<int> V[N];
int du[N];
void dfs(int x, int fax) {
  for (auto tox : V[x]) {
    if (tox == fax) continue;
    du[x]++, dfs(tox, x);
  }
}
int Og[N], pos[N];
inline void FFT(vector<int> &A, const int &type, const int &lim) {
  for (int i = 0; i < lim; i++)
    if (i < pos[i]) swap(A[i], A[pos[i]]);
  for (int mid = 1; mid < lim; mid <<= 1) {
    int wn = qpow(type == 1 ? G : GI, (kcz - 1) / (mid << 1));
    Og[0] = 1;
    for (int i = 1; i < mid; i++) Og[i] = int(1ll * (Og[i - 1]) * (wn) % kcz);
    for (int j = 0; j < lim; j += mid << 1)
      for (int k = 0; k < mid; k++) {
        int x = A[j + k], y = int(1ll * (A[j + mid + k]) * (Og[k]) % kcz);
        A[j + k] = ((x) + (y) >= kcz ? (x) + (y)-kcz : (x) + (y)),
              A[j + mid + k] = ((x) + (kcz - y) >= kcz ? (x) + (kcz - y) - kcz
                                                       : (x) + (kcz - y));
      }
  }
  if (type == -1) {
    int INV = qpow(lim, kcz - 2);
    for (int i = 0; i < lim; i++) A[i] = int(1ll * (A[i]) * (INV) % kcz);
  }
}
vector<int> solve(int l, int r) {
  if (l == r) {
    vector<int> A;
    A.push_back(1), A.push_back(du[l]);
    return A;
  }
  int mid = (l + r) >> 1;
  vector<int> L = solve(l, mid), R = solve(mid + 1, r);
  int lim = 1, qaq = 0;
  while (lim <= r - l + 1) lim <<= 1, qaq++;
  for (int i = 0; i < lim; i++)
    pos[i] = (pos[i >> 1] >> 1) | ((i & 1) << (qaq - 1));
  for (int i = mid - l + 2; i < lim; i++) L.push_back(0);
  for (int i = r - mid + 1; i < lim; i++) R.push_back(0);
  FFT(L, 1, lim), FFT(R, 1, lim);
  vector<int> aqua(lim);
  for (int i = 0; i < lim; i++) aqua[i] = int(1ll * (L[i]) * (R[i]) % kcz);
  FFT(aqua, -1, lim), aqua.resize(r - l + 2);
  return aqua;
}
int fac[N], f[N];
inline void MAIN() {
  fac[0] = fac[1] = 1, n = read();
  for (int i = 2; i <= n; i++) fac[i] = int(1ll * (fac[i - 1]) * (i) % kcz);
  for (int i = 1; i < n; i++) {
    int u = read(), v = read();
    V[u].push_back(v), V[v].push_back(u);
  }
  dfs(1, 0);
  vector<int> aqua = solve(1, n);
  for (int i = 0; i <= n; i++) f[i] = int(1ll * (aqua[i]) * (fac[n - i]) % kcz);
  int ans = 0;
  for (int i = 0, cur = 1; i <= n; i++, cur ^= 1)
    ((ans) += (cur ? f[i] : kcz - f[i]), (ans) >= kcz ? (ans) -= kcz : 1);
  printf("%d\n", ans);
}
}  // namespace MAIN
int main() {
  int Case = 1;
  while (Case--) MAIN::MAIN();
  return 0;
}
