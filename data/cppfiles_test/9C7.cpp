#include <bits/stdc++.h>
using namespace std;
pair<int, int> p[1010][1010];
pair<int, int> dsu(pair<int, int> a) {
  if (p[a.first][a.second] == a) return a;
  return p[a.first][a.second] = dsu(p[a.first][a.second]);
}
int n, m, k;
int mat[1010][1010];
int main() {
  cin >> n >> m >> k;
  for (int i = 0; i <= n; i++)
    for (int j = 0; j < m; j++) p[i][j] = {i, j};
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> mat[i][j];
      if (mat[i][j] == 2) p[i][j] = {i + 1, j};
    }
  for (int i = 0; i < k; i++) {
    int c;
    cin >> c;
    pair<int, int> x = {0, c - 1};
    while (x.first < n) {
      while (mat[x.first][x.second] != 2) {
        p[x.first][x.second] = dsu({x.first + 1, x.second});
        pair<int, int> tmp = x;
        if (mat[x.first][x.second] == 1)
          tmp.second++;
        else
          tmp.second--;
        mat[x.first][x.second] = 2;
        x = tmp;
      }
      x = dsu(x);
    }
    cout << x.second + 1 << " ";
  }
  cout << endl;
}
