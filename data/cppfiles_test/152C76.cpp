#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using ull = unsigned long long;
using db = long double;
const int N = 1e6 + 5, LG = 18, MOD = 998244353;
const long double PI = acos(-1);
int dp[N][2];
int par[N][2];
void doWork() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    for (int j = 0; j < 2; j++) dp[i][j] = INT_MAX;
  }
  dp[0][0] = dp[0][1] = INT_MIN;
  auto upd = [&](int i, int j, int k, int p) {
    if (dp[i][j] > k) {
      dp[i][j] = k;
      par[i][j] = p;
    }
  };
  for (int i = 0; i < n - 1; i++)
    for (int x = 0; x < 2; x++)
      for (int y = 0; y < 2; y++) {
        int val1 = (x ? -1 : 1) * a[i];
        int val2 = (y ? -1 : 1) * a[i + 1];
        if (val1 <= val2) {
          upd(i + 1, y, dp[i][x], x);
        }
        if (dp[i][x] <= val2) {
          upd(i + 1, y, val1, x);
        }
      }
  if (dp[n - 1][0] == INT_MAX) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
    int cur = 0;
    for (int i = n - 1; i >= 0; --i) {
      if (cur) a[i] *= -1;
      cur = par[i][cur];
    }
    for (int i = 0; i < n; i++) cout << a[i] << " \n"[i + 1 == n];
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    doWork();
  }
  return 0;
}
