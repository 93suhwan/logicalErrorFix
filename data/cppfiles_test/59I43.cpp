#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int mod = 1e9 + 7;
const long double ep = 1.000000001;
void solve() {
  int n;
  cin >> n;
  vector<int> v[5];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 5; j++) {
      int a;
      cin >> a;
      if (a == 1) v[j].push_back(i + 1);
    }
  }
  vector<bool> flag(5);
  for (int i = 0; i < 5; i++) {
    if (v[i].size() >= n / 2) {
      flag[i] = true;
    }
  }
  bool ans = false;
  for (int i = 0; i < 5; i++) {
    vector<bool> visited(n + 1, false);
    if (flag[i] == false) continue;
    for (auto x : v[i]) visited[x] = true;
    for (int j = i + 1; j < 5; j++) {
      if (flag[j] == false) continue;
      for (auto x : v[j]) {
        visited[x] = true;
      }
      int count = 0;
      for (int k = 1; k <= n; k++) {
        if (visited[k]) count++;
      }
      if (count == n) {
        ans = true;
        break;
      }
    }
    if (ans == true) break;
  }
  if (ans)
    cout << "YES" << '\n';
  else
    cout << "NO" << '\n';
}
void local() {}
int32_t main() {
  local();
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(8) << fixed;
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
  }
}
