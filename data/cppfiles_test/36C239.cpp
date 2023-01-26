#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
void fileio(const string &s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}
const long long INF = 4e18;
inline long long read() {
  long long x = 0;
  bool flag = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') flag = 0;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + c - '0';
    c = getchar();
  }
  return (flag ? x : ~(x - 1));
}
long long t, n, sum, a[101], f[20001];
long long pri(long long x) {
  for (long long i = 2; i * i <= x; i++)
    if (x % i == 0) return 1;
  return 0;
}
void solve() {
  n = read();
  sum = 0;
  for (long long i = 1; i <= n; i++) {
    a[i] = read();
    sum += a[i];
  }
  if (pri(sum)) {
    cout << n << endl;
    for (long long i = 1; i <= n; i++) cout << i << " ";
    cout << endl;
    return;
  }
  for (long long i = 1; i <= n; i++)
    if (pri(sum - a[i])) {
      cout << n - 1 << endl;
      for (long long l = 1; l <= n; l++)
        if (l != i) cout << l << " ";
      cout << endl;
      return;
    }
  for (long long i = 1; i <= n; i++)
    for (long long l = i + 1; l <= n; l++)
      if (pri(sum - a[i] - a[l])) {
        cout << n - 2 << endl;
        for (long long j = 1; j <= n; j++)
          if (j != i && j != l) cout << j << " ";
        cout << endl;
        return;
      }
  for (long long i = 1; i <= n; i++)
    for (long long l = i + 1; l <= n; l++)
      for (long long j = l + 1; j <= n; j++)
        if (pri(sum - a[i] - a[l] - a[j])) {
          cout << n - 3 << endl;
          for (long long k = 1; k <= n; k++)
            if (i != k && l != k && j != k) cout << k << " ";
          cout << endl;
          return;
        }
}
signed main() {
  t = read();
  while (t--) solve();
  return 0;
}
