#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const long long g = 3, gi = 332748118;
int rev[300000];
int d[250010];
int bit, tot;
long long qpow(long long a, long long p) {
  long long ans = 1ll;
  while (p) {
    if (p & 1) ans = ans * a % mod;
    a = a * a % mod;
    p >>= 1;
  }
  return ans % mod;
}
int n;
vector<long long> v;
long long jc[250010];
void ntt(vector<long long>& A, int opt) {
  long long x, y;
  for (int i = 0; i < tot; ++i)
    if (i < rev[i]) swap(A[i], A[rev[i]]);
  for (int mid = 1; mid < tot; mid <<= 1) {
    long long gn = qpow(opt == 1 ? g : gi, (mod - 1) / (mid << 1));
    for (int i = 0; i < tot; i += (mid << 1)) {
      long long g1 = 1;
      for (int j = 0; j < mid; ++j, g1 = g1 * gn % mod) {
        x = A[i + j], y = g1 * A[i + j + mid] % mod;
        A[i + j] = (x + y) % mod;
        A[i + j + mid] = (x - y + mod) % mod;
      }
    }
  }
  if (opt == -1) {
    long long inv = qpow(tot, mod - 2);
    for (int i = 0; i < tot; ++i) A[i] = A[i] * inv % mod;
  }
}
vector<long long> operator*(vector<long long> A, vector<long long> B) {
  int len = A.size() + B.size() - 1;
  bit = 0;
  while ((1 << bit) < (len)) bit++;
  tot = 1 << bit;
  for (int i = 0; i < tot; ++i)
    rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (bit - 1));
  A.resize(tot);
  B.resize(tot);
  ntt(A, 1);
  ntt(B, 1);
  for (int i = 0; i < tot; ++i) A[i] = A[i] * B[i] % mod;
  ntt(A, -1);
  A.resize(len);
  return A;
}
vector<long long> work(int l, int r) {
  if (l == r) {
    return {1, d[l] - (l != 1)};
  }
  return work(l, (l + r) / 2) * work((l + r) / 2 + 1, r);
}
void run() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int main() {
  run();
  cin >> n;
  jc[0] = 1;
  for (int i = 1; i <= n; ++i) jc[i] = i * jc[i - 1] % mod;
  int uu, vv;
  for (int i = 1; i < n; ++i) {
    cin >> uu >> vv;
    d[uu]++;
    d[vv]++;
  }
  v = work(1, n);
  long long ans = 0;
  for (int i = n - 1; i >= 0; --i) {
    if (i & 1)
      ans = (ans - v[i] * jc[n - i] % mod + mod) % mod;
    else
      ans = (ans + v[i] * jc[n - i] % mod) % mod;
  }
  cout << ans << endl;
}
