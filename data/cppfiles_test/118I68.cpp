#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
long long M = 998244353;
void fft(vector<complex<double>> &a) {
  int n = a.size(), L = 31 - __builtin_clz(n);
  static vector<complex<long double>> R(2, 1);
  static vector<complex<double>> rt(2, 1);
  for (static int k = 2; k < n; k *= 2) {
    R.resize(n);
    rt.resize(n);
    auto x = polar(1.0L, 3.141592653589793238462643383279502884L / k);
    for (int i = (int)k; i < (int)2 * k; i++)
      rt[i] = R[i] = i & 1 ? R[i / 2] * x : R[i / 2];
  }
  vector<int> rev(n);
  for (int i = 0; i < (int)n; i++) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
  for (int i = 0; i < (int)n; i++)
    if (i < rev[i]) swap(a[i], a[rev[i]]);
  for (int k = 1; k < n; k *= 2)
    for (int i = 0; i < n; i += 2 * k)
      for (int j = 0; j < (int)k; j++) {
        auto x = (double *)&rt[j + k], y = (double *)&a[i + j + k];
        complex<double> z(x[0] * y[0] - x[1] * y[1], x[0] * y[1] + x[1] * y[0]);
        a[i + j + k] = a[i + j] - z;
        a[i + j] += z;
      }
}
vector<long double> conv(const vector<long long> &a,
                         const vector<long long> &b) {
  if (a.empty() || b.empty()) return {};
  vector<long double> res(a.size() + b.size() - 1);
  int L = 32 - __builtin_clz(res.size()), n = 1 << L;
  vector<complex<double>> in(n), out(n);
  copy(a.begin(), a.end(), in.begin());
  for (int i = 0; i < (int)b.size(); i++) in[i].imag(b[i]);
  fft(in);
  for (auto &x : in) x *= x;
  for (int i = 0; i < (int)n; i++) out[i] = in[-i & (n - 1)] - conj(in[i]);
  fft(out);
  for (int i = 0; i < (int)res.size(); i++) res[i] = imag(out[i]) / (4 * n);
  return res;
}
long long n;
vector<long long> ch;
vector<vector<long long>> g;
const long long MAXN = 250000;
long long F[MAXN];
vector<long long> build(long long l, long long r) {
  if (l == r) {
    vector<long long> aux;
    aux.push_back(1);
    aux.push_back(ch[l]);
    return aux;
  }
  vector<long long> v1 = build(l, (l + r) / 2);
  vector<long long> v2 = build((l + r) / 2 + 1, r);
  vector<long double> res = conv(v1, v2);
  vector<long long> ans;
  for (auto it : res) ans.push_back(round(it));
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  F[0] = 1;
  for (long long i = 1; i < MAXN; i++) F[i] = F[i - 1] * i % M;
  cin >> n;
  ch.assign(n, 0);
  g.assign(n, vector<long long>());
  for (int i = 0; i < n - 1; i++) {
    long long x, y;
    cin >> x >> y;
    g[x - 1].push_back(y - 1);
    g[y - 1].push_back(x - 1);
  }
  ch[0] = g[0].size();
  for (long long i = 1; i < n; i++) {
    ch[i] = g[i].size() - 1;
  }
  vector<long long> ans = build(0, n - 1);
  long long res = 0;
  for (long long i = 0; i < ans.size(); i++) {
    if (i % 2 == 0) {
      res += (ans[i] * F[n - i]) % M;
    } else {
      res -= (ans[i] * F[n - i]) % M;
      res += 2 * M;
    }
    res %= M;
  }
  cout << res << "\n";
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
}
