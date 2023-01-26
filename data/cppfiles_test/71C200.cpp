#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
using namespace std;
vector<int> digits;
int k, cur_k;
bool used[10];
int64_t dfs(int pos, int64_t prefix, bool same) {
  if (pos == digits.size()) return prefix;
  int tried = 0;
  int64_t ans = INT_MAX;
  for (int i = 0; i < 10; ++i) {
    if (tried == 2) break;
    if (same && i < digits[pos]) continue;
    if (k == cur_k && !used[i]) continue;
    bool is_new = used[i];
    if (!is_new) {
      used[i] = true;
      ++cur_k;
    }
    ++tried;
    ans = min(ans, dfs(pos + 1, prefix * 10 + i, same && i == digits[pos]));
    if (!is_new) {
      used[i] = false;
      --cur_k;
    }
  }
  return ans;
}
void solve() {
  int64_t n;
  cin >> n >> k;
  digits.clear();
  cur_k = 0;
  memset(used, 0, sizeof(used));
  int64_t temp = n;
  while (temp) {
    digits.push_back(temp % 10);
    temp /= 10;
  }
  reverse(digits.begin(), digits.end());
  int64_t ans = dfs(0, 0, true);
  cout << ans << "\n";
  return;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
