#include <bits/stdc++.h>
using namespace std;
const long long p = 998244353;
map<long long, map<long long, long long>> vis;
long long op1 = 0, op2 = 0;
map<long long, map<long long, long long>> f;
long long mp[1000100][2];
long long a[1000100][2];
long long dp[1000100];
int main() {
  dp[0] = 1;
  for (long long i = 1; i <= 1000000; i++) dp[i] = dp[i - 1] * 2 % 998244353;
  long long n, m, k;
  cin >> n >> m >> k;
  long long num = 0, ok = 0;
  long long num1 = 0, ok1 = 0;
  while (k--) {
    long long x, y, op;
    cin >> x >> y >> op;
    if (f[x][y]) {
      long long q1 = ((x + y) & 1) ^ vis[x][y];
      if (q1 == 1)
        op2--;
      else
        op1--;
      long long q = (x & 1) ^ (vis[x][y]);
      if (mp[y][0] && mp[y][1]) ok--;
      mp[y][q]--;
      if (mp[y][0] && mp[y][1]) ok++;
      if (mp[y][0] == 0 && mp[y][1] == 0) num--;
      q = (y & 1) ^ vis[x][y];
      if (a[x][0] && a[x][1]) ok1--;
      a[x][q]--;
      if (a[x][0] && a[x][1]) ok1++;
      if (a[x][0] == 0 && a[x][1] == 0) num1--;
    }
    vis[x][y] = op;
    if (op == -1) {
      f[x][y] = 0;
    } else {
      long long q1 = ((x + y) & 1) ^ vis[x][y];
      if (q1 == 1)
        op2++;
      else
        op1++;
      long long q = (x & 1) ^ (vis[x][y]);
      if (mp[y][0] && mp[y][1]) ok--;
      mp[y][q]++;
      if (mp[y][0] && mp[y][1]) ok++;
      if (mp[y][q] == 1 && mp[y][q ^ 1] == 0) num++;
      q = (y & 1) ^ vis[x][y];
      if (a[x][0] && a[x][1]) ok1--;
      a[x][q]++;
      if (a[x][0] && a[x][1]) ok1++;
      if (a[x][q] == 1 && a[x][q ^ 1] == 0) num1++;
      f[x][y] = 1;
    }
    long long ans = -(op1 == 0) - (op2 == 0) + 1ll * (ok1 == 0) * dp[n - num1] +
                    (ok == 0) * dp[n - num];
    ans %= p;
    cout << ans << endl;
  }
}
