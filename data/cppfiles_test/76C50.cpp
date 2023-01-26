#include <bits/stdc++.h>
using namespace std;
const int maxn = 50;
bool g[maxn][maxn] = {};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  n = min(n, maxn);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    if (a >= maxn || b >= maxn) continue;
    g[a][b] = g[b][a] = true;
  }
  vector<bool> sor(n, false);
  for (int i = n - 5; i < n; i++) sor[i] = true;
  do {
    vector<int> v;
    for (int i = 0; i < n; i++)
      if (sor[i]) v.push_back(i);
    int db = 0;
    for (int i = 0; i < 4; i++)
      for (int j = i + 1; j < 5; j++) db += g[v[i]][v[j]];
    if (db == 0 || db == 10) {
      for (int &x : v) cout << x + 1 << ' ';
      cout << '\n';
      return 0;
    }
  } while (next_permutation(sor.begin(), sor.end()));
  cout << "-1\n";
  return 0;
}
