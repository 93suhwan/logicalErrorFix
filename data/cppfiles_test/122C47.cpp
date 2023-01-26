#include <bits/stdc++.h>
using namespace std;
bool ans;
int lala[200100], canh[200100][3];
vector<pair<int, int> > edge[200100];
int x, y, z;
int n, m;
int tinh(int x, int z) {
  if (z != 0)
    return 1 - x;
  else
    return x;
}
void dfs(int x) {
  for (pair<int, int> v : edge[x]) {
    int z = v.second;
    int y = v.first;
    if (lala[y] != -1) {
      if (lala[y] != tinh(lala[x], z)) {
        ans = false;
      }
    } else {
      lala[y] = tinh(lala[x], z);
      dfs(y);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) edge[i].clear();
    for (int i = 1; i < n; ++i) {
      cin >> x >> y >> z;
      canh[i][0] = x;
      canh[i][1] = y;
      canh[i][2] = z;
      if (z == -1) continue;
      z = __builtin_popcount(z) % 2;
      edge[x].push_back(pair<int, int>(y, z));
      edge[y].push_back(pair<int, int>(x, z));
    }
    for (int i = 1; i <= m; ++i) {
      cin >> x >> y >> z;
      z = __builtin_popcount(z) % 2;
      edge[x].push_back(pair<int, int>(y, z));
      edge[y].push_back(pair<int, int>(x, z));
    }
    memset(lala, -1, sizeof(lala));
    ans = true;
    for (int i = 1; i <= n; ++i)
      if (lala[i] == -1) {
        lala[i] = 0;
        dfs(i);
      }
    if (ans == false) {
      printf("NO\n");
      continue;
    }
    printf("YES\n");
    for (int i = 1; i < n; ++i) {
      int x = canh[i][0];
      int y = canh[i][1];
      int z = canh[i][2];
      printf("%d %d ", x, y);
      if (z != -1) {
        printf("%d\n", z);
      } else {
        if (lala[x] == lala[y])
          printf("0\n");
        else
          printf("1\n");
      }
    }
  }
}
