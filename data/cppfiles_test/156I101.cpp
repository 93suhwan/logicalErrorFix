#include <bits/stdc++.h>
using namespace std;
const int inf = (1 << 29);
const long long lnf = (1ll << 60);
const int mod = 1e9 + 7;
int add(int a, int b, int md = mod) {
  return (a + b >= md ? a + b - md : (a + b < 0 ? a + b + md : a + b));
}
int mul(int a, int b, int md = mod) { return 1ll * a * b % md; }
int pw(int a, int b, int md = mod) {
  return (b ? mul(pw(mul(a, a, md), b / 2, md), (b & 1 ? a : 1), md) : 1);
}
const int N = 2e5 + 50;
int n;
long long k, a[N], suf[N];
bool val(int t) {
  for (int i = t; i >= t - n + 1; i--) {
    long long mn = a[0] - i;
    if (suf[0] - (suf[n - t + i] - mn * (t - i) + i) <= k) return 1;
  }
  return 0;
}
void solve() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  memset(suf, 0, sizeof suf);
  for (int i = n - 1; i >= 0; i--) {
    suf[i] = suf[i + 1] + a[i];
  }
  long long l = -1, r = max(suf[0] - k, 0ll);
  while (r - l > 1) {
    long long md = (l + r) / 2;
    if (val(md)) {
      r = md;
    } else {
      l = md;
    }
  }
  cout << r << '\n';
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int tc = 1;
  cin >> tc;
  while (tc--) solve();
  return 0;
}
