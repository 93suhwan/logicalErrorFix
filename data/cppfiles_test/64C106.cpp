#include <bits/stdc++.h>
using namespace std;
class DSU {
 private:
  vector<int> parent, rank;

 public:
  DSU(int n) {
    parent.resize(n);
    rank.resize(n);
    for (int i = 0; i < n; i++) {
      parent[i] = i;
      rank[i] = 0;
    }
  }
  int getSet(int i) {
    if (i == parent[i]) return i;
    return parent[i] = getSet(parent[i]);
  }
  int unionSets(int i, int j) {
    i = getSet(i);
    j = getSet(j);
    if (i != j) {
      if (rank[i] < rank[j]) std::swap(i, j);
      parent[j] = i;
      if (rank[i] == rank[j]) ++rank[i];
    }
    return i;
  }
};
void solve(int test, istream &in) {
  int n;
  in >> n;
  DSU dsu[2] = {DSU(n), DSU(n)};
  int m[2];
  in >> m[0] >> m[1];
  for (int k = 0; k < 2; k++) {
    for (int i = 0; i < m[k]; i++) {
      int u, v;
      in >> u >> v;
      u--;
      v--;
      dsu[k].unionSets(u, v);
    }
  }
  vector<pair<int, int>> res;
  for (int i = 1; i < n; i++) {
    if (dsu[0].getSet(0) != dsu[0].getSet(i) &&
        dsu[1].getSet(0) != dsu[1].getSet(i)) {
      res.emplace_back(0, i);
      for (int k = 0; k < 2; k++) {
        dsu[k].unionSets(0, i);
      }
    }
  }
  vector<int> q[2];
  for (int k = 0; k < 2; k++) {
    for (int i = 0; i < n; i++) {
      if (dsu[k].getSet(0) != dsu[k].getSet(i)) {
        q[k].push_back(i);
      }
    }
  }
  while (true) {
    for (int k = 0; k < 2; k++) {
      while (q[k].size() && dsu[k].getSet(0) == dsu[k].getSet(q[k].back())) {
        q[k].pop_back();
      }
    }
    if (q[0].size() && q[1].size()) {
      res.emplace_back(q[0].back(), q[1].back());
      for (int k = 0; k < 2; k++) {
        dsu[k].unionSets(q[0].back(), q[1].back());
      }
    } else {
      break;
    }
  }
  printf("%d\n", (int)res.size());
  for (int i = 0; i < res.size(); i++) {
    printf("%d %d\n", res[i].first + 1, res[i].second + 1);
  }
}
void solve1(int test, istream &in) {
  int n;
  in >> n;
  DSU dsu1(n), dsu2(n);
  int m1, m2;
  in >> m1 >> m2;
  for (int i = 0; i < m1; i++) {
    int u, v;
    in >> u >> v;
    u--;
    v--;
    dsu1.unionSets(u, v);
  }
  for (int i = 0; i < m2; i++) {
    int u, v;
    in >> u >> v;
    u--;
    v--;
    dsu2.unionSets(u, v);
  }
  vector<pair<int, int>> res;
  for (int i = 0; i < n; i++) {
    for (int j = 1; j < n; j++) {
      if (dsu1.getSet(i) != dsu1.getSet(j) &&
          dsu2.getSet(i) != dsu2.getSet(j)) {
        res.emplace_back(i, j);
        dsu1.unionSets(i, j);
        dsu2.unionSets(i, j);
      }
    }
  }
  printf("%d\n", (int)res.size());
  for (int i = 0; i < res.size(); i++) {
    printf("%d %d\n", res[i].first + 1, res[i].second + 1);
  }
}
int main(int argc, char *argv[]) {
  istream &f = cin;
  int tests = 1;
  for (int test = 0; test < tests; test++) {
    solve(test, f);
  }
  return 0;
}
