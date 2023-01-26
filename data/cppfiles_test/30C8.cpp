#include <bits/stdc++.h>
using namespace std;
int n, q;
int par[1000002];
int a[150001];
bool comp[1000002];
int smallest[1000002];
vector<int> pr[1000002];
vector<int> primes;
int find(int x) {
  if (par[x] == x) return x;
  return par[x] = find(par[x]);
}
void join(int x, int y) {
  int a = find(x);
  int b = find(y);
  par[a] = b;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> q;
  int m = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    m = max(m, a[i] + 1);
  }
  for (int i = 1; i <= m; i++) par[i] = i;
  for (int i = 2; i <= m; i++) {
    if (!comp[i]) {
      primes.push_back(i);
      smallest[i] = i;
    }
    for (auto &p : primes) {
      if (i * p > m) break;
      comp[i * p] = 1;
      smallest[i * p] = p;
      if (i % p == 0) break;
    }
  }
  for (int i = 1; i <= n; i++) {
    int x = a[i];
    while (x > 1) {
      int p = smallest[x];
      join(a[i], p);
      while (x % p == 0) x /= p;
    }
    x = a[i] + 1;
    while (x > 1) {
      int p = smallest[x];
      pr[a[i] + 1].push_back(p);
      while (x % p == 0) x /= p;
    }
  }
  vector<pair<int, int> > edges;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < (int)pr[a[i] + 1].size(); j++) {
      if (find(a[i]) != find(pr[a[i] + 1][j]))
        edges.push_back({min(find(a[i]), find(pr[a[i] + 1][j])),
                         max(find(a[i]), find(pr[a[i] + 1][j]))});
      for (int k = j + 1; k < (int)pr[a[i] + 1].size(); k++) {
        int x = find(pr[a[i] + 1][j]);
        int y = find(pr[a[i] + 1][k]);
        if (x != y) edges.push_back({min(x, y), max(x, y)});
      }
    }
  }
  sort(edges.begin(), edges.end());
  edges.erase(unique(edges.begin(), edges.end()), edges.end());
  for (int i = 1; i <= q; i++) {
    int second, t;
    cin >> second >> t;
    if (find(a[second]) == find(a[t]))
      cout << 0 << '\n';
    else {
      int aa = find(a[second]);
      int bb = find(a[t]);
      if (bb < aa) swap(aa, bb);
      auto it = lower_bound(edges.begin(), edges.end(), make_pair(aa, bb));
      if (it != edges.end() && *it == make_pair(aa, bb))
        cout << 1 << '\n';
      else
        cout << 2 << '\n';
    }
  }
}
