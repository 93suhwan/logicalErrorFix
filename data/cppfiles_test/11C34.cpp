#include <bits/stdc++.h>
using namespace std;
const int N = 200010, mo = 1e9 + 7;
int n;
pair<int, int> e[N];
int dp[N], cnt;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> e[i].first;
    e[i].second = -i;
  }
  sort(e + 1, e + 1 + n);
  for (int i = 1; i <= n; i++) {
    int d = -e[i].second - e[i].first;
    if (d < 0) continue;
    int pos = upper_bound(dp + 1, dp + 1 + cnt, d) - dp;
    if (pos > cnt) cnt++;
    dp[pos] = d;
  }
  cout << cnt << '\n';
  return 0;
}
