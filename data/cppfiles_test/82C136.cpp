#include <bits/stdc++.h>
char s[300100];
int sum[300100];
std::vector<int> val[2000100];
int n, q;
int trs(char c) { return c == '+' ? 1 : -1; }
void Solve(int l, int r, int f) {
  if (!f)
    std::cout << "1\n";
  else {
    std::cout << "2\n" << l - 1 << " ";
  }
  int tmp = sum[r] - sum[l - 1];
  if (tmp > 0)
    tmp = (tmp + 1) / 2;
  else
    tmp = (tmp - 1) / 2;
  tmp += sum[l - 1] + n;
  std::cout << *std::lower_bound(val[tmp].begin(), val[tmp].end(), l) << "\n";
}
void multi_task() {
  std::cin >> n >> q >> (s + 1);
  for (int i = 1; i <= n; ++i)
    sum[i] = sum[i - 1] + ((i - 1) & 1 ? -1 : 1) * trs(s[i]);
  for (int i = 1; i <= n; ++i) val[sum[i] + n].emplace_back(i);
  for (int l, r; q; --q) {
    std::cin >> l >> r;
    if ((r - l + 1) & 1)
      Solve(l, r, 0);
    else {
      if (sum[r] - sum[l - 1] == 0)
        std::cout << "0\n";
      else
        Solve(l + 1, r, 1);
    }
  }
  for (int i = 1; i <= n; ++i) val[sum[i] + n].clear();
}
signed main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  int T;
  for (std::cin >> T; T; --T) multi_task();
  return 0;
}
