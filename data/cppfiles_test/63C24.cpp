#include <bits/stdc++.h>
using namespace std;
int n;
string s[21];
int mp[21][400005];
int baki[21];
int mx[21];
int dp[1 << 21];
int run(int mask) {
  if (mask == (1 << n) - 1) {
    return 0;
  }
  if (dp[mask] != -1) return dp[mask];
  int a = 0;
  for (int i = 0; i < n; i++) {
    if (mask & (1 << i)) {
      a += baki[i] - mx[i];
    }
  }
  int tot = 0;
  for (int i = 0; i < n; i++) {
    if (mask & (1 << i)) continue;
    int ans = 0;
    ans += mp[i][a];
    if (mx[i] <= a) {
      ans += run(mask | (1 << i));
    }
    tot = max(ans, tot);
  }
  return dp[mask] = tot;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    int a = 0, b = 0;
    int ex = 0;
    for (auto u : s[i]) {
      if (u == '(') {
        a++;
      } else {
        if (a == 0) {
          ex++;
          mp[i][ex]++;
        } else {
          a--;
          if (a == 0) mp[i][ex]++;
        }
      }
      mx[i] = max(mx[i], ex);
    }
    baki[i] = a;
  }
  memset(dp, -1, sizeof dp);
  cout << run(0);
}
