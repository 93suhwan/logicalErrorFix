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
    cin >> n >> k;
    long long int a[n];
    for (auto i = 0; i < n; i++) cin >> a[i];
    for (auto i = max(0 * 1LL, n - 300); i < n; i++) {
      for (auto j = i + 1; j < n; j++) {
        mx = max(((i + 1) * (j + 1) - k * (a[i] | a[j])), mx);
      }
    }
    cout << mx << endl;
  }
  return 0;
}
