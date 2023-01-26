#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  for (int i = 0; i < n; ++i) cin >> s[i];
  vector<int> ans(n);
  const auto b = ans.begin(), e = ans.end();
  iota(b, e, 0), sort(b, e, [&](int i, int j) {
    int k = 0;
    while (s[i][k] == s[j][k]) ++k;
    const int p = k & 1, x = s[i][k], y = s[j][k];
    return p ? x > y : x < y;
  });
  for (int i = 0; i < n; ++i) cout << ans[i] + 1 << ' ';
}
