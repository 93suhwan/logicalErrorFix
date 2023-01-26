#include <bits/stdc++.h>
using namespace std;
const int G = 3;
const int Gi = 332748118;
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
vector<long long> v;
long long jc[250010];
long long su(long long a, long long b) {
  a += b;
  return (a >= mod) ? a - mod : a;
}
void ntt(vector<long long> &A, int type) {
  for (int i = 0; i <= tot - 1; ++i) {
    if (i < rev[i]) swap(A[i], A[rev[i]]);
  }
  for (int mid = 1; mid <= tot - 1; mid <<= 1) {
    long long Wn = qpow(type == 1 ? G : Gi, (mod - 1) / (mid << 1));
    for (int j = 0; j <= tot - 1; j += (mid << 1)) {
      long long w = 1;
      for (int k = 0; k <= mid - 1; ++k, w = (w * Wn) % mod) {
        int x = A[j + k];
        int y = w * A[j + mid + k] % mod;
        A[j + k] = su(x, y);
        A[j + mid + k] = su(x, mod - y);
      }
    }
  }
  if (type == -1) {
    long long tmp = qpow(tot, mod - 2);
    for (int i = 0; i <= tot - 1; ++i) {
      A[i] = A[i] * tmp % mod;
    }
  }
}
vector<long long> operator*(vector<long long> A, vector<long long> B) {
  int len = A.size() + B.size() - 1;
  tot = 1;
  while (tot <= len) tot <<= 1;
  for (int i = 0; i <= tot - 1; ++i) {
    rev[i] = (rev[i >> 1] >> 1) | ((i & 1) * (tot >> 1));
  }
  A.resize(tot);
  B.resize(tot);
  ntt(A, 1);
  ntt(B, 1);
  for (int i = 0; i <= tot - 1; ++i) {
    A[i] = A[i] * B[i] % mod;
  }
  ntt(A, -1);
  A.resize(len);
  return A;
}
int i, j, k, n, m, t, a[250005];
vector<long long> work(int l, int r) {
  if (l == r) {
    return {1, d[l] - (l != 1)};
  }
  return work(l, (l + r) / 2) * work((l + r) / 2 + 1, r);
}
int main() {
  jc[0] = 1;
  for (i = 1; i <= 250000; i++) {
    jc[i] = jc[i - 1] * i % mod;
  }
  ios::sync_with_stdio(0);
  cin >> n;
  for (i = 1; i < n; i++) {
    cin >> j >> k;
    a[j]++;
    a[k]++;
  }
  v = work(1, n);
  long long res = 0;
  for (i = n - 1; i >= 0; i--) {
    if (i & 1)
      res = su(res, mod - v[i] * jc[n - i] % mod);
    else
      res = su(res, v[i] * jc[n - i] % mod);
  }
  cout << res;
}
