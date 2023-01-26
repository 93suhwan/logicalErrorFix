#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
int mex(int x, int y) {
  if (x != y) return 2;
  return x ^ 1;
}
void solve() {
  int n;
  cin >> n;
  array<string, 2> s;
  cin >> s[0] >> s[1];
  vector<int> dps(n + 1, 0);
  array<array<int, 2>, 2> last;
  last[0][0] = last[0][1] = last[1][0] = last[1][1] = -1;
  for (int i = 0; i < n; ++i) {
    int& dp = dps[i + 1];
    int x = s[0][i] - '0';
    int y = s[1][i] - '0';
    assert(0 <= x && x <= 1);
    assert(0 <= y && y <= 1);
    dp = dps[i] + mex(x, y);
    if (last[0][x ^ 1] >= 0) {
      dp = max(dp, dps[last[0][x ^ 1]] + 2);
    }
    if (last[0][y ^ 1] >= 0) {
      dp = max(dp, dps[last[0][y ^ 1]] + 2);
    }
    if (last[1][x ^ 1] >= 0) {
      dp = max(dp, dps[last[1][x ^ 1]] + 2);
    }
    if (last[1][y ^ 1] >= 0) {
      dp = max(dp, dps[last[1][y ^ 1]] + 2);
    }
    last[0][x] = i;
    last[1][y] = i;
  }
  cout << dps[n] << '\n';
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int T;
  cin >> T;
  while (T-- > 0) {
    solve();
  }
  return 0;
}
