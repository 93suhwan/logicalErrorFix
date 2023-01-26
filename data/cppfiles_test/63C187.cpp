#include <bits/stdc++.h>
using namespace std;
class DisjointSet {
  vector<int> rank, parent;
  int n;

 public:
  DisjointSet(int num) {
    n = num;
    for (int i = 0; i < n; i++) {
      rank.push_back(0);
      parent.push_back(i);
    }
  }
  int find(int x) {
    if (parent[x] != x) {
      parent[x] = find(parent[x]);
    }
    return parent[x];
  }
  void Union(int x, int y) {
    int xset = find(x);
    int yset = find(y);
    if (xset == yset) return;
    if (rank[xset] < rank[yset]) {
      parent[xset] = yset;
    } else if (rank[xset] > rank[yset]) {
      parent[yset] = xset;
    } else {
      parent[yset] = xset;
      rank[xset] = rank[xset] + 1;
    }
  }
};
int main() {
  int t = 1;
  while (t--) {
    long long n = 0, a, b;
    cin >> n >> a >> b;
    DisjointSet DJMocha(n + 1);
    DisjointSet DJDiana(n + 1);
    int mocha[n + 1][n + 1], diana[n + 1][n + 1];
    memset(mocha, 0, sizeof(mocha));
    memset(diana, 0, sizeof(diana));
    for (int i = 0; i < a; i++) {
      int x, y;
      cin >> x >> y;
      mocha[x][y] = 1;
      mocha[y][x] = 1;
      DJMocha.Union(x, y);
    }
    for (int i = 0; i < b; i++) {
      int x, y;
      cin >> x >> y;
      diana[x][y] = 1;
      diana[y][x] = 1;
      DJDiana.Union(x, y);
    }
    vector<pair<int, int>> ans;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (i == j) continue;
        if (mocha[i][j] == 0 && diana[i][j] == 0) {
          if (DJMocha.find(i) != DJMocha.find(j) &&
              DJDiana.find(i) != DJDiana.find(j)) {
            DJMocha.Union(i, j);
            DJDiana.Union(i, j);
            ans.push_back({i, j});
            mocha[i][j] = 1;
            mocha[j][i] = 1;
            diana[i][j] = 1;
            diana[j][i] = 1;
          }
        }
      }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
      cout << ans[i].first << " " << ans[i].second << endl;
    }
  }
  return 0;
}
