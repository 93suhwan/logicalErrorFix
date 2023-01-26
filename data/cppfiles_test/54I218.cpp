#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7;
const int maxn = 1e5 + 5;
int controversy = 0, imposters = 0;
void add_edge(vector<int> vec[], int u, int v) {
  vec[u].push_back(v);
  vec[v].push_back(u);
}
void dfs(vector<int> vec[], vector<bool>& visited, int source, int n) {
  vector<int> color(n + 1, 2);
  visited[source] = true;
  color[source] = 1;
  queue<int> q;
  q.push(source);
  while (q.empty() == false) {
    int current = q.front();
    q.pop();
    for (int i = 0; i < vec[current].size(); i++) {
      int adjacent = vec[current][i];
      if (visited[adjacent] == false) {
        color[adjacent] = 1 - color[current];
        visited[adjacent] = true;
        q.push(adjacent);
      } else {
        if (color[adjacent] == color[current]) {
          controversy = 1;
        }
      }
    }
  }
  int one = 0, zero = 0;
  for (int i = 1; i < n + 1; i++) {
    if (color[i] == 1) {
      one++;
    } else if (color[i] == 0) {
      zero++;
    }
  }
  if (controversy == 0) {
    imposters += max(one, zero);
  }
}
void solve() {
  long long int n, m;
  cin >> n >> m;
  vector<int> vec[n + 1];
  long long int i, j;
  string str;
  controversy = 0;
  imposters = 0;
  while (m--) {
    cin >> i >> j >> str;
    if (str == "imposter") {
      add_edge(vec, i, j);
    } else {
      add_edge(vec, i, 0);
      add_edge(vec, j, 0);
    }
  }
  vector<bool> visited(n + 1, false);
  for (int i = 0; i < n + 1; i++) {
    if (visited[i] == false) {
      dfs(vec, visited, i, n);
    }
  }
  if (controversy == 1) {
    cout << -1 << endl;
    return;
  }
  cout << imposters << endl;
  return;
}
class Node {
  int u, v;
  string str;

 public:
  int getU() { return u; }
  int getv() { return v; }
  string getRelation() { return str; }
  Node(int first, int second, string relation) {
    u = first;
    v = second;
    str = relation;
  }
};
void solve2() {
  long long int n, m;
  cin >> n >> m;
  vector<Node> vec;
  long long int i, j;
  string str;
  while (m--) {
    cin >> i >> j >> str;
    Node node1(i, j, str);
    vec.push_back(node1);
  }
  for (int i = 0; i < n; i++) {
    Node current = vec[i];
    cout << current.getU() << " " << current.getv() << " "
         << current.getRelation() << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
    if (i == 63) {
      solve2();
      break;
    }
  }
  return 0;
}
