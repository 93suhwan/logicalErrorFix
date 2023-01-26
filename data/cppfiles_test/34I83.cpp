#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
long long dp[8193], p[8192][5001];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  long long x;
  dp[0] = 1;
  queue<long long> v[5001];
  for (long long i = 1; i <= 5000; i++) v[i].push(0);
  for (long long i = 0; i < n; i++) {
    cin >> x;
    while (!v[x].empty()) {
      long long y = v[x].front();
      v[x].pop();
      p[x][y] = 1;
      if (dp[(x ^ y)] == 1) continue;
      dp[(x ^ y)] = 1;
      for (long long z = max(x, y) + 1; z <= 5000; z++)
        if (p[(x ^ y)][z] == 0) {
          v[z].push((x ^ y));
          p[(x ^ y)][z] = 1;
        }
    }
  }
  vector<long long> ans;
  for (long long i = 0; i <= 8192; i++)
    if (dp[i] == 1) ans.push_back(i);
  cout << ans.size() << '\n';
  for (auto to : ans) cout << to << ' ';
  return 0;
}
