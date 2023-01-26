#include <bits/stdc++.h>
using namespace std;
const int N = (int)2e+3 + 8;
int n, k;
vector<int> v;
int dp[N][N];
int ans(int i, int j) {
  if (i < 0) return (!!j) * INT_MIN;
  if (j < 0) return INT_MIN;
  if (dp[i][j] != -1) return dp[i][j];
  long long val1 = (v[i] == j) + ans(i - 1, j - 1);
  long long val2 = ans(i - 1, j);
  return dp[i][j] = max(val1, val2);
}
void MAIN(long long tc) {
  cin >> n >> k;
  v.resize(n);
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      dp[i][j] = -1;
    }
  }
  for (auto &x : v) cin >> x;
  int res = -1;
  for (int i = n; i >= k; i--) {
    int v = ans(n - 1, i);
    if (v >= k) {
      res = n - i;
      break;
    }
  }
  cout << res << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed;
  cout << setprecision(10);
  int test__cases = 1;
  cin >> test__cases;
  for (int i = 1; i <= test__cases; i++) {
    MAIN(i);
  }
}
