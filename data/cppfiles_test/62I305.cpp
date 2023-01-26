#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
const int modp = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const double eps = 1e-6;
const double pi = acos(-1.0);
const double e = 2.718281828459045;
int solve() {
  int n;
  cin >> n;
  vector<int> mp[n + 2];
  for (int i = 1; i <= n; i++) {
    mp[i].clear();
    if (i != n) {
      mp[i].push_back(i + 1);
    }
  }
  int a;
  for (int i = 1; i <= n; i++) {
    cin >> a;
    if (a)
      mp[n + 1].push_back(i);
    else
      mp[i].push_back(n + 1);
  }
  int f = 0;
  for (auto &v : mp[n + 1]) {
    if (v == 1) {
      f = 1;
      break;
    }
  }
  if (f) {
    cout << n + 1 << ' ';
    for (int i = 1; i <= n; i++) cout << i << ' ';
    return 0;
  }
  if (mp[n + 1].size()) {
    for (int i = 1; i <= n + 1; i++) cout << i << ' ';
    return 0;
  }
  f = 0;
  for (auto &v : mp[n + 1]) {
    if (v == 2) {
      f = 1;
      break;
    }
  }
  if (f) {
    cout << 1 << ' ' << n + 1 << ' ';
    for (int i = 2; i <= n; i++) cout << i << ' ';
    return 0;
  }
  cout << -1;
  return 0;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << endl;
  }
  return 0;
}
