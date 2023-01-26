#include <bits/stdc++.h>
using namespace std;
const long long p = 998244353;
map<int, map<int, int>> vis;
int op1 = 0, op2 = 0;
map<int, map<int, int>> f;
int mp[1000100][2];
int dp[1000100];
int main() {
  dp[0] = 1;
  for (int i = 1; i <= 1000000; i++) dp[i] = dp[i - 1] * 2 % 998244353;
  int n, m, k;
  cin >> n >> m >> k;
  int num = 0, ok = 0;
  while (k--) {
    int x, y, op;
    cin >> x >> y >> op;
    if (f[x][y]) {
      if (y & 1) {
        if (vis[x][y] == 0)
          op1--;
        else
          op2--;
      } else {
        if (vis[x][y] == 0)
          op2--;
        else
          op1--;
      }
      int q = (x & 1) ^ (vis[x][y]);
      if (mp[y][0] && mp[y][1]) ok--;
      mp[y][q]--;
      if (mp[y][0] && mp[y][1]) ok++;
      if (mp[y][0] == 0 && mp[y][1] == 0) num--;
    }
    vis[x][y] = op;
    if (op == -1) {
      f[x][y] = 0;
    } else {
      if (y & 1) {
        if (vis[x][y] == 0)
          op1++;
        else
          op2++;
      } else {
        if (vis[x][y] == 0)
          op2++;
        else
          op1++;
      }
      int q = (x & 1) ^ (vis[x][y]);
      if (mp[y][0] && mp[y][1]) ok--;
      mp[y][q]++;
      if (mp[y][0] && mp[y][1]) ok++;
      if (mp[y][q] == 1 && mp[y][q ^ 1] == 0) num++;
      f[x][y] = 1;
    }
    long long ans = (op1 == 0) + (op2 == 0) + (ok == 0) * dp[n - num];
    ans %= p;
    cout << ans << endl;
  }
}
