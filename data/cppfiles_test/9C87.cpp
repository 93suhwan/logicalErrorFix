#include <bits/stdc++.h>
using namespace std;
int arr[1000][1000], n, m, k, pos;
vector<int> ans;
int main() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &arr[i][j]);
    }
  }
  for (int i = 0; i < k; i++) {
    scanf("%d", &pos);
    pair<int, int> p = {0, pos - 1};
    while (p.first != n) {
      if (arr[p.first][p.second] == 1) {
        arr[p.first][p.second] = 2;
        p.second++;
      } else if (arr[p.first][p.second] == 2) {
        p.first++;
      } else if (arr[p.first][p.second] == 3) {
        arr[p.first][p.second] = 2;
        p.second--;
      }
    }
    ans.push_back(p.second + 1);
  }
  for (int i = 0; i < k; i++) {
    printf("%d ", ans[i]);
  }
  return 0;
}
