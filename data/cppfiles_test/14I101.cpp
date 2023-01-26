#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18 + 7;
const double eps = 0;
const int ms = 0;
const int md = 0;
const int mod = 1e9 + 7;
const int N = 5 + 5;
const int pi = 31;
int n, k;
int a[N], dp[N], b[N], path[N];
int main() {
  int t;
  cin >> t;
  ;
  while (t--) {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) b[i] = i - a[i];
    fill(dp + 1, dp + n + 1, 0);
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= i; j++) {
        if (a[i] <= i && a[j] <= j && b[i] >= b[j] &&
            b[i] - b[j] <= i - j - 1) {
          if (dp[i] < dp[j] + 1) path[i] = j;
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
    }
    int pos = max_element(dp + 1, dp + n + 1) - dp;
    if (dp[pos] < k)
      cout << -1 << '\n';
    else {
      vector<int> store;
      while (pos) {
        store.push_back(b[pos]);
        pos = path[pos];
      }
      int res = 0;
      for (int i = 0; i <= (int)store.size() - 1; i++) {
        if (i == (int)store.size() - 1)
          res += store[i];
        else
          res += store[i] - store[i + 1];
      }
      cout << res << '\n';
    }
  }
  return 0;
}
