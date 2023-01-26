#include <bits/stdc++.h>
using namespace std;
long long inf = 1e9 + 7;
long long n;
vector<vector<long long> > ans;
string s;
void prep() {
  ans.assign(6, vector<long long>(n, 0));
  for (long long i = n - 1; i >= 0; i--) {
    ans[0][i] = (i != n - 1 ? ans[1][i + 1] : 0) + (s[i] == 'a' ? 1 : 0);
    ans[1][i] = (i != n - 1 ? ans[2][i + 1] : 0) + (s[i] == 'b' ? 1 : 0);
    ans[2][i] = (i != n - 1 ? ans[0][i + 1] : 0) + (s[i] == 'c' ? 1 : 0);
    ans[3][i] = (i != n - 1 ? ans[4][i + 1] : 0) + (s[i] == 'a' ? 1 : 0);
    ans[4][i] = (i != n - 1 ? ans[5][i + 1] : 0) + (s[i] == 'c' ? 1 : 0);
    ans[5][i] = (i != n - 1 ? ans[3][i + 1] : 0) + (s[i] == 'b' ? 1 : 0);
  }
}
void solve() {
  long long l, r;
  cin >> l >> r;
  l--;
  r--;
  if (r - l == 0) {
    cout << 0 << '\n';
    return;
  }
  if (r - l == 1) {
    cout << (s[l] == s[r] ? 1 : 0) << '\n';
    return;
  }
  if ((r - l) % 3 == 2) {
    long long ans_ = 0;
    for (long long i = 0; i < 6; i++) {
      ans_ = max(ans_, ans[i][l] - (r == n - 1 ? 0 : ans[i][r + 1]));
    }
    cout << r - l + 1 - ans_ << '\n';
    return;
  }
  if ((r - l) % 3 == 0) {
    long long ans_ = 0;
    for (long long i = 0; i < 6; i++) {
      ans_ = max(
          ans_,
          ans[i][l] -
              (r == n - 1 ? 0 : ans[(i + 1) % 3 + (i >= 3 ? 3 : 0)][r + 1]));
    }
    cout << r - l + 1 - ans_ << '\n';
    return;
  }
  long long ans_ = 0;
  for (long long i = 0; i < 6; i++) {
    ans_ =
        max(ans_,
            ans[i][l] -
                (r == n - 1 ? 0 : ans[(i + 2) % 3 + (i >= 3 ? 3 : 0)][r + 1]));
  }
  cout << r - l + 1 - ans_ << '\n';
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> n >> t >> s;
  prep();
  while (t--) {
    solve();
  }
}
