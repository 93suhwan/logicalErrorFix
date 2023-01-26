#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7, M = 1e5 + 7;
int n, m, k, a[N][N], b[M];
vector<int> x2[N];
void drop(int y, int i) {
  y--;
  int x = 0;
  while (x < n) {
    if (x2[y].size() == n) {
      b[i] = y + 1;
      return;
    }
    if (a[x][y] == 1) {
      a[x][y] = 2;
      x2[y].push_back(x);
      y++;
    } else if (a[x][y] == 2) {
      x++;
    } else if (a[x][y] == 3) {
      a[x][y] = 2;
      x2[y].push_back(x);
      y--;
    }
  }
  b[i] = y + 1;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      if (a[i][j] == 2) x2[j].push_back(i);
    }
  for (int i = 0; i < k; i++) cin >> b[i];
  for (int i = 0; i < k; i++) drop(b[i], i);
  for (int i = 0; i < k; i++) cout << b[i] << ' ';
}
