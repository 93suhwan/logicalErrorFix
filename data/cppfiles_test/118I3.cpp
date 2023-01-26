#include <bits/stdc++.h>
using namespace std;
long long ModularExponentation(long long a, long long n) {
  long long ans = 1;
  for (; n > 0; n /= 2) {
    if (n % 2) ans = (ans * a) % 998244353;
    a = (a * a) % 998244353;
  }
  return ans;
}
long long ModularInverse(int a) {
  return ModularExponentation(a, 998244353 - 2);
}
void FFT(vector<int>& a, bool invert) {
  int n = a.size();
  for (int i = 1, j = 0; i < n; ++i) {
    int bit = n >> 1;
    for (; j & bit; bit >>= 1) {
      j ^= bit;
    }
    j ^= bit;
    if (i < j) {
      swap(a[i], a[j]);
    }
  }
  for (int len = 2; len <= n; len <<= 1) {
    int wlen = invert ? 121392023 : 996173970;
    for (int i = len; i < (1 << 18); i <<= 1) {
      wlen = (int)(1LL * wlen * wlen % 998244353);
    }
    for (int i = 0; i < n; i += len) {
      int w = 1;
      for (int j = 0; j < len / 2; ++j) {
        int u = a[i + j], v = (int)(1LL * a[i + j + len / 2] * w % 998244353);
        a[i + j] = u + v < 998244353 ? u + v : u + v - 998244353;
        a[i + j + len / 2] = u - v >= 0 ? u - v : u - v + 998244353;
        w = (int)(1LL * w * wlen % 998244353);
      }
    }
  }
  if (invert) {
    int n_1 = ModularInverse(n);
    for (int& x : a) {
      x = (int)(1LL * x * n_1 % 998244353);
    }
  }
}
vector<int> MultiplyPolynomials(vector<int>& a, vector<int>& b) {
  int n = 1;
  for (int m = a.size() + b.size(); n < m; n <<= 1)
    ;
  a.resize(n), b.resize(n);
  FFT(a, false), FFT(b, false);
  vector<int> c(n);
  for (int i = 0; i < n; ++i) {
    c[i] = (1ll * a[i] * b[i]) % 998244353;
  }
  FFT(c, true);
  a.clear(), b.clear();
  return c;
}
vector<vector<int>> adj(250001);
vector<int> Solve(int l, int r) {
  if (l == r) {
    return {1, (int)adj[l].size() - (l != 1)};
  }
  int mid = l + (r - l) / 2;
  vector<int> a = Solve(l, mid);
  vector<int> b = Solve(mid + 1, r);
  return MultiplyPolynomials(a, b);
}
int main() {
  int n;
  scanf("%d", &n);
  for (int x = 1; x < n; ++x) {
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
  }
  vector<int> f = Solve(1, n);
  int ans = 0;
  for (int i = 1, j = n - 1, fact = 1; i <= n; ++i, --j) {
    fact = (1ll * i * fact) % 998244353;
    int ansx = (1ll * f[j] * fact) % 998244353;
    if (j % 2 == 1) {
      ansx = 998244353 - ansx;
    }
    ans = (ans + ansx) % 998244353;
  }
  printf("%d\n", ans);
  return 0;
}
