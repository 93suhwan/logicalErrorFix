#include <bits/stdc++.h>
using namespace std;
struct UnionFind {
  int numSets;
  vector<int> padre, rango, numVertices;
  UnionFind(int N) : numSets(N) {
    padre.assign(N + 1, 0);
    rango.assign(N + 1, 0);
    numVertices.assign(N + 1, 0);
    for (int i = 0; i <= N; ++i) {
      padre[i] = i;
      rango[i] = 0;
      numVertices[i] = 1;
    }
  }
  int findSet(int x) {
    return (x == padre[x]) ? x : (padre[x] = findSet(padre[x]));
  }
  bool isSameSet(int x, int y) { return findSet(x) == findSet(y); }
  void unionSet(int x, int y) {
    int xRoot = findSet(x);
    int yRoot = findSet(y);
    if (!isSameSet(xRoot, yRoot)) {
      if (rango[xRoot] > rango[yRoot]) {
        padre[yRoot] = xRoot;
        numVertices[xRoot] += numVertices[yRoot];
      } else {
        padre[xRoot] = yRoot;
        numVertices[yRoot] += numVertices[xRoot];
        if (rango[xRoot] == rango[yRoot]) rango[yRoot]++;
      }
      numSets--;
    }
  }
  int sizeOfSet(int x) { return numVertices[findSet(x)]; }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m1, m2, u, v;
  vector<pair<int, int>> aristas;
  cin >> n >> m1 >> m2;
  UnionFind mocha(n), diana(n);
  for (int i = 0; i < m1; i++) {
    cin >> u >> v;
    u--;
    v--;
    if (u > v) swap(u, v);
    mocha.unionSet(u, v);
  }
  for (int i = 0; i < m2; i++) {
    cin >> u >> v;
    u--;
    v--;
    if (u > v) swap(u, v);
    diana.unionSet(u, v);
  }
  vector<pair<int, int>> ans;
  for (int i = 1; i < n; i++) {
    if (!mocha.isSameSet(0, i) and !diana.isSameSet(0, i)) {
      mocha.unionSet(0, i);
      diana.unionSet(0, i);
      ans.emplace_back(0, i);
    }
  }
  vector<int> p1, p2;
  for (int i = 1; i < n; i++) {
    if (mocha.isSameSet(0, i)) p1.emplace_back(i);
    if (diana.isSameSet(0, i)) p2.emplace_back(i);
  }
  while (!p1.empty() and !p2.empty()) {
    if (diana.isSameSet(0, p1.back())) {
      p1.pop_back();
      continue;
    }
    if (mocha.isSameSet(0, p2.back())) {
      p2.pop_back();
      continue;
    }
    ans.emplace_back(p1.back(), p2.back());
    diana.unionSet(0, p1.back());
    p1.pop_back();
    mocha.unionSet(0, p2.back());
    p2.pop_back();
  }
  cout << ans.size() << "\n";
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i].first + 1 << " " << ans[i].second + 1 << "\n";
  return 0;
}
