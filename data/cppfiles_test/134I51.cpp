#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t != 0) {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    set<long long> b;
    for (int i = 0; i < n; ++i) {
      for (long long j = 1; j * j <= n; ++j) {
        if (a[i] % j == 0) {
          b.insert(j);
          b.insert(a[i] / j);
        }
      }
    }
    bool with_break = false;
    for (auto j : b) {
      int first = a[0] % j;
      int second = a[1] % j;
      with_break = false;
      for (int i = 1; i < n; ++i) {
        if (a[i] % j != first && a[i] % j != second ||
            a[i] % j == a[i - 1] % j) {
          with_break = true;
          break;
        }
      }
      if (!with_break) {
        cout << j << '\n';
        break;
      }
    }
    if (with_break) cout << 0 << '\n';
    --t;
  }
  return 0;
}
