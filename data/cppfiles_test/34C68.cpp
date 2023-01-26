#include <bits/stdc++.h>
const int maxn = 1e6 + 10;
const int maxm = (1 << 13);
std::vector<int> g[maxm];
int r[maxm];
int n;
int ans[maxm];
int main() {
  scanf("%d", &n);
  ans[0] = 1;
  for (int i = 1; i < maxm; i++) {
    g[i].emplace_back(0);
  }
  for (int i = 1; i < maxm; i++) {
    r[i] = maxm;
  }
  for (int i = 1; i <= n; i++) {
    int val;
    scanf("%d", &val);
    for (const auto &pre : g[val]) {
      int nk = (pre ^ val);
      ans[nk] = 1;
      while (r[nk] > val) {
        --r[nk];
        if (r[nk] != val) g[r[nk]].emplace_back(nk);
      }
    }
    g[val].clear();
  }
  std::vector<int> vec;
  for (int i = 0; i < maxm; i++) {
    if (ans[i]) vec.emplace_back(i);
  }
  int lens = vec.size();
  printf("%d\n", lens);
  for (int i = 0; i < lens; i++) {
    printf("%d%c", vec[i], " \n"[i == lens - 1]);
  }
  return 0;
}
