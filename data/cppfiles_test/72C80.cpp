#include <bits/stdc++.h>
using namespace std;
long long t, k, n, ans[21], cnt[21];
string s;
bool dfs(long long now, long long val, bool tag) {
  if (val > k) return 0;
  if (now == n && val <= k) {
    for (register long long i = 0; i < n; ++i) cout << ans[i];
    cout << endl;
    return 1;
  }
  for (register long long i = tag ? s[now] - '0' : 0; i <= 9; ++i) {
    ++cnt[i];
    ans[now] = i;
    if (cnt[i] == 1) {
      if (dfs(now + 1, val + 1, tag && i == s[now] - '0')) return 1;
    } else if (dfs(now + 1, val, tag && i == s[now] - '0'))
      return 1;
    --cnt[i];
  }
  return 0;
}
signed main() {
  cin >> t;
  while (t--) {
    for (register long long i = 0; i <= 10; ++i) cnt[i] = 0;
    for (register long long i = 0; i <= 10; ++i) ans[i] = 0;
    cin >> s >> k;
    n = s.length();
    if (!dfs(0, 0, 1)) {
      cout << 10;
      for (register long long i = 2; i < k; ++i) cout << i;
      cout << endl;
    }
  }
  return 0;
}
