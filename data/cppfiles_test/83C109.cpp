#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 10;
int dp1[N][N], dp2[N];
void solve() {
  int n, ans = 0;
  cin >> n;
  string a;
  cin >> a;
  for (int i = n - 1; i >= 0; i--) {
    for (int j = n - 1; j >= 0; j--) {
      dp1[i][j] = 0;
      if (a[i] == a[j]) dp1[i][j] = dp1[i + 1][j + 1] + 1;
    }
  }
  dp2[0] = n;
  ans = n;
  for (int i = 1; i < n; i++) {
    dp2[i] = n - i;
    for (int j = 0; j < i; j++) {
      if (a[i] > a[j])
        dp2[i] = max(dp2[i], dp2[j] + (n - i));
      else if (a[i] == a[j])
        if (i + dp1[i][j] < n)
          if (a[i + dp1[i][j]] > a[j + dp1[i][j]])
            dp2[i] = max(dp2[i], (dp2[j]) + ((n - i) - (dp1[i][j])));
    }
    ans = max(dp2[i], ans);
  }
  cout << ans << "\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  unsigned long long test_case;
  cin >> test_case;
  while (test_case--) solve();
  return 0;
}
