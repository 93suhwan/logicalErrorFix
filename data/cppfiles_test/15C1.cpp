#include <bits/stdc++.h>
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast")
#pragma gcc optimize("unroll-loops")
using namespace std;
const int INF = 1e9;
const int TMX = 1 << 18;
const long long llINF = 1e18 + 10;
const long long mod = 1e9 + 7;
const long long hashmod = 100003;
const int MAXN = 100000;
const int MAXM = 1000000;
const long double P = acos(-1.L);
int n, k, cnt[105], s[105];
long long arr[105];
vector<int> v[105];
vector<int> sum[105];
void dfs(int first, int pr, int dep) {
  cnt[dep]++;
  for (int i : v[first]) {
    if (i == pr) continue;
    dfs(i, first, dep + 1);
  }
}
long long fact[305], factInv[305];
long long mpow(long long first, long long m) {
  if (!m) return 1;
  long long tmp = mpow(first, m / 2);
  tmp = tmp * tmp % mod;
  if (m % 2) return tmp * first % mod;
  return tmp;
}
long long Com(long long first, long long r) {
  return fact[first] * factInv[r] % mod * factInv[first - r] % mod;
}
void FFT(vector<complex<long double> > &f, bool rev) {
  int n = f.size();
  for (int i = 1, j = 0; i < n; i++) {
    int bit = n >> 1;
    for (; j >= bit; bit >>= 1) j -= bit;
    j += bit;
    if (i < j) swap(f[i], f[j]);
  }
  for (int k = 1; k < n; k <<= 1) {
    vector<complex<long double> > w(k);
    for (int i = 0; i < k; i++) {
      long double ang = (rev ? -2 * P * i / (k * 2) : 2 * P * i / (k * 2));
      w[i] = complex<long double>(cos(ang), sin(ang));
    }
    for (int i = 0; i < n; i += (k << 1)) {
      complex<long double> wp(1, 0);
      for (int j = 0; j < k; j++) {
        complex<long double> first = f[i + j], second = f[i + j + k] * w[j];
        f[i + j] = first + second;
        f[i + j + k] = first - second;
      }
    }
  }
  if (rev)
    for (int i = 0; i < n; i++) f[i] /= n;
}
void calc(vector<complex<long double> > &a, vector<complex<long double> > &b) {
  int n = 1;
  while (n < 2 * max((int)a.size(), (int)b.size())) n <<= 1;
  a.resize(n);
  b.resize(n);
  FFT(a, false);
  FFT(b, false);
  for (int i = 0; i < n; i++) a[i] *= b[i];
  FFT(a, true);
  for (int i = n - 1; i >= 0; i--) {
    a[i] = ((long long)round(a[i].real())) % mod;
  }
  return;
}
vector<complex<long double> > gar;
vector<complex<long double> > divt(int l, int r) {
  if (l == r) {
    gar.clear();
    gar.push_back(arr[l]);
    gar.push_back(1);
    return gar;
  } else {
    int mid = (l + r) >> 1;
    vector<complex<long double> > tmp = divt(l, mid);
    vector<complex<long double> > tmp2 = divt(mid + 1, r);
    calc(tmp, tmp2);
    return tmp;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  fact[0] = 1;
  for (int i = 1; i <= 300; i++) fact[i] = fact[i - 1] * i % mod;
  factInv[300] = mpow(fact[300], mod - 2);
  for (int i = 299; i >= 0; i--) factInv[i] = factInv[i + 1] * (i + 1) % mod;
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) v[i].clear();
    for (int i = 1; i < n; i++) {
      int first, second;
      cin >> first >> second;
      v[first].push_back(second), v[second].push_back(first);
    }
    if (k == 2) {
      cout << n * (n - 1) / 2 << '\n';
      continue;
    }
    long long Ans = 0;
    for (int i = 1; i <= n; i++) {
      if (v[i].size() < k) continue;
      for (int j = 1; j <= n; j++) sum[j].clear();
      for (int j : v[i]) {
        for (int l = 1; l <= n; l++) cnt[l] = 0;
        dfs(j, i, 1);
        for (int l = 1; l <= n; l++) {
          if (cnt[l]) sum[l].push_back(cnt[l]);
        }
      }
      for (int j = 1; j <= n; j++) {
        if (sum[j].size() < k) continue;
        int sz = sum[j].size();
        for (int l = 0; l < sz; l++) arr[l + 1] = sum[j][l];
        arr[sz + 1] = 0;
        vector<complex<long double> > ans = divt(1, sz);
        Ans += ans[sz - k].real();
        Ans %= mod;
      }
    }
    cout << Ans << '\n';
  }
}
