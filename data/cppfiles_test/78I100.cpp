#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  bool flag = true;
  for (int i = 0; i < n - 1; i++) {
    if (v[i] != v[i + 1]) {
      flag = false;
      break;
    }
  }
  if (flag && v[0] == 0) {
    for (int i = 0; i < n; i++) {
      cout << i + 1 << " ";
    }
    cout << "\n";
    return;
  }
  if (flag) {
    for (int i = 0; i < n / 2; i++) {
      cout << i + 1 << " ";
    }
    cout << n << " ";
    cout << "\n";
    return;
  }
  sort(v.begin(), v.end());
  int diff = v[1] - v[0];
  flag = true;
  for (int i = 1; i < n; i++) {
    if (v[i] != v[i - 1] + diff) {
      flag = false;
      break;
    }
  }
  if (flag) {
    for (int i = 0; i < n / 2; i++) {
      cout << i + 1 << " ";
    }
    cout << "\n";
    return;
  }
  cout << 1 << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
