#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
  int m;
  vector<int> a(3);
  for (int i = 0; i < 3; i++) {
    cin >> a[i];
  }
  cin >> m;
  sort(a.rbegin(), a.rend());
  if (m > a[0] + a[1] + a[2] - 3) {
    cout << "NO\n";
    return;
  }
  int sum = a[0] + a[1] + a[2] - 3;
  if (a[0] >= m + 1) {
    a[0] -= m + 1;
    if (abs(a[1] - a[2]) >= 2) {
      cout << "NO\n";
      return;
    } else {
      cout << "YES\n";
      return;
    }
  } else {
    m -= a[0] - 1;
    a[0] = 0;
    if (m > 0) {
      m -= a[1] - 1;
      a[1] = 0;
    }
    if (m > 0) {
      m -= a[2] - 1;
      a[2] = 0;
    }
    if (abs(a[1] - a[2]) >= 2) {
      cout << "NO\n";
      return;
    } else {
      cout << "YES\n";
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
