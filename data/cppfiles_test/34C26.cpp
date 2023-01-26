#include <bits/stdc++.h>
using namespace std;
const int MAXN = (1 << 13) - 1;
int r[MAXN + 1], ans[MAXN + 1];
vector<int> g[MAXN + 1];
inline void solve() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i <= MAXN; i++) {
    g[i].push_back(0);
    r[i] = MAXN;
  }
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    for (int j = 0; j < g[x].size(); j++) {
      int to = g[x][j] ^ x;
      ans[to] = 1;
      while (r[to] > x) {
        g[r[to]].push_back(to);
        r[to]--;
      }
    }
    g[x].clear();
  }
  int cnt = 0;
  ans[0] = 1;
  for (int i = 0; i <= MAXN; i++) {
    if (ans[i] == 1) cnt++;
  }
  printf("%d\n", cnt);
  for (int i = 0; i <= MAXN; i++) {
    if (i == 0)
      printf("%d", i);
    else if (ans[i] == 1)
      printf(" %d", i);
  }
  printf("\n");
}
int main() { solve(); }
