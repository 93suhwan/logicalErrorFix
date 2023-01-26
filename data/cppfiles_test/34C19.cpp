#include <bits/stdc++.h>
using namespace std;
const int kMax = 1 << 13;
int dp[kMax];
vector<int> pos[kMax];
void min_self(int &x, const int &y) {
  if (y < x) {
    x = y;
  }
}
void TestCase() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    pos[x].emplace_back(i);
  }
  memset(dp, 0x3f, sizeof(dp));
  dp[0] = -1;
  for (int x = 0; x < kMax; ++x) {
    if (!pos[x].empty()) {
      for (int sxor = 0; sxor < kMax; ++sxor) {
        if (dp[sxor] != 0x3f3f3f3f) {
          auto it = upper_bound(pos[x].begin(), pos[x].end(), dp[sxor]);
          if (it != pos[x].end()) {
            min_self(dp[sxor ^ x], *it);
          }
        }
      }
    }
  }
  int ans = 0;
  for (int x = 0; x < (1 << 13); ++x) {
    ans += (dp[x] != 0x3f3f3f3f);
  }
  cout << ans << '\n';
  for (int x = 0; x < (1 << 13); ++x) {
    if (dp[x] != 0x3f3f3f3f) {
      cout << x << ' ';
    }
  }
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tests = 1;
  for (int tc = 1; tc <= tests; ++tc) {
    TestCase();
  }
  return 0;
}
