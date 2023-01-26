#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
  return os << '(' << p.first << ", " << p.second << ')';
}
template <typename T_container, typename T = typename enable_if<
                                    !is_same<T_container, string>::value,
                                    typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v) {
  os << '{';
  string sep;
  for (const T &x : v) os << sep << x, sep = ", ";
  return os << '}';
}
void dbg_out() { cerr << '\n'; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}
void dfs(int node, vector<bool> &visited, vector<vector<int>> &graph) {
  visited[node] = true;
  for (auto n : graph[node]) {
    if (!visited[n]) {
      dfs(n, visited, graph);
    }
  }
}
void run_case() {
  int N;
  cin >> N;
  vector<pair<int, int>> A(N), B(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i].first;
    A[i].second = i;
  }
  for (int i = 0; i < N; i++) {
    cin >> B[i].first;
    B[i].second = i;
  }
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  vector<vector<int>> graph(N);
  for (int i = 0; i < N - 1; i++) {
    graph[A[i].second].push_back(A[i + 1].second);
    graph[B[i].second].push_back(B[i + 1].second);
  }
  vector<bool> visited(N);
  int node1 = A.back().second, node2 = B.back().second;
  for (auto node : {node1, node2}) {
    if (!visited[node1]) {
      dfs(node, visited, graph);
    }
  }
  for (int i = 0; i < N; i++) {
    cout << visited[i];
  }
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int tests = 1;
  cin >> tests;
  while (tests--) {
    run_case();
    cout << '\n';
  }
}
