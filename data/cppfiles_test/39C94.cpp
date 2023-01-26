#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
using namespace std;
int a[110];
int p[110];
int n;
int query() {
  int res;
  cout << "?";
  for (register int i = 1; i <= n; i++) cout << " " << a[i];
  cout << endl;
  cout.flush();
  cin >> res;
  return res;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (register int i = 1; i <= n; i++) a[i] = 1;
  p[n] = n;
  int l = 1, r = n - 1, mid, res;
  while (l <= r) {
    mid = (l + r) >> 1;
    a[n] = n - mid + 1;
    res = query();
    if (res > 0) {
      p[n] = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  for (register int i = 1; i <= n - 1; i++) a[i] = p[n];
  for (register int i = 1; i <= n; i++) {
    if (i == p[n]) continue;
    a[n] = i;
    res = query();
    p[res] = i;
  }
  cout << "!";
  for (register int i = 1; i <= n; i++) cout << " " << p[i];
  cout.flush();
  return 0;
}
