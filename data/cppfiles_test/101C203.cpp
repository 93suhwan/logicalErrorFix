#include <bits/stdc++.h>
using namespace std;
const long long maxn = 200005;
long long n;
long long a[maxn];
long long r[maxn];
long long l[maxn];
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (long long i = 1; i <= n; ++i) {
      cin >> a[i];
      r[i] = l[i] = 0;
    }
    char c;
    bool ok = 1;
    for (long long i = 1; i <= n; ++i) {
      cin >> c;
      if (c == 'R') {
        if (a[i] > n)
          ok = 0;
        else if (a[i] <= 0)
          r[1]++;
        else
          r[a[i]]++;
      } else {
        if (a[i] <= 0)
          ok = 0;
        else if (a[i] > n)
          l[n]++;
        else
          l[a[i]]++;
      }
    }
    if (!ok) {
      cout << "NO" << endl;
      continue;
    }
    long long rp = 0;
    for (long long i = n; i >= 1; --i) {
      rp += r[i];
      if (rp > n - i + 1) {
        ok = 0;
        break;
      }
    }
    if (!ok) {
      cout << "NO" << endl;
      continue;
    }
    long long lp = 0;
    for (long long i = 1; i <= n; ++i) {
      lp += l[i];
      if (lp > i) {
        ok = 0;
        break;
      }
    }
    if (!ok) {
      cout << "NO" << endl;
      continue;
    } else
      cout << "YES" << endl;
  }
  return 0;
}
