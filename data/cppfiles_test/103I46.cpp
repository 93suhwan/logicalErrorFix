#include <bits/stdc++.h>
using namespace std;
const int N = 2020;
int f[N][N], n, m;
char p[N][N];
int st[N][N], ans = 0, ans1, ans2;
map<int, int> mp;
vector<pair<int, int>> v;
int get(int x, int y) { return (x - 1) * m + y; }
int dfs(int x, int y) {
  st[x][y] = 1;
  v.push_back({x, y});
  mp[get(x, y)] = 1;
  f[x][y] = 1;
  int ux = x, uy = y;
  if (p[x][y] == 'R')
    uy++;
  else if (p[x][y] == 'L')
    uy--;
  else if (p[x][y] == 'U')
    ux--;
  else
    ux++;
  if (ux >= 1 && ux <= n && uy <= 1 && uy <= m && mp[get(ux, uy)]) {
    vector<pair<int, int>> temp;
    while (1) {
      pair<int, int> now = v.back();
      v.pop_back();
      temp.push_back(now);
      if (now.first == ux && now.second == uy) break;
    }
    for (int i = 0; i < temp.size(); i++)
      f[temp[i].first][temp[i].second] = temp.size();
  } else if (ux >= 1 && ux <= n && uy >= 1 && uy <= m) {
    if (st[ux][uy]) {
      f[x][y] += f[ux][uy];
      if (v.size()) v.pop_back();
    } else {
      int tt = dfs(ux, uy);
      if (v.size() && v.back().first == x && v.back().second == y)
        f[x][y] += tt, v.pop_back();
    }
  } else if (v.size())
    v.pop_back();
  if (f[x][y] > ans) {
    ans = f[x][y];
    ans1 = x, ans2 = y;
  }
  return f[x][y];
}
int main(void) {
  int t;
  scanf("%d", &t);
  while (t--) {
    mp.clear();
    ans = ans1 = ans2 = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) f[i][j] = -1, st[i][j] = 0;
    for (int i = 1; i <= n; i++) scanf("%s", p[i] + 1);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (!st[i][j]) v.clear(), mp.clear(), dfs(i, j);
      }
    }
    cout << ans1 << " " << ans2 << " " << ans << endl;
  }
  return 0;
}
