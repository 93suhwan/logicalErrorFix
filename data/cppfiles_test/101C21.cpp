#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int ans = 0, n, m, k;
  cin >> n >> m >> k;
  set<long long int> x, y;
  x.insert(1e6 + 1), y.insert(1e6 + 1);
  for (long long int i = 0; i < n; i++) {
    long long int temp;
    cin >> temp;
    x.insert(temp);
  }
  for (long long int i = 0; i < m; i++) {
    long long int temp;
    cin >> temp;
    y.insert(temp);
  }
  map<long long int, map<long long int, long long int>> xx, yy;
  for (long long int i = 0; i < k; i++) {
    long long int a, b;
    cin >> a >> b;
    if (x.find(a) != x.end()) {
      if (y.find(b) == y.end()) {
        long long int v = *y.lower_bound(b);
        yy[v][a]++;
      }
    } else {
      long long int v = *x.lower_bound(a);
      xx[v][b]++;
    }
  }
  for (auto i : xx) {
    long long int t = 1, sum = 0;
    for (auto j : i.second) {
      sum += (j.second);
    }
    for (auto j : i.second) {
      t += (sum - j.second) * j.second;
    }
    if ((i.second).size() > 1) {
      ans += t / 2;
    }
  }
  for (auto i : yy) {
    long long int t = 1, sum = 0;
    for (auto j : i.second) {
      sum += (j.second);
    }
    for (auto j : i.second) {
      t += (sum - j.second) * j.second;
    }
    if ((i.second).size() > 1) {
      ans += t / 2;
    }
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
