#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 2e5 + 1;
int cnt0, cnt1;
bool bud[MAXN];
int n;
vector<int> g[MAXN];
void dfs(int now, int pre) {
  bool have = 0;
  for (auto it : g[now])
    if (it != pre) {
      dfs(it, now);
      if (!bud[it]) {
        have = 1;
        if (now == 1) {
          cnt0++;
        }
      }
    }
  if (have && now != 1) {
    bud[now] = 1;
    cnt1++;
  }
}
void solve() {
  cnt0 = cnt1 = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) g[i].clear(), bud[i] = 0;
  for (int i = 1; i <= n - 1; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 0);
  int answer = 0;
  for (int i = 2; i <= n; ++i) {
    answer += !bud[i];
  }
  if (cnt1) {
    answer -= cnt1 - 1;
    if (cnt0) answer--;
  }
  cout << answer << endl;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
