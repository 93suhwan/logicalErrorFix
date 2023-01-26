#include <bits/stdc++.h>
using namespace std;
using cd = complex<double>;
const double PI = acos(-1);
const long long mod = 998244353;
long long power(long long x, long long n) {
  int i = 0;
  long long d = x;
  long long ats = 1;
  while (n > 0) {
    if (n & (1ll << i)) {
      n ^= (1ll << i);
      ats *= d;
      ats %= mod;
    }
    i++;
    d = (d * d) % mod;
  }
  return ats;
}
long long modInverse(long long a) { return power(a, mod - 2); }
const int root = 3;
void fft(vector<long long> &a, bool invert) {
  int n = a.size();
  for (int i = 1, j = 0; i < n; i++) {
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
    long long wlen = power(root, (mod - 1) / len);
    if (invert) {
      wlen = modInverse(wlen);
    }
    for (int i = 0; i < n; i += len) {
      long long w = 1;
      for (int j = 0; j < len / 2; j++) {
        long long u = a[i + j],
                  v = (long long)(1LL * a[i + j + len / 2] * w % mod);
        a[i + j] = u + v < mod ? u + v : u + v - mod;
        a[i + j + len / 2] = u - v >= 0 ? u - v : u - v + mod;
        w = (long long)(1LL * w * wlen % mod);
      }
    }
  }
  if (invert) {
    long long n_1 = modInverse(n);
    for (long long &x : a) {
      x = (long long)(1LL * x * n_1 % mod);
    }
  }
}
vector<long long> multiply(vector<long long> const &a,
                           vector<long long> const &b) {
  vector<long long> fa(a.begin(), a.end()), fb(b.begin(), b.end());
  int n = 1;
  while (n < a.size() + b.size()) {
    n <<= 1;
  }
  fa.resize(n);
  fb.resize(n);
  fft(fa, false);
  fft(fb, false);
  for (int i = 0; i < n; i++) {
    fa[i] *= fb[i];
    fa[i] %= mod;
  }
  fft(fa, true);
  return fa;
}
const int maxn = 250010;
vector<int> gra[maxn];
vector<long long> rek(int l, int r) {
  if (l == r) {
    vector<long long> d(2);
    d[0] = 1;
    d[1] = gra[l].size() - (l == 0 ? 0 : 1);
    return d;
  } else {
    int mid = (l + r) / 2;
    auto t = rek(l, mid);
    auto t1 = rek(mid + 1, r);
    return multiply(t, t1);
  }
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    gra[a].push_back(b);
    gra[b].push_back(a);
  }
  auto d = rek(0, n - 1);
  long long ans = 0;
  long long fakt[n + 1];
  fakt[0] = 1;
  for (int i = 1; i <= n; ++i) {
    fakt[i] = (fakt[i - 1] * i) % mod;
  }
  for (int i = 0; i <= n; ++i) {
    ans += (i % 2 == 0 ? 1 : -1) * fakt[n - i] * d[i];
    ans %= mod;
  }
  cout << (ans % mod + mod) % mod;
}
