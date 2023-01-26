#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
void solve() {
  long long i, j, k, n;
  cin >> n;
  long long a[n], sm = 0;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    sm += a[i];
  }
  for (i = 2; i < sm; i++) {
    if (sm % i == 0) {
      cout << n << "\n";
      for (j = 0; j < n; j++) {
        cout << j + 1 << " ";
      }
      return;
    }
  }
  bool flg = true;
  cout << n - 1 << "\n";
  for (j = 0; j < n; j++) {
    if ((a[j] % 2 == 1) && flg) {
      flg = false;
      continue;
    }
    cout << j + 1 << " ";
  }
  return;
}
int32_t main() {
  long long t, tc = 1;
  t = 1;
  cin >> t;
  while (tc <= t) {
    solve();
    cout << "\n";
    tc++;
  }
  return 0;
}
