#include <bits/stdc++.h>
using namespace std;
void solve() {
  int t;
  cin >> t;
  for (int test = 0; test < t; ++test) {
    int res = 0;
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    vector<int> cnt(31);
    for (int num : v) {
      for (int i = 0; i < 31; ++i) {
        if (num & (1 << i)) ++cnt[i];
      }
    }
    for (int i = 1; i <= n; ++i) {
      bool ok = true;
      for (int j = 0; j < 31; ++j) {
        if (cnt[j] % i != 0) {
          ok = false;
          break;
        }
      }
      if (ok) cout << i << ' ';
    }
    cout << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
