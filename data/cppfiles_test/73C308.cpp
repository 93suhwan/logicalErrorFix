#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
void solve() {
  int n;
  cin >> n;
  vector<int> v(n + 1);
  for (int i = 1; i <= n; i++) cin >> v[i];
  for (int j = 1;; j++) {
    bool w = 1;
    for (int i = 1; i <= n; i++) {
      if (v[i] != i) {
        w = 0;
        break;
      }
    }
    if (w) {
      cout << j - 1 << '\n';
      return;
    }
    if (j % 2) {
      for (int i = 1; i <= n - 2; i += 2) {
        if (v[i] > v[i + 1]) swap(v[i], v[i + 1]);
      }
    } else {
      for (int i = 2; i <= n - 1; i += 2) {
        if (v[i] >= v[i + 1]) swap(v[i], v[i + 1]);
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
