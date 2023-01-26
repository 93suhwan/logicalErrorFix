#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
mt19937 rng((int)chrono::steady_clock::now().time_since_epoch().count());
const int MOD = 1e9 + 7;
const int MAXN = 8e5 + 5;
const int INF = 2e9;
vector<int> vals[21][MAXN], ss;
int dp[1 << 20][2], sm[1 << 20], valid[1 << 20];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int offset = 4e5;
  int n;
  cin >> n;
  string s;
  valid[0] = 1;
  for (int i = 0; i < n; i++) {
    cin >> s;
    valid[1 << i] = 1;
    int tam = s.size(), sum = 0;
    for (int j = 0; j < tam; j++) {
      if (s[j] == '(')
        sum++;
      else
        sum--;
      vals[i][sum + offset].push_back(j);
      if (sum < 0) valid[1 << i] = 0;
    }
    ss.push_back(sum + offset);
  }
  for (int i = 0; i < (1 << n); i++) {
    int sum = 0;
    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) sum += ss[j] - offset;
    }
    sm[i] = sum + offset;
  }
  for (int i = 1; i < (1 << n); i++) {
    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        dp[i][1] = max(dp[i][1], dp[i ^ (1 << j)][1]);
        if (sm[i ^ (1 << j)] < offset) continue;
        if (vals[j][offset - (sm[i ^ (1 << j)] - offset) - 1].size()) {
          int np = vals[j][offset - (sm[i ^ (1 << j)] - offset) - 1][0];
          int tot =
              vals[j][offset - (sm[i ^ (1 << j)] - offset)].end() -
              lower_bound(vals[j][offset - (sm[i ^ (1 << j)] - offset)].begin(),
                          vals[j][offset - (sm[i ^ (1 << j)] - offset)].end(),
                          np);
          tot = vals[j][offset - (sm[i ^ (1 << j)] - offset)].size() - tot;
          if (valid[i ^ (1 << j)])
            dp[i][1] = max(dp[i][1], dp[i ^ (1 << j)][0] + tot);
        } else {
          dp[i][0] = max(
              dp[i][0],
              dp[i ^ (1 << j)][0] +
                  (int)vals[j][offset - (sm[i ^ (1 << j)] - offset)].size());
          valid[i] = 1;
        }
      }
    }
  }
  cout << max(dp[(1 << n) - 1][0], dp[(1 << n) - 1][1]) << '\n';
  return 0;
}
