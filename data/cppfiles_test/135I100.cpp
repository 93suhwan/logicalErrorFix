#include <bits/stdc++.h>
using namespace std;
using ulli = unsigned long long int;
using lli = long long int;
using ld = long double;
using ll = long long;
lli dp[100][100][55];
lli fun(vector<lli>& v, int i, lli j, lli k, lli n, vector<lli>& sum) {
  if (k == 0) {
    if (i > 0)
      return sum[j] - sum[i - 1];
    else {
      return accumulate(v.begin() + i, v.begin() + j + 1, 0LL);
    }
  }
  if (dp[i][j][k] != -1) {
    return dp[i][j][k];
  }
  lli t1{INT64_MAX}, t2{INT64_MAX}, t3{INT64_MAX};
  if (i <= j) t1 = v[i] / v[j] + fun(v, i + 1, j - 1, k - 1, n, sum);
  if (j > 0) {
    t2 = v[j - 1] / v[j] + fun(v, i, j - 2, k - 1, n, sum);
  }
  if (i < n - 1) {
    t3 = v[i] / v[i + 1] + fun(v, i + 2, j, k - 1, n, sum);
  }
  return dp[i][j][k] = min(t1, min(t2, t3));
}
void solve() {
  lli n, k;
  cin >> n >> k;
  vector<lli> v(n);
  for (int i = 0; i < (int)(n); ++i) cin >> v[i];
  if (n == 1) {
    cout << v[0] << endl;
    return;
  }
  sort((v).begin(), (v).end());
  vector<lli> sum(n, 0);
  sum[0] = v[0];
  for (int i = 1; i <= (int)(n - 1); ++i) {
    sum[i] = v[i] + sum[i - 1];
  }
  memset(dp, -1, sizeof(dp));
  cout << fun(v, 0, n - 1, k, n, sum) << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  int T{1};
  cin >> T;
  while (T--) {
    solve();
  }
}
