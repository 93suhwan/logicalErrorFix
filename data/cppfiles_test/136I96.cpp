#include <bits/stdc++.h>
#pragma optimize(3, "-Ofast", "inline")
using namespace std;
const int maxn = 1e5 + 3, maxm = 1e6 + 11, inf_int = 0x3f3f3f3f;
const long long inf_ll = 0x3f3f3f3f3f3f3f, mod = 1e9 + 7;
const double eps = 1e-6;
long long n, a[maxn], b[maxn], d[maxn];
inline long long get(long long x0) {
  long long x1 = x0 - 1, x2 = x0 - 2;
  if (x1 <= 0) x1 += n;
  if (x2 <= 0) x2 += n;
  return 2 * b[x1] - b[x0] - b[x2];
}
inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> b[i];
  for (int i = 1; i <= n; i++) {
    d[i] = get(i);
    if (d[i] % n) {
      cout << "NO" << endl;
      return;
    }
    d[i] /= n;
  }
  a[1] = 0;
  for (int i = 2; i <= n; i++) a[i] = d[i] + a[i - 1];
  long long sum = b[1], tot = n * (n + 1) / 2;
  for (int i = 2, t = n; i <= n; i++, t--) sum -= t * a[i];
  if (sum % tot) {
    cout << "NO" << endl;
    return;
  }
  a[1] = sum / tot;
  for (int i = 2; i <= n; i++) a[i] += a[1];
  cout << "YES" << endl;
  for (int i = 1; i <= n; i++) cout << a[i] << " ";
  cout << endl;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int TEST = 1;
  cin >> TEST;
  while (TEST--) solve();
}
