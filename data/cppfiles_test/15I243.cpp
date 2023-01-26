#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007LL;
long long C[105][105];
int dis[105], headers[105];
int cnt;
struct line {
  int from;
  int to;
  int next;
};
struct line que[205];
void add(int from, int to) {
  cnt++;
  que[cnt].from = from;
  que[cnt].to = to;
  que[cnt].next = headers[from];
  headers[from] = cnt;
}
int depth[105];
void dfs(int place, int father) {
  dis[place] = dis[father] + 1;
  depth[dis[place]]++;
  for (int i = headers[place]; i; i = que[i].next)
    if (que[i].to != father) dfs(que[i].to, place);
}
int main() {
  int n, t, u, v, k;
  scanf("%d", &t);
  for (int i = 0; i <= 100; i++) C[i][0] = 1;
  for (int i = 1; i <= 100; i++)
    for (int j = 1; j <= i; j++)
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
  while (t--) {
    scanf("%d%d", &n, &k);
    cnt = 0;
    for (int i = 1; i <= n; i++) headers[i] = 0;
    for (int i = 1; i < n; i++) {
      scanf("%d%d", &u, &v);
      add(u, v);
      add(v, u);
    }
    if (k == 2) {
      printf("%d\n", n * (n - 1) / 2);
      continue;
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
      vector<vector<int>> son;
      for (int j = headers[i]; j; j = que[j].next) {
        vector<int> temp;
        temp.push_back(0);
        for (int k = 1; k <= n; k++) depth[k] = 0;
        dis[i] = 0;
        dfs(que[j].to, i);
        for (int j = 1; j <= n; j++) temp.push_back(depth[j]);
        son.push_back(temp);
      }
      for (int j = 1; j <= n; j++) {
        int tot = 0;
        long long temp = 1;
        for (int l = 0; l < son.size(); l++)
          if (son[l][j]) {
            tot++;
            temp = temp * son[l][j];
          }
        ans = (ans + C[tot][k] * temp % mod) % mod;
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
