#include <bits/stdc++.h>
using namespace std;
long long pref[200005][3];
long long calc(long long l, long long r, long long p) {
  l--;
  while ((l % 3) != (r % 3)) {
    if (l < 0) {
      return pref[r][p];
    }
    l--;
  }
  if (l < 0) {
    return pref[r][p];
  }
  return pref[r][p] - pref[l][p];
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  for (long long i = 0; i < s.length(); i++) {
    for (long long j = 0; j < 3; j++) {
      if (s[i] == (char)(j + 'a')) {
        pref[i][j] = 0;
      } else {
        pref[i][j] = 1;
      }
      if (i >= 3) {
        pref[i][j] += pref[i - 3][j];
      }
    }
  }
  string sub = "";
  while (m--) {
    long long l, r;
    cin >> l >> r;
    l--;
    r--;
    long long res = r - l + 1;
    if (l == r) {
      cout << 0 << '\n';
      continue;
    }
    for (long long i = 0; i < 3; i++) {
      for (long long j = 0; j < 3; j++) {
        for (long long k = 0; k < 3; k++) {
          if (i == j) continue;
          if (i == k) continue;
          if (j == k) continue;
          long long ans = 0;
          sub = "";
          sub += (char)('a' + i);
          sub += (char)('a' + j);
          sub += (char)('a' + k);
          for (long long p = r; p > r - 3; p--) {
            ans += calc(l, p, sub[r - p] - 'a');
          }
          res = min(res, ans);
        }
      }
    }
    cout << res << '\n';
  }
  return 0;
}
