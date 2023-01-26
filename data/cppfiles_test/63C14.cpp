#include <bits/stdc++.h>
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  std::vector<std::string> s(n);
  for (int i = 0; i < n; ++i) std::cin >> s[i];
  std::vector<int> len(n), low(n), h(n);
  std::vector<std::vector<int>> tax(n);
  for (int i = 0; i < n; ++i) {
    len[i] = s[i].length();
    h[i] = 0;
    low[i] = 0;
    tax[i].resize(len[i] + 1);
    for (char c : s[i]) {
      h[i] += c == '(' ? 1 : -1;
      if (h[i] <= low[i]) {
        low[i] = std::min(low[i], h[i]);
        ++tax[i][h[i] + len[i]];
      }
    }
  }
  std::vector<int> f(1 << n), pre(1 << n);
  int ans = 0;
  for (int s = 1; s < (1 << n); ++s) {
    f[s] = -1;
    for (int i = 0; i < n; ++i) {
      if ((s >> i) & 1) {
        pre[s] += h[i];
        int t = s ^ (1 << i);
        if (f[t] == -1) continue;
        int val = f[t];
        if (pre[t] >= 0 && pre[t] <= len[i]) val += tax[i][len[i] - pre[t]];
        ans = std::max(ans, val);
        if (pre[t] + low[i] >= 0) f[s] = std::max(f[s], val);
      }
    }
  }
  std::cout << ans << '\n';
  return 0;
}
