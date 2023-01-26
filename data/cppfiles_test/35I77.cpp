#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 6;
char s[N];
vector<int> st[N];
int n, a[N], b[N], nxt[N], vis[N], sum[N], now;
void init() {
  vector<int> p;
  for (int i = 2; i < N; i++) {
    if (!vis[i]) vis[i] = i, p.push_back(i);
    for (auto j : p) {
      if (i * j >= N) break;
      vis[i * j] = j;
      if (i % j == 0) break;
    }
  }
}
void add(int x, int p) {
  while (x != 1) {
    st[vis[x]].push_back(p);
    x /= vis[x];
  }
}
int del(int x, int p) {
  int res = p - 1;
  while (x != 1) {
    int w = vis[x];
    if (st[w].empty() || st[w].back() <= now) return -1;
    res = min(res, st[w].back());
    st[w].pop_back();
    x /= vis[x];
  }
  return res - 1;
}
int main() {
  init();
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  scanf("%s", s + 1);
  for (int i = 1; i <= n; i++) b[i] = (s[i] == '*' || a[i] == 1);
  long long cnt = 0, res = 0;
  for (int i = 1; i <= n; i++) {
    cnt += b[i];
    if (!b[i] || i == n) {
      res += (cnt + 1) * cnt / 2;
      cnt = 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (b[i])
      add(a[i], i), nxt[i] = i - 1;
    else
      nxt[i] = del(a[i], i);
    if (nxt[i] == -1) {
      now = i;
      sum[i] = 0;
    } else
      sum[i] = sum[nxt[i]] + 1;
  }
  for (int i = 1; i <= n; i++) {
    if (b[i]) continue;
    int cnt = 1;
    for (int j = i + 1; b[j] && j <= n; j++) cnt++;
    res += 1ll * sum[i] * cnt;
  }
  printf("%lld\n", res);
  return 0;
}
