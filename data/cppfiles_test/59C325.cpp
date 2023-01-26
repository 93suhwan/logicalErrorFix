#include <bits/stdc++.h>
const double pi = acos(-1.0);
using namespace std;
const long long mod = 1e9 + 7;
void solve() {
  int n, ans = 0;
  cin >> n;
  int a[n + 2][10];
  vector<int> v[10];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> a[i][j];
      if (a[i][j] == 1) {
        v[j].push_back(i);
      }
    }
  }
  for (int i = 0; i < 5; i++) {
    if (v[i].size() < n / 2) continue;
    set<int> s;
    for (int j = 0; j < 5; j++) {
      if (v[j].size() < n / 2) continue;
      for (auto x : v[i]) {
        s.insert(x);
      }
      for (auto x : v[j]) {
        s.insert(x);
      }
      if (s.size() == n && i != j) {
        ans = 1;
        break;
      }
      s.clear();
    }
  }
  if (ans)
    cout << "YES"
         << "\n";
  else
    cout << "NO"
         << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
