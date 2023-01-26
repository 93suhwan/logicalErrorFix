#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
const int MAXN = 1 << 13;
int r[MAXN], ans[MAXN];
vector<int> g[MAXN];
inline void solve() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < MAXN; i++) {
    g[i].push_back(0);
  }
  for (int i = 0; i < MAXN; i++) {
    r[i] = MAXN;
  }
  ans[0] = 1;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    for (int j = 0; j < g[x].size(); j++) {
      int to = g[x][j] ^ x;
      ans[to] = 1;
      while (r[to] > x) {
        r[to]--;
        if (r[to] != x) g[r[to]].push_back(to);
      }
    }
    g[x].clear();
  }
  int cnt = 0;
  for (int i = 0; i < MAXN; i++) {
    if (ans[i] == 1) cnt++;
  }
  printf("%d\n", cnt);
  for (int i = 0; i < MAXN; i++) {
    if (i == 0)
      printf("%d", i);
    else if (ans[i] == 1)
      printf(" %d", i);
  }
  printf("\n");
}
int main() { solve(); }
