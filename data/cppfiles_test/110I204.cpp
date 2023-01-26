#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5 + 5;
vector<long long> graph[MAX];
long long a[MAX];
long long in[MAX]{};
long long n;
long long bfs(queue<long long> q) {
  bool visited[MAX]{};
  vector<long long> r;
  while (q.size()) {
    long long u = q.front();
    q.pop();
    visited[u] = true;
    r.push_back(u);
  }
  for (long long i = 0; i < r.size(); i++) {
    q.push(r[i]);
  }
  while (q.size()) {
    long long u = q.front();
    q.pop();
    for (long long v : graph[u]) {
      if (in[v]) {
        in[v]--;
        q.push(v);
      }
      if (in[v] == 0 && visited[v] == false) {
        visited[v] = true;
        r.push_back(v);
      }
    }
  }
  if (r.size() < n) return -1;
  vector<long long> c(n);
  long long mc = r[0];
  for (long long i = 0; i < r.size(); i++) {
    c[i] = min(r[i], mc);
  }
  long long cnt = 0;
  for (long long i = 0; i < c.size(); i++) {
    if (c[i] == r[i]) cnt++;
  }
  return cnt;
}
void solveB() {
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    graph[i].clear();
  }
  for (long long i = 1; i <= n; i++) {
    long long k;
    cin >> k;
    for (long long j = 0, v; j < k; j++) {
      cin >> v;
      graph[v].push_back(i);
    }
    in[i] = k;
  }
  queue<long long> q;
  for (long long i = 1; i <= n; i++) {
    if (in[i] == 0) {
      q.push(i);
    }
  }
  if (q.size() == 0)
    cout << "-1\n";
  else
    cout << bfs(q) << '\n';
}
int32_t main() {
  long long t = 1;
  cin >> t;
  while (t--) {
    solveB();
  }
}
