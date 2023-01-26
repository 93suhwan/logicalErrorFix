#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<pair<int, char>> a(n);
  queue<int> a1, a2;
  for (int i = 0; i < n; i++) cin >> a[i].first;
  for (int i = 0; i < n; i++) cin >> a[i].second;
  sort(a.begin(), a.end());
  for (int i = 0; i < n; i++) {
    if (a[i].first > n && a[i].second == 'R') {
      cout << "NO" << endl;
      return;
    }
    if (a[i].second == 'B')
      a1.push(a[i].first);
    else
      a2.push(a[i].first);
  }
  for (int i = 1; i <= n; i++) {
    if (!a1.empty()) {
      if (a1.front() < i) {
        cout << "NO" << endl;
        return;
      }
      a1.pop();
    } else {
      if (a2.front() > i) {
        cout << "NO" << endl;
        return;
      }
      a2.pop();
    }
  }
  cout << "YES" << endl;
}
signed main() {
  ios::sync_with_stdio(false);
  int tt;
  std::cin >> tt;
  while (tt--) {
    solve();
  }
}
