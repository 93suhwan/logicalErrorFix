#include <bits/stdc++.h>
using namespace std;
int a[2][100005];
int find_set(int x, int ind) {
  if (a[ind][x] == x)
    return x;
  else
    find_set(a[ind][x], ind);
}
void union_set(int x, int y, int ind) {
  x = find_set(x, ind);
  y = find_set(y, ind);
  if (x != y) a[ind][y] = x;
}
int main() {
  int n, m1, m2;
  cin >> n >> m1 >> m2;
  for (int i = 1; i <= n; i++) {
    a[0][i] = i;
    a[1][i] = i;
  }
  for (int i = 1; i <= m1; i++) {
    int x, y;
    cin >> x >> y;
    union_set(x, y, 0);
  }
  for (int i = 1; i <= m2; i++) {
    int x, y;
    cin >> x >> y;
    union_set(x, y, 1);
  }
  vector<pair<int, int>> ans;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (find_set(i, 0) != find_set(j, 0) &&
          find_set(i, 1) != find_set(j, 1)) {
        union_set(i, j, 0);
        union_set(i, j, 1);
        ans.push_back(make_pair(i, j));
      }
    }
  }
  cout << ans.size() << endl;
  for (auto it : ans) cout << it.first << " " << it.second << endl;
  return 0;
}
