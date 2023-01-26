#include <bits/stdc++.h>
using namespace std;
std::vector<vector<long long>> edges;
std::vector<bool> visited;
std::vector<int> precc;
std::vector<int> depth;
std::vector<bool> degree;
long long degNumber;
void dfs(int v, int d) {
  visited[v] = true;
  for (auto &u : edges[v]) {
    if (!visited[u]) {
      depth[u] = d + 1;
      precc[u] = v;
      dfs(u, d + 1);
    }
  }
}
void change(int a) {
  if (degree[a] == true) {
    degree[a] = false;
    degNumber--;
  } else {
    degree[a] = true;
    degNumber++;
  }
}
std::vector<long long> findPath(int a, int b) {
  if (a == b) {
    return {a};
  }
  vector<long long> first;
  vector<long long> second;
  first.push_back(a);
  second.push_back(b);
  change(a);
  change(b);
  while (true) {
    if (depth[a] < depth[b]) {
      b = precc[b];
      if (a != b) {
        second.push_back(b);
      } else {
        break;
      }
    } else if (depth[b] < depth[a]) {
      a = precc[a];
      if (a != b) {
        first.push_back(a);
      } else {
        break;
      }
    } else if (depth[a] == depth[b]) {
      if (a == b) {
        break;
      } else {
        a = precc[a];
        b = precc[b];
        first.push_back(a);
        if (a != b) {
          second.push_back(b);
        } else {
          break;
        }
      }
    }
  }
  reverse(second.begin(), second.end());
  first.insert(first.end(), second.begin(), second.end());
  return first;
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  long long T, a, b, c, d, n, m, q;
  std::cin >> n >> m;
  edges.resize(n);
  visited.resize(n, false);
  depth.resize(n, -1);
  precc.resize(n, -1);
  for (int i = 0; i < m; i++) {
    std::cin >> a >> b;
    a--;
    b--;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  depth[0] = 0;
  precc[0] = -1;
  dfs(0, 0);
  vector<vector<long long>> paths;
  degNumber = 0;
  degree.resize(n, false);
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> a >> b;
    a--;
    b--;
    auto path = findPath(a, b);
    paths.push_back(path);
  }
  if (degNumber == 0) {
    cout << "YES" << endl;
    for (auto &path : paths) {
      cout << path.size() << endl;
      for (auto &node : path) {
        cout << node + 1 << " ";
      }
      cout << endl;
    }
  } else {
    cout << "NO" << endl;
    cout << degNumber / 2 << endl;
  }
}
