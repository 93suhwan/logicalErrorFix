#include <bits/stdc++.h>
using namespace std;
class tile {
 public:
  bool n, s, e, w;
  bool visited = false;
  int i, j;
  void make_walls(int n);
  void print() {
    cout << "(" << i << "," << j << ") "
         << "n " << n << " "
         << "e " << e << " "
         << "s " << s << " "
         << "w " << w << " " << endl;
  }
};
void tile::make_walls(int x) {
  w = x & 1;
  s = (x >> 1) & 1;
  e = (x >> 2) & 1;
  n = (x >> 3) & 1;
}
void solve() {
  int n, m, x;
  cin >> n >> m;
  tile tiles[n][m];
  vector<int> sizes;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      tile temp;
      cin >> x;
      temp.make_walls(x);
      temp.i = i;
      temp.j = j;
      tiles[i][j] = temp;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (tiles[i][j].visited) continue;
      int size = 1;
      tiles[i][j].visited = true;
      tile temp;
      queue<tile> q;
      q.push(tiles[i][j]);
      while (!q.empty()) {
        temp = q.front();
        q.pop();
        for (int p = temp.j; p < m; p++) {
          if (!tiles[temp.i][p].visited) {
            size++;
            tiles[temp.i][p].visited = true;
            q.push(tiles[temp.i][p]);
          }
          if (tiles[temp.i][p].e) break;
        }
        for (int p = temp.j; p >= 0; p--) {
          if (!tiles[temp.i][p].visited) {
            size++;
            tiles[temp.i][p].visited = true;
            q.push(tiles[temp.i][p]);
          }
          if (tiles[temp.i][p].w) break;
        }
        for (int p = temp.i; p < n; p++) {
          if (!tiles[p][temp.j].visited) {
            size++;
            tiles[p][temp.j].visited = true;
            q.push(tiles[p][temp.j]);
          }
          if (tiles[p][temp.j].s) break;
        }
        for (int p = temp.i; p >= 0; p--) {
          if (!tiles[p][temp.j].visited) {
            size++;
            tiles[p][temp.j].visited = true;
            q.push(tiles[p][temp.j]);
          }
          if (tiles[p][temp.j].n) break;
        }
      }
      sizes.push_back(size);
    }
  }
  sort(sizes.begin(), sizes.end(), greater<int>());
  for (int x : sizes) {
    cout << x << " ";
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
