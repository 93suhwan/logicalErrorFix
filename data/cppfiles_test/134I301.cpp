#include <bits/stdc++.h>
using namespace std;
int solve() {
  long long n, f1 = 1, f2 = 1;
  cin >> n;
  long long a[n], d1 = a[0], d2 = a[1];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i % 2 == 0) d1 = min(a[i], d1);
    if (i % 2 != 0) d2 = min(a[i], d2);
  }
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      if (a[i] % d1 != 0) f1 = 0;
      if (a[i] % d2 == 0) f2 = 0;
    }
    if (i % 2 != 0) {
      if (a[i] % d2 != 0) f2 = 0;
      if (a[i] % d1 == 0) f1 = 0;
    }
    if (!f1 & !f2) {
      cout << 0 << endl;
      return 0;
    }
  }
  if (f1) {
    cout << d1 << endl;
    return 0;
  }
  if (f2) {
    cout << d2 << endl;
    return 0;
  }
  return 0;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  ;
  long long T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
}
