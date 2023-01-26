#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int cur = 1;
  for (int i = 0; i < n; i++) {
    if (a[i] && (i == 0 || a[i - 1] == 0)) {
      cur++;
    } else {
      if (!a[i]) {
        if (i && !a[i - 1]) {
          cur = -1;
          break;
        }
      } else {
        cur += 5;
      }
    }
  }
  cout << cur << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
