#include <bits/stdc++.h>
using namespace std;
using cd = complex<double>;
mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
const long long N = 2e5 + 5;
long long x[N], y[N], a[N], b[N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long q;
  cin >> q;
  while (q--) {
    long long n, m, ans = 0;
    cin >> n >> m;
    for (long long i = 1; i <= n; i++) {
      x[i] = y[i] = 0;
      cin >> a[i] >> b[i];
    }
    for (long long i = 1; i <= n; i++) {
      if (a[i] >= m)
        x[i] = m, y[i] = 0;
      else
        x[i] = a[i], y[i] = m - a[i];
      ans += (a[i] - x[i]) - (b[i] - y[i]);
    }
    if (ans < 0) {
      for (long long i = 1; i <= n; i++) {
        long long v = abs(ans) / 2;
        v = min(v, min(x[i], b[i] - y[i]));
        x[i] -= v;
        y[i] += v;
        ans += 2 * v;
      }
    }
    cout << abs(ans) << endl;
    for (long long i = 1; i <= n; i++) {
      cout << x[i] << " " << y[i] << endl;
    }
  }
}
