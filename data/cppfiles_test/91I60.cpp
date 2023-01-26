#include <bits/stdc++.h>
using namespace std;
const double pi = 3.14159265358979323846, eps = 1e-9;
const long long M = 998244353, I = 1e18;
const int mxn = 1e5, mxn1 = 1e3, lg = 20;
int t, n, arr[mxn], cnt[mxn + 1], dp[mxn + 1][2];
vector<int> v[2];
long long ans;
void solve() {
  for (int i = 0; i < 2; i++) v[i].clear();
  ans = 0;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
  for (int i = n - 1; i >= 0; i--) {
    int ind = i % 2;
    v[ind].push_back(arr[i]);
    dp[ind][arr[i]] = 1;
    int p = arr[i];
    for (int j : v[ind ^ 1]) {
      int k = arr[i] / j;
      if (arr[i] % j != 0) k++;
      int cur = arr[i] / k;
      ans = (ans + (long long)dp[ind ^ 1][j] * (long long)(k - 1) % M *
                       (long long)(i + 1) % M) %
            M;
      if (cur != p) {
        v[ind].push_back(cur);
        p = cur;
      }
      dp[ind][cur] += dp[ind ^ 1][j];
    }
    for (int j : v[ind ^ 1]) dp[ind ^ 1][j] = 0;
    v[ind ^ 1].clear();
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  cin >> t;
  while (t--) solve();
}
