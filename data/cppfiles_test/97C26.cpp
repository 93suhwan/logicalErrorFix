#include <bits/stdc++.h>
long long read() {
  long long a = 0;
  int op = 1;
  char ch = getchar();
  while (ch < '0' || '9' < ch) {
    if (ch == '-') op = -1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') {
    a = (a << 3) + (a << 1) + (48 ^ ch);
    ch = getchar();
  }
  return a * op;
}
const int B1 = 2000;
const int B2 = 110;
const int N = 2e5 + 10;
std::vector<int> tr[N];
using dp_t = int*;
int ans[N];
std::vector<std::pair<int, int>> mount[N];
int size[N];
std::pair<dp_t, dp_t> dfs(int now, int from) {
  size[now] = 1;
  dp_t dp1 = nullptr;
  dp_t dp2 = nullptr;
  int d = tr[now].size() - (now != from);
  for (int to : tr[now])
    if (to != from) {
      auto [to1, to2] = dfs(to, now);
      if (dp1 == nullptr) {
        dp1 = new int[B1];
        dp2 = new int[B2];
        for (int i = 0; i < B1; i++) dp1[i] = d;
        for (int i = 0; i < B2; i++) dp2[i] = 0;
      }
      for (int i = 0; i < B1; i++)
        if (to1[i] > i) dp1[i] += to1[i] - 1 - i;
      for (int i = B2 - 1; ~i; i--) {
        dp2[i]++;
        for (int j = std::max(0, i - size[now] - 1); j < i && j <= size[to];
             j++) {
          dp2[i] = std::max(dp2[i], dp2[i - j - 1] + to2[j]);
        }
      }
      size[now] += size[to];
      delete to1;
      delete to2;
    }
  if (dp1 == nullptr) {
    dp1 = new int[B1];
    dp2 = new int[B2];
    for (int i = 0; i < B1; i++) dp1[i] = d;
    for (int i = 0; i < B2; i++) dp2[i] = 0;
  }
  for (auto [k, id] : mount[now]) {
    if (k < B1)
      ans[id] = dp1[k];
    else
      for (int i = 0; i < B2; i++) ans[id] = std::max(ans[id], dp2[i] - k * i);
  }
  return {dp1, dp2};
}
int main() {
  int n = read();
  for (int i = 1; i < n; i++) {
    int u = read();
    int v = read();
    tr[u].push_back(v);
    tr[v].push_back(u);
  }
  int m = read();
  for (int i = 1; i <= m; i++) {
    int v = read();
    int k = read();
    mount[v].emplace_back(k, i);
  }
  dfs(1, 1);
  for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
  return 0;
}
