#include <bits/stdc++.h>
using namespace std;
const long long MAX = 1e11;
const long long mod = 1e9 + 7;
const long long inf = 1000000000000000000;
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  long long mx = -1;
  bool f = 0;
  bool f1 = 0;
  for (long long i = 0; i < n; i++) {
    mx = max(mx, a[i] % 3);
    if (a[i] % 3 == 1) {
      f = 1;
    }
    if (a[i] % 3 == 0) {
      f1 = 1;
    }
  }
  if (mx == 0) {
    cout << a[n - 1] / 3 << '\n';
    return;
  }
  if (mx == 1) {
    if (a[n - 1] % 3 == 0) {
      long long cnt = (a[n - 1] / 3) - 1;
      cnt += 2;
      cout << cnt << '\n';
      return;
    }
    if (a[n - 1] % 3 == 1) {
      cout << (a[n - 1] / 3) + 1 << '\n';
      return;
    }
  }
  if (mx == 2) {
    if (a[n - 1] % 3 == 0) {
      cout << (a[n - 1] / 3) - 1 + 2 << '\n';
      return;
    }
    if (a[n - 1] % 3 == 1) {
      if (f1 == 0) {
        cout << (a[n - 1] / 3) - 1 + 2 << '\n';
        return;
      } else {
        cout << (a[n - 1] / 3) - 1 + 3 << '\n';
        return;
      }
    }
    if (a[n - 1] % 3 == 2) {
      if (f == 1) {
        cout << (a[n - 1] / 3) - 1 + 3 << '\n';
        return;
      } else {
        cout << (a[n - 1] / 3) + 1 << '\n';
        return;
      }
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
