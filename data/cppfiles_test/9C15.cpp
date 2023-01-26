#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  int arr[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &arr[i][j]);
    }
  }
  int starting_pos[1000];
  memset(starting_pos, 0, sizeof(starting_pos));
  vector<int> ans;
  bool vis[n][m];
  memset(vis, false, sizeof(vis));
  while (k--) {
    int a;
    scanf("%d", &a);
    a--;
    int i = starting_pos[a];
    starting_pos[a]++;
    while (i < n) {
      if (vis[i][a] || arr[i][a] == 2) {
        vis[i][a] = true;
        i++;
      } else if (arr[i][a] == 1) {
        vis[i][a] = true;
        a++;
      } else {
        vis[i][a] = true;
        a--;
      }
    }
    ans.push_back(a + 1);
  }
  for (int i = 0; i < ans.size(); i++) {
    printf("%d ", ans[i]);
  }
  printf("\n");
}
