#include <bits/stdc++.h>
const int N = 200010;
int stk[N];
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  int n;
  std::cin >> n;
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    int ai;
    std::cin >> ai;
    int x = i - ai;
    if (x < 0) continue;
    int pos =
        std::upper_bound(stk + 1, stk + ans + 1, x, std::greater<int>()) - stk;
    stk[pos] = x;
    if (pos == ans + 1) ++ans;
  }
  std::cout << ans << '\n';
  return 0;
}
