#include <bits/stdc++.h>
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
const long long int int_max = 1e18;
using namespace std;
void file_i_o() {
  ios::sync_with_stdio(false), cin.tie(0);
  cout.tie(0);
}
vector<vector<long long int>> bset(2e5 + 2, vector<long long int>(31, 0));
void precompute() {
  long long int n = 2e5 + 1;
  for (long long int i = 0; i <= n; i++) {
    for (long long int j = 0; j <= 30; j++) {
      if ((1 << j) & i) {
        if (i != 0)
          bset[i][j] = bset[i - 1][j] + 1;
        else
          bset[i][j] = 1;
      } else {
        if (i != 0)
          bset[i][j] += bset[i - 1][j];
        else
          bset[i][j] = 0;
      }
    }
  }
}
void solve() {
  long long int l, r;
  cin >> l >> r;
  long long int ans = int_max;
  for (long long int i = 0; i <= 30; i++) {
    if (l - 1 >= 0)
      ans = min(ans, (r - l + 1) - (bset[r][i] - bset[l - 1][i]));
    else
      ans = min(ans, (r - l + 1) - bset[r][i]);
  }
  cout << ans << endl;
}
int main(int argc, char const *argv[]) {
  file_i_o();
  long long int t;
  t = 1;
  cin >> t;
  precompute();
  while (t--) solve();
  return 0;
}
