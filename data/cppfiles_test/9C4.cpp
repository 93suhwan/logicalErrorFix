#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int mat[1010][1010];
struct dsu {
  vector<int> parent;
  dsu(int n) {
    parent.resize(n);
    for (int i = 0; i < n; i++) parent[i] = i;
  }
  int find_set(int a) {
    if (parent[a] == a) return a;
    return parent[a] = find_set(parent[a]);
  }
  int merge(int a, int b) {
    int x = find_set(a), y = find_set(b);
    parent[x] = y;
    return x;
  }
  bool are_same(int a, int b) { return find_set(a) == find_set(b); }
  int size(int a) { return -parent[find_set(a)]; }
};
inline int coord(int i, int j) { return i * m + j; }
inline pair<int, int> coord(int hash) { return {hash / m, hash % m}; }
int main() {
  cin >> n >> m >> k;
  dsu dsu(1001123);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &mat[i][j]);
    }
  }
  for (int i = 0; i < k; i++) {
    int c;
    cin >> c;
    c--;
    int row = 0;
    while (row < n) {
      int current_cell = mat[row][c];
      if (current_cell == 1) {
        mat[row][c] = 2;
        dsu.merge(coord(row, c), coord(row + 1, c));
        c++;
      } else if (current_cell == 3) {
        mat[row][c] = 2;
        dsu.merge(coord(row, c), coord(row + 1, c));
        c--;
      } else {
        int new_step = dsu.find_set(coord(row, c));
        if (!dsu.are_same(coord(row, c), coord(row + 1, c)))
          dsu.merge(coord(row, c), coord(row + 1, c));
        auto next_coord = coord(new_step);
        row = next_coord.first;
        c = next_coord.second;
        continue;
      }
    }
    printf("%d ", c + 1);
  }
  cout << endl;
  return 0;
}
