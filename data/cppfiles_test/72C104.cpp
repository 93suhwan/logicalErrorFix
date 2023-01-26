#include <bits/stdc++.h>
using namespace std;
const int N = 11;
const int M = (1 << 10) + 1;
int n, k;
bool dp[N][M][2];
bool vis[N][M][2];
int jabo[N][M][2];
vector<int> digits;
void fun(int n) {
  while (n != 0) {
    digits.push_back(n % 10);
    n /= 10;
  }
  reverse(digits.begin(), digits.end());
}
bool solve(int idx, int mask, bool done) {
  if (__builtin_popcount(mask) > k) return 0;
  if (idx == (int)digits.size()) return 1;
  bool &ret = dp[idx][mask][done];
  if (vis[idx][mask][done]) {
    return ret;
  }
  bool ans = false;
  if (!done) {
    for (int i = digits[idx]; i <= 9; i++) {
      bool eta = 0;
      if (i != digits[idx]) eta = 1;
      if (solve(idx + 1, mask | (1 << i), eta)) {
        jabo[idx][mask][done] = i;
        ans = 1;
        break;
      }
    }
  } else {
    for (int i = 0; i <= 9; i++) {
      if (solve(idx + 1, mask | (1 << i), 1)) {
        jabo[idx][mask][done] = i;
        ans = 1;
        break;
      }
    }
  }
  return ret = ans;
}
void print(int idx, int mask, bool done) {
  if (idx == digits.size()) return;
  int i = jabo[idx][mask][done];
  cout << i;
  mask |= (1 << i);
  if (!done && i > digits[idx]) done = 1;
  print(idx + 1, mask, done);
}
void TEST_CASES() {
  memset(vis, 0, sizeof vis);
  digits.clear();
  cin >> n >> k;
  fun(n);
  bool x = solve(0, 0, 0);
  print(0, 0, 0);
  cout << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    TEST_CASES();
  }
  return 0;
}
