#include <bits/stdc++.h>
using namespace std;
vector<long long> dep;
vector<vector<long long>> v;
vector<int> visited;
long long n;
long long maxdepth(long long node) {
  visited[node] = 1;
  for (long long i = 0; i < v[node].size(); i++) {
    if (dep[v[node][i]] == 0) {
      if (node < v[node][i])
        dep[node] = max(dep[node], 1 + maxdepth(v[node][i]));
      else
        dep[node] = max(dep[node], maxdepth(v[node][i]));
    } else {
      if (node < v[node][i])
        dep[node] = max(dep[node], 1 + dep[v[node][i]]);
      else
        dep[node] = max(dep[node], dep[v[node][i]]);
    }
  }
  return dep[node];
}
bool cycle(long long root, vector<long long>& stv, vector<long long>& cv) {
  cv[root] = 1;
  stv[root] = 1;
  for (long long i = 0; i < v[root].size(); i++) {
    if (cv[v[root][i]] == 0) {
      if (cycle(v[root][i], stv, cv) == true) return true;
    } else if (stv[v[root][i]] == true)
      return true;
  }
  stv[root] = 0;
  return false;
}
bool iscyclic() {
  vector<long long> cv(n + 1);
  vector<long long> stv(n + 1);
  for (int i = 1; i < n + 1; i++) {
    if (cv[i]) continue;
    if (cycle(i, stv, cv)) return true;
  }
  return false;
}
int solve() {
  cin >> n;
  v.clear();
  dep.clear();
  visited.clear();
  v.resize(n + 1);
  dep.resize(n + 1);
  visited.resize(n + 1);
  for (long long i = 1; i < n + 1; i++) {
    long long temp;
    cin >> temp;
    v[i].resize(temp);
    for (long long j = 0; j < temp; j++) {
      cin >> v[i][j];
    }
  }
  if (iscyclic()) return -2;
  for (long long i = 1; i < n + 1; i++) {
    if (visited[i] == 0) {
      maxdepth(i);
    }
  }
  return *max_element(dep.begin(), dep.end());
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long res = solve() + 1LL;
    cout << res << '\n';
  }
  return 0;
}
