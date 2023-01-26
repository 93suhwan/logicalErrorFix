#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while ((c < '0' || c > '9') && (c != '-')) c = getchar();
  if (c == '-') f = -1, c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x * f;
}
namespace Poly {
const int mod = 998244353;
inline int Add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline int Del(int a, int b) { return a >= b ? a - b : a + mod - b; }
inline int power(int a, int b) {
  int ret = 1;
  for (; b; b >>= 1, a = 1ll * a * a % mod)
    if (b & 1) ret = 1ll * ret * a % mod;
  return ret;
}
inline int Get(int x) {
  int ret = 1;
  while (ret < x) ret <<= 1;
  return ret;
}
vector<int> pos, w;
inline void init(int n) {
  pos.resize(n), w.resize(n);
  for (int i = (0); i <= (n - 1); i++)
    pos[i] = (pos[i >> 1] >> 1) | ((i & 1) * (n >> 1));
  for (int i = 1; i < n; i <<= 1) {
    int wn = power(3, (mod - 1) / i / 2);
    w[i] = 1;
    for (int j = (1); j <= (i - 1); j++)
      w[j + i] = 1ll * w[j + i - 1] * wn % mod;
  }
}
inline void DFT(vector<int> &F, int n) {
  F.resize(n);
  for (int i = (0); i <= (n - 1); i++)
    if (i < pos[i]) swap(F[i], F[pos[i]]);
  for (int i = 1; i < n; i <<= 1)
    for (int j = 0; j < n; j += i << 1)
      for (int k = 0; k < i; k++) {
        int x = F[j + k], y = 1ll * F[j + k + i] * w[i + k] % mod;
        F[j + k] = Add(x, y), F[j + k + i] = Del(x, y);
      }
}
inline void IDFT(vector<int> &F, int n) {
  DFT(F, n), reverse(F.begin() + 1, F.end());
  for (int i = 0, inv = power(n, mod - 2); i < n; i++)
    F[i] = 1ll * F[i] * inv % mod;
}
inline vector<int> Del(vector<int> A, vector<int> B) {
  int n = max(A.size(), B.size());
  vector<int> ret(n);
  A.resize(n), B.resize(n);
  for (int i = (0); i <= (n - 1); i++) ret[i] = Del(A[i], B[i]);
  return ret;
}
inline vector<int> Add(vector<int> A, vector<int> B) {
  int n = max(A.size(), B.size());
  vector<int> ret(n);
  A.resize(n), B.resize(n);
  for (int i = (0); i <= (n - 1); i++) ret[i] = Add(A[i], B[i]);
  return ret;
}
inline vector<int> Mul(vector<int> A, vector<int> B) {
  if (A.size() <= 20 || B.size() <= 20) {
    vector<int> ret;
    ret.resize(A.size() + B.size() - 1);
    for (int i = (0); i < (((int)(A).size())); i++)
      for (int j = (0); j < (((int)(B).size())); j++)
        ret[i + j] = Add(ret[i + j], 1ll * A[i] * B[j] % mod);
    return ret;
  }
  int n = A.size() + B.size() - 1, m = Get(n);
  init(m);
  DFT(A, m), DFT(B, m);
  for (int i = (0); i <= (m - 1); i++) A[i] = 1ll * A[i] * B[i] % mod;
  return IDFT(A, m), A.resize(n), A;
}
inline vector<int> Inv(const vector<int> &F, int n) {
  if (n == 1) return {power(F[0], mod - 2)};
  vector<int> G = Inv(F, n + 1 >> 1), tmp(F.begin(), F.begin() + n);
  int m = Get(n * 2 - 1);
  init(m);
  DFT(G, m), DFT(tmp, m);
  for (int i = (0); i <= (m - 1); i++)
    G[i] = 1ll * Del(2, 1ll * G[i] * tmp[i] % mod) * G[i] % mod;
  return IDFT(G, m), G.resize(n), G;
}
}  // namespace Poly
const int mod = 998244353;
pair<vector<int>, int> solve(int n, int m) {
  if (!m) {
    vector<int> F(n + 1);
    return F[0] = 1, make_pair(F, 0);
  }
  auto [tmp, ans] = solve(n, m / 2);
  vector<int> odd(n + 1), even(n + 1);
  for (int i = (0); i <= (n); i++)
    if (i & 1)
      odd[i] = tmp[i];
    else
      even[i] = tmp[i];
  odd[1] = (m + 1) / 2;
  vector<int> F(n + 1);
  F[0] = 1;
  for (int i = (1); i <= (n); i++) F[i] = mod - odd[i];
  F = Poly::Inv(F, n + 1);
  if (n % 2 == 0)
    ans = (ans * 2ll + F[n]) % mod;
  else
    ans = F[n];
  for (int i = (1); i <= (n); i++)
    if (i & 1) ans = (ans + 1ll * odd[i] * (i - 1) % mod * F[n - i]) % mod;
  vector<int> G = Poly::Mul(Poly::Mul(even, even), F);
  G.resize(n + 1);
  G = Poly::Add(G, odd);
  return make_pair(G, ans);
}
int main() {
  int n = read(), m = read();
  printf("%d\n", solve(n, m).second);
}
