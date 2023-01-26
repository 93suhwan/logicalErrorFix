#include <bits/stdc++.h>
using namespace std;
int solve(int l, int r, vector<int> &a, vector<int> &dp) {
  if (l > r) {
    return 0;
  }
  int ans = a[l] - solve(l + 1, r, a, dp);
  return dp[l] = ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, q;
    cin >> n >> q;
    string s;
    vector<int> a;
    a.push_back(0);
    cin >> s;
    for (int i = 0; i < n; i++) {
      if (s[i] == '+') {
        a.push_back(1);
      } else {
        a.push_back(-1);
      }
    }
    vector<int> dp(n + 1, 0);
    solve(1, n, a, dp);
    while (q--) {
      int l, r;
      cin >> l >> r;
      if ((dp[l] - dp[r + 1] == 0) || (dp[r + 1] - dp[l] == 0)) {
        cout << 0 << endl;
      } else if ((r - l + 1) % 2 == 0) {
        cout << 2 << endl;
      } else {
        cout << 1 << endl;
      }
    }
  }
  return 0;
}
