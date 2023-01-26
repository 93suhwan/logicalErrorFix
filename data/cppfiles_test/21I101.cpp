#include <bits/stdc++.h>
using namespace std;
long long int dp[200005], st[200005], p[200005], c[200005], n;
int bs(long long int p, long long int s) {
  int mid = 0;
  int lo = 0;
  int hi = s - 1;
  while (lo < hi) {
    mid = (lo + hi) / 2;
    if (st[mid] >= p) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }
  return mid;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  dp[0] = 0;
  st[0] = 0;
  p[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> st[i] >> p[i] >> c[i];
    dp[i] = 0;
  }
  long long int ans = 0, prev, star, pos;
  for (int i = 1; i <= n; i++) {
    prev = p[i];
    star = st[i];
    pos = bs(prev, i);
    dp[i] = (((star - prev) % 998244353 + dp[i - 1] % 998244353) % 998244353 -
             dp[pos - 1] % 998244353 + 998244353) %
            998244353;
    if (c[i] == 1) {
      ans = (ans % 998244353 + dp[i] % 998244353) % 998244353;
    }
  }
  cout << (ans + (st[n] + 1ll) % 998244353) % 998244353 << "\n";
  return 0;
}
