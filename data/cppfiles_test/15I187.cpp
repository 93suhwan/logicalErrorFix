#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
int T;
int ans = inf;
int n, m, k;
char a[15][30];
int mp[15][30];
struct node {
  int x, y;
};
bool chk(node l, node r) {
  if (l.x < 0 || l.y < 0 || l.x > n || l.y > m || r.x < 0 || r.y < 0 ||
      r.x > n || r.y > m || a[l.x][l.y] != '*' || a[r.x][r.y] != '*')
    return 0;
  return 1;
}
void bfs(int x, int y) {
  int d = 0;
  deque<node> q;
  deque<node> q1;
  deque<node> q2;
  node tmp;
  tmp.x = x;
  tmp.y = y;
  q.push_back(tmp);
  tmp.x = x - 1;
  tmp.y = y - 1;
  q1.push_back(tmp);
  tmp.y = y + 1;
  q2.push_back(tmp);
  while (1) {
    node l = q1.back();
    q1.pop_back();
    node r = q2.back();
    q2.pop_back();
    if (!chk(l, r)) break;
    q.push_back(l);
    q.push_back(r);
    d++;
    tmp.x = l.x - 1;
    tmp.y = l.y - 1;
    q1.push_back(tmp);
    tmp.x = r.x - 1;
    tmp.y = r.y + 1;
    q2.push_back(tmp);
  }
  while (q.size()) {
    tmp = q.front();
    q.pop_front();
    mp[tmp.x][tmp.y] = max(mp[tmp.x][tmp.y], d);
  }
}
int main() {
  scanf("%d", &T);
  while (T--) {
    memset(mp, 0, sizeof(mp));
    ans = inf;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
      scanf("%s", a[i] + 1);
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (a[i][j] == '*') bfs(i, j);
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (a[i][j] == '*') {
          ans = min(ans, mp[i][j]);
        }
      }
    }
    if (ans < k || ans == inf)
      printf("NO\n");
    else
      printf("YES\n");
  }
  return 0;
}
