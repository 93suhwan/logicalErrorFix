#include <bits/stdc++.h>
static int row[4] = {-1, 0, 0, 1};
static int col[4] = {0, -1, 1, 0};
static int dagb[4] = {1, -1, 1, -1};
static int daga[4] = {1, -1, -1, 1};
using namespace std;
long long int a[202], b[202], c[202];
long long int binexp(long long int a, long long int b) {
  long long int res = 1;
  while (b) {
    if (b % 2 == 1)
      (res *= a) % 1000000007, b--;
    else
      (a *= a) % 1000000007, b /= 2;
  }
  return res;
}
long long int solve(long long int sz, long long int la, long long int lb,
                    long long int n, long long int m) {
  if (sz == m) return 1;
  if (la > n || lb < 0) return 0;
  long long int ans = 0;
  for (auto i = la; i < n + 1; i++) {
    for (auto j = lb; j >= 1; j--) {
      if (j >= i) (ans += solve(sz + 1, i, j, n, m)) % 1000000007;
    }
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int _ = 1;
  cin >> _;
  for (auto ii = 1; ii < _ + 1; ii++) {
    string s1, s2, s3;
    long long int s = 0;
    long long int l = 0, n, m, r, h, k, w = 1, y = 0, z = 0, x = 0, flag = 0,
                  mn = 0, e = 0, cnt = 0, f = INT_MAX, sum = 0, de = 1,
                  mx = -1e18, ans = 0;
    cin >> n >> m;
    long long int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x >> y;
    if (abs(x1 - x2) + x > n && abs(y1 - y2) + y > m)
      cout << -1 << endl;
    else {
      long long int u = 0, v = 0, c = 0, d = 0;
      u = max(x1, n - x2);
      v = max(y1, m - y2);
      if (y > v) c = abs(y - v);
      if (x > u) d = abs(x - u);
      double dd;
      if (x + abs(x1 - x2) > n)
        dd = c;
      else if (y + abs(y1 - y2) > m)
        dd = d;
      else
        dd = min(c, d);
      cout << fixed << setprecision(9) << dd << endl;
    }
  }
  return 0;
}
