#include <bits/stdc++.h>
using namespace std;
const int N = 2100;
const long long inf = N * N;
int a[N], dp[N][N], n;
int solve(int p, int cost) {
  if (p == -1) return 0;
  if (cost == -1) return -inf;
  int &ans = dp[p][cost];
  if (ans != -1) return ans;
  ans = solve(p - 1, cost - 1);
  if (a[p] != -1) ans = max(ans, (a[p] == cost ? 1 : 0) + solve(p - 1, cost));
  return ans;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int q, k;
  cin >> q;
  while (q--) {
    memset(dp, -1, sizeof(dp));
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      if (i + 1 >= a[i])
        a[i] = i + 1 - a[i];
      else
        a[i] = -1;
    }
    int at = -1;
    for (int i = 0; i < n; ++i) {
      if (solve(n - 1, i) >= k) {
        at = i;
        break;
      }
    }
    cout << at << "\n";
  }
  return 0;
}
