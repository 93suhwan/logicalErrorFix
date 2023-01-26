#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, mod = 1e9 + 7;
vector<vector<int>> v;
vector<vector<int>> a;
vector<int> c;
int n;
int calc(vector<int> V) {
  int ret = 0;
  for (int i = 0; i < n; i++) {
    ret += a[i][c[i] - 1 - V[i]];
  }
  return ret;
}
void gen() {
  priority_queue<pair<int, vector<int>>> q;
  q.push({calc(vector<int>(n, 0)), vector<int>(n, 0)});
  map<vector<int>, bool> vis;
  while (!q.empty()) {
    vector<int> cur = q.top().second;
    q.pop();
    v.push_back(cur);
    if ((int)v.size() > 100000) break;
    for (int i = 0; i < n; i++) {
      if (c[i] - 1 - cur[i] - 1 < 0) continue;
      cur[i]++;
      if (!vis[cur]) q.push({calc(cur), cur});
      vis[cur] = 1;
      cur[i]--;
    }
  }
}
int main() {
  int tc = 1;
  for (int cn = 1; cn <= tc; cn++) {
    scanf("%d", &n);
    a.resize(n);
    c.resize(n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &c[i]);
      a[i].resize(c[i]);
      for (int j = 0; j < c[i]; j++) scanf("%d", &a[i][j]);
    }
    int m;
    scanf("%d", &m);
    map<vector<int>, bool> banned;
    while (m--) {
      vector<int> b(n);
      for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
        b[i] = c[i] - b[i];
      }
      banned[b] = true;
    }
    gen();
    for (auto x : v) {
      if (banned[x]) continue;
      for (int i = 0; i < n; i++) {
        printf("%d ", c[i] - x[i]);
      }
      puts("");
      break;
    }
  }
  return 0;
}
