#include <bits/stdc++.h>
using namespace std;
int n, m;
int bian[110][110];
bool fff = 0;
bool vis[110];
int cho[110], answ[110];
void dfs(int x) {
  if (fff == 1) return;
  if (x == 6) {
    bool flag_all = 1;
    bool flag_nol = 1;
    for (int i = 1; i <= 5; i++) {
      for (int j = 1; j <= 5; j++) {
        if (i == j) continue;
        if (bian[cho[i]][cho[j]] == 0) flag_all = 0;
        if (bian[cho[i]][cho[j]] == 1) flag_nol = 0;
      }
    }
    if (flag_all == 1 || flag_nol == 1) {
      for (int i = 1; i <= 5; i++) {
        fff = 1;
        answ[i] = cho[i];
      }
    }
    return;
  }
  for (int i = 1; i <= min(n, 50); i++) {
    if (vis[i] == 1) continue;
    bool Ft = 1;
    bool Gg = 1;
    for (int j = 1; j < x; j++) {
      if (bian[cho[j]][i] == 1) Gg = 0;
      if (bian[cho[j]][i] == 0) Ft = 0;
    }
    if (Ft == 0 && Gg == 0) continue;
    cho[x] = i;
    vis[i] = 1;
    dfs(x + 1);
    if (fff == 1) return;
    cho[x] = 0;
    vis[i] = 0;
  }
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    if (a <= 50 && b <= 50) {
      bian[a][b] = 1;
      bian[b][a] = 1;
    }
  }
  dfs(1);
  if (fff == 1) {
    for (int i = 1; i <= 5; i++) cout << answ[i] << ' ';
    return 0;
  } else {
    cout << "-1" << endl;
  }
  return 0;
}
