#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
int dp[N][N], mark[N][N], id, a[N];
int solve(int idx, int rem) {
  if (idx == -1) {
    return (rem != 0) * -1e9;
  }
  if (idx + 1 == rem) return 0;
  if (mark[idx][rem] == id) return dp[idx][rem];
  mark[idx][rem] = id;
  int cur = idx + 1 - rem;
  int op1 = (cur == a[idx]) + solve(idx - 1, rem);
  int op2 = -1e9;
  if (rem > 0) op2 = solve(idx - 1, rem - 1);
  return dp[idx][rem] = max(op1, op2);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    id++;
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = -1;
    for (int i = 0; i < n; i++) {
      if (solve(n - 1, i) >= k) {
        ans = i;
        break;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
