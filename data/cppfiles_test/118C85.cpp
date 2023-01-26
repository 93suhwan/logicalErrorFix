#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1e3 + 7;
const int MOD = 998244353;
long long poww(long long x, int y) {
  long long ret = 1;
  while (y) {
    if (y & 1) ret *= x, ret %= MOD;
    x *= x, x %= MOD;
    y >>= 1;
  }
  return ret;
}
namespace NTT {
const int g = 3, ig = (MOD + 1) / 3;
const int MAXN = 1e6;
inline long long inv(long long x) { return poww(x, MOD - 2); }
int R[MAXN];
void fft(vector<long long> &a, int L, int ty) {
  for (int i = 0; i < L; i++) i > R[i] ? swap(a[i], a[R[i]]) : void(0);
  for (int i = 1; i < L; i <<= 1) {
    long long w = poww(ty, (MOD - 1) / (i << 1));
    for (int j = 0; j < L; j += (i << 1)) {
      long long wn = 1;
      for (int k = j; k < i + j; k++) {
        long long t = wn * a[i + k] % MOD;
        a[i + k] = a[k] - t;
        a[i + k] < 0 ? a[i + k] += MOD : 0;
        a[k] += t;
        a[k] >= MOD ? a[k] -= MOD : 0;
        wn = wn * w % MOD;
      }
    }
  }
}
vector<long long> mul(vector<long long> A, vector<long long> B) {
  int L = 1, n = A.size() - 1, m = B.size() - 1;
  while (L <= n + m) L <<= 1;
  A.resize(L);
  B.resize(L);
  for (int i = 1; i < L; i <<= 1)
    for (int j = 0; j < i; j++) R[i + j] = R[j] + L / (i << 1);
  fft(A, L, g);
  fft(B, L, g);
  vector<long long> ret(L);
  for (int i = 0; i < L; i++) ret[i] = A[i] * B[i] % MOD;
  fft(ret, L, ig);
  long long invL = inv(L);
  for (int i = 0; i < L; i++) ret[i] = ret[i] * invL % MOD;
  ret.resize(n + m + 1);
  return ret;
}
}  // namespace NTT
vector<long long> fun[N];
vector<long long> gao(int l, int r) {
  if (l == r) return fun[l];
  int mid = (l + r) / 2;
  return NTT::mul(gao(l, mid), gao(mid + 1, r));
}
int vis[N];
long long fac[N], ifac[N];
long long C(int n, int m) { return fac[n] * ifac[m] % MOD * ifac[n - m] % MOD; }
int a[N];
int main() {
  ios_base::sync_with_stdio(false);
  fac[0] = 1;
  for (int i = 1; i <= N - 1; i++) fac[i] = fac[i - 1] * i % MOD;
  ifac[N - 1] = poww(fac[N - 1], MOD - 2);
  for (int i = N - 1; i >= 1; i--) ifac[i - 1] = ifac[i] * i % MOD;
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    a[u]++;
    a[v]++;
  }
  int top = 0;
  for (int i = 1; i <= n; i++) {
    top++;
    fun[top].resize(2);
    fun[top][0] = 1;
    fun[top][1] = a[i] - (i != 1);
  }
  auto tans = gao(1, top);
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans = (ans +
           1ll * (i % 2 == 0 ? 1 : MOD - 1) * fac[n - i] % MOD * tans[i] % MOD);
  }
  cout << ans % MOD << endl;
  return 0;
}
