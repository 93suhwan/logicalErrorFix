#include <bits/stdc++.h>
using namespace std;
const int INF = (int)(1e9) + 10;
int n, k;
int ans;
string s;
void update(int pos, int mask, int num) {
  if (pos == (int)s.size()) {
    ans = num;
    return;
  }
  if (__builtin_popcount(mask) < k) {
    for (int i = pos; i < (int)s.size(); i++) num *= 10;
    ans = num;
    return;
  }
  if (__builtin_popcount(mask) == k) {
    for (int d = 0; d < 10; d++) {
      if (((1 << d) | mask) == mask) {
        for (int i = pos; i < (int)s.size(); i++) num = num * 10 + d;
        ans = num;
        return;
      };
    }
  };
  return;
}
bool go(int pos, bool upper, int mask, int num) {
  if ((pos == (int)s.size()) || upper) {
    update(pos, mask, num);
    return true;
  }
  int low_d = (upper) ? 0 : s[pos] - '0';
  for (int d = low_d; d < 10; d++) {
    int new_mask = mask | (1 << d);
    if (__builtin_popcount(new_mask) <= k) {
      if (go(pos + 1, upper || (d > s[pos] - '0'), new_mask, num * 10 + d))
        return true;
    }
  }
  return false;
};
void solve() {
  cin >> n >> k;
  s = to_string(n);
  ans = 0;
  go(0, 0, 0, 0);
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T = 1;
  cin >> T;
  while (T--) solve();
  return 0;
}
