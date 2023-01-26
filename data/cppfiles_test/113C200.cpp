#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
using namespace std;
const int N = 2e5 + 10;
long long a[N], f[N];
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  long long s = 0;
  cin >> n;
  for (register int i = 1; i <= n; i++) {
    cin >> a[i];
    s += a[i];
  }
  sort(a + 1, a + n + 1);
  a[0] = -1;
  for (register int i = 1; i <= n; i++) {
    if (a[i] != a[i - 1]) {
      for (register int j = i - 1; j >= 1; j--) {
        if (a[j] < a[i]) {
          f[i] = j;
          break;
        }
      }
    } else {
      f[i] = f[i - 1];
    }
  }
  int m;
  cin >> m;
  long long x, y;
  int l, r, mid;
  while (m--) {
    cin >> x >> y;
    l = 1, r = n;
    while (l <= r) {
      mid = (l + r) >> 1;
      if (a[mid] < x) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    if (a[l] == 0) {
      cout << x - a[n] + max(y - s + a[n], 0LL) << endl;
      continue;
    }
    if (a[f[l]] == -1) {
      cout << max(y - s + a[1], 0LL) << endl;
      continue;
    }
    cout << min(max(x - a[l], 0LL) + max(y - s + a[l], 0LL),
                max(x - a[f[l]], 0LL) + max(y - s + a[f[l]], 0LL))
         << endl;
  }
}
