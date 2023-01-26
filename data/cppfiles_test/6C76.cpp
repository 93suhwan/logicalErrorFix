#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
const long long mod = 1e9 + 7;
long long ExtendedEuclid(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long g = ExtendedEuclid(b, a % b, x, y);
  long long nx = y, ny = x - a / b * y;
  x = nx;
  y = ny;
  return g;
}
long long modInverse(long long x, long long m) {
  long long a, q;
  ExtendedEuclid(x, m, a, q);
  if (a < 0) {
    a = a + (abs(a) + m - 1) / m * m;
  }
  return a;
}
long long n, m, q;
vector<vector<set<long long>>> adj;
void solve(int testcase) {
  cin >> n >> m;
  adj = vector<vector<set<long long>>>(n, vector<set<long long>>(2));
  for (long long i = 0; i < m; i++) {
    long long u, v;
    cin >> u >> v;
    u--;
    v--;
    adj[u][(v > u)].insert(v);
    adj[v][(u > v)].insert(u);
  }
  long long ans = 0;
  for (long long i = 0; i < n; i++) {
    if (adj[i][1].size() == 0) ans++;
  }
  cin >> q;
  while (q--) {
    long long op;
    cin >> op;
    if (op == 3) {
      cout << ans << "\n";
    } else if (op == 1) {
      long long u, v;
      cin >> u >> v;
      u--;
      v--;
      if (u > v) swap(u, v);
      if (adj[u][1].size() == 0) ans--;
      adj[u][(v > u)].insert(v);
      adj[v][(u > v)].insert(u);
    } else if (op == 2) {
      long long u, v;
      cin >> u >> v;
      u--;
      v--;
      if (u > v) swap(u, v);
      if (adj[u][1].size() == 1) ans++;
      adj[u][(v > u)].erase(adj[u][(v > u)].find(v));
      adj[v][(u > v)].erase(adj[v][(u > v)].find(u));
    }
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 0;
  solve(t);
  return 0;
}
