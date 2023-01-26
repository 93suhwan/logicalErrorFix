#include <bits/stdc++.h>
using std::pair;
const int maxn = 3e5 + 10;
int n, a[maxn], b[maxn], pre[maxn], ans = -1;
bool vis[maxn];
std::queue<pair<int, int> > q;
std::vector<int> path;
void bfs() {
  q.push(pair<int, int>(n, 0));
  vis[n] = true;
  pair<int, int> cur;
  while (ans == -1 && !q.empty()) {
    cur = q.front();
    q.pop();
    for (int i = 0, pos; i <= a[cur.first]; ++i) {
      pos = cur.first - i;
      if (pos <= 0) {
        pre[0] = cur.first;
        ans = cur.second + 1;
        break;
      }
      pos += b[pos];
      if (!vis[pos]) {
        pre[pos] = cur.first;
        vis[pos] = true;
        q.push(pair<int, int>(pos, cur.second + 1));
      }
    }
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  for (int i = 1; i <= n; ++i) scanf("%d", b + i);
  bfs();
  printf("%d\n", ans);
  if (ans == -1) return 0;
  int pos = 0;
  while (pos != n) {
    path.push_back(pos);
    pos = pre[pos];
  }
  for (auto it = path.rbegin(); it != path.rend(); ++it) printf("%d ", *it);
  return 0;
}
