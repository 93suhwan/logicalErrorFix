#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
char s[N];
int n, a[N], vis[N], nxt[N];
vector<int> p, st[N];
void init() {
  for (int i = 2; i < N; i++) {
    if (!vis[i])
      vis[i] = i, p.push_back(i);
    else {
      for (auto j : p) {
        if (i * j >= N) continue;
        vis[i * j] = j;
        if (i % j == 0) break;
      }
    }
  }
}
void add(int x, int p) {
  while (x != 1) {
    int w = vis[x];
    st[w].push_back(p);
    x /= w;
  }
}
void del(int x, int p) {
  while (x != 1) {
    int w = vis[x];
    if (st[w].empty()) return void(nxt[p] = 0);
    nxt[p] = min(nxt[p], st[w].back());
    st[w].pop_back();
  }
}
int main() {
  init();
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  scanf("%s", s + 1);
  for (int i = 1; i <= n; i++) {
    nxt[i] = i;
    if (s[i] == '*')
      add(a[i], i);
    else
      del(a[i], i);
  }
  vector<pair<int, int>> f;
  long long res = 0;
  for (int i = n; i >= 1; i--) {
    long long cnt = 1;
    while (!f.empty() && f.back().first >= nxt[i]) {
      cnt += f.back().second;
      f.pop_back();
    }
    f.push_back({nxt[i], cnt});
    if (nxt[i] == i) res += cnt;
  }
  printf("%lld\n", res);
  return 0;
}
