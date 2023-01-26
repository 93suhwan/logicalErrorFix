#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long inf = 1e16;
const long long N = 1e6 + 1;
void run() {
  long long n;
  cin >> n;
  long long a[n][5];
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < 5; j++) {
      cin >> a[i][j];
    }
  }
  vector<vector<long long>> ans(n, vector<long long>(5, 0));
  for (long long i = 0; i < 5; i++) {
    long long cur = 1e9, win;
    vector<pair<long long, long long>> v;
    for (long long j = 0; j < n; j++) {
      v.push_back({a[j][i], j});
      if (a[j][i] < cur) {
        win = j + 1;
        cur = a[j][i];
      }
    }
    sort((v).begin(), (v).end());
    for (long long j = 0; j < n - 2; j++) {
      ans[v[j].second][i]++;
    }
  }
  for (long long i = 0; i < n; i++) {
    long long ct = 0;
    for (long long j = 0; j < 5; j++) {
      ct += ans[i][j];
    }
    if (ct == n - 1) {
      cout << i + 1 << "\n";
      return;
    }
  }
  cout << "-1\n";
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long tt = 1;
  cin >> tt;
  while (tt--) run();
  return 0;
}
