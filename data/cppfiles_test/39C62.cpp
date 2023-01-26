#include <bits/stdc++.h>
const int maxn = 1e2 + 10;
using namespace std;
const long long mod = 1e9 + 7;
int n, a[maxn], p[maxn];
vector<pair<int, int> > G[maxn];
void query(int id, int op) {
  int x;
  if (op == 1) {
    cout << "? ";
    for (int i = 1; i <= n; i++) {
      if (i != id)
        cout << 1 << " \n"[i == n];
      else
        cout << 2 << " \n"[i == n];
    }
    cin >> x;
    if (x >= id)
      return;
    else if (!x)
      p[id] = n;
    else
      G[x].push_back({-1, id}), G[id].push_back({1, x});
  } else {
    cout << "? ";
    for (int i = 1; i <= n; i++) {
      if (i != id)
        cout << 2 << " \n"[i == n];
      else
        cout << 1 << " \n"[i == n];
    }
    cin >> x;
    if (x >= id)
      return;
    else if (!x)
      p[id] = 1;
    else
      G[x].push_back({1, id}), G[id].push_back({-1, x});
  }
}
void dfs(int u) {
  for (auto np : G[u]) {
    if (p[np.second]) continue;
    p[np.second] = p[u] + np.first;
    dfs(np.second);
  }
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) query(i, 1);
  for (int i = 1; i <= n; i++) query(i, 2);
  for (int i = 1; i <= n; i++) {
    if (p[i] == 1 || p[i] == n) {
      dfs(i);
    }
  }
  cout << "! ";
  for (int i = 1; i <= n; i++) cout << p[i] << " \n"[i == n];
}
