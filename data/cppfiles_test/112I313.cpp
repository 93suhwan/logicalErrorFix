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
  int sum = a[0] + a[1] + a[2];
  if (m > a[0] + a[1] + a[2] - 3) {
    cout << "NO\n";
    return;
  }
  auto apply = [&](int &x) {
    if (x >= m + 1) {
      x -= m + 1;
      m = 0;
    } else {
      m -= x - 1;
      x = 0;
    }
  };
  apply(a[0]);
  if (m > 0) {
    apply(a[1]);
  }
  if (m > 0) {
    apply(a[2]);
  }
  sort(a.rbegin(), a.rend());
  assert(m == 0);
  if (a[0] - a[1] - a[2] >= 2) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
