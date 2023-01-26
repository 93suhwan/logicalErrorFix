#include <bits/stdc++.h>
using namespace std;
int currSize;
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
tile tiles[1000][1000];
void tile::make_walls(int x) {
  w = x & 1;
  s = (x >> 1) & 1;
  e = (x >> 2) & 1;
  n = (x >> 3) & 1;
}
void dfs(int i, int j) {
  if (tiles[i][j].visited) return;
  tiles[i][j].visited = true;
  currSize++;
  tile t = tiles[i][j];
  if (!t.n) dfs(i - 1, j);
  if (!t.e) dfs(i, j + 1);
  if (!t.s) dfs(i + 1, j);
  if (!t.w) dfs(i, j - 1);
}
void solve() {
  int n, m, x;
  cin >> n >> m;
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
      if (!tiles[i][j].visited) {
        currSize = 0;
        dfs(i, j);
        sizes.push_back(currSize);
      }
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
