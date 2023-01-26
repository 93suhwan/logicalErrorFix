#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1010;
vector<int> bl[MAXN][MAXN];
vector<pair<int, int> > rod[MAXN * 2];
long long ans[MAXN * 2];
bool ban[MAXN][MAXN];
void calc(int id) {
  int lst = 0;
  ans[id] = 0;
  for (int i = 0; i < (int)rod[id].size(); i++) {
    int x = rod[id][i].first;
    int y = rod[id][i].second;
    if (ban[x][y])
      lst = i + 1;
    else
      ans[id] += i - lst;
  }
}
int main() {
  int n, m, Q, cnt = 0;
  scanf("%d%d%d", &n, &m, &Q);
  for (int i = 1; i < n; i++) {
    int dx = 1, dy = 0;
    int x = i, y = 1;
    cnt++;
    while (x <= n && y <= m) {
      rod[cnt].push_back(make_pair(x, y));
      bl[x][y].push_back(cnt);
      x += dx, y += dy;
      swap(dx, dy);
    }
  }
  for (int j = 1; j < m; j++) {
    int dx = 0, dy = 1;
    int x = 1, y = j;
    cnt++;
    while (x <= n && y <= m) {
      rod[cnt].push_back(make_pair(x, y));
      bl[x][y].push_back(cnt);
      x += dx, y += dy;
      swap(dx, dy);
    }
  }
  for (int i = 1; i <= cnt; i++) calc(i);
  int x, y;
  long long all = n * m;
  while (Q--) {
    scanf("%d%d", &x, &y);
    if (ban[x][y])
      all++;
    else
      all--;
    ban[x][y] ^= 1;
    for (int id : bl[x][y]) calc(id);
    long long cur = 0;
    for (int i = 1; i <= cnt; i++) cur += ans[i];
    printf("%lld\n", cur + all);
  }
  return 0;
}
