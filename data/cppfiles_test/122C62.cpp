#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--) {
    int n, m;
    cin >> n >> m;
    vector<int> pr(n), col(n);
    vector<vector<int> > g(n);
    vector<vector<pair<int, int> > > tree(n);
    for (int i = 0; i < n; i++) {
      pr[i] = i;
      col[i] = 0;
      g[i].push_back(i);
    }
    int flag = 1;
    for (int i = 0; i < n - 1; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      a--;
      b--;
      tree[a].push_back({b, c});
      tree[b].push_back({a, c});
      if (c == -1) continue;
      int cnt = 0;
      for (int j = 0; j < 30; j++) {
        cnt = (cnt + c % 2) % 2;
        c /= 2;
      }
      if (pr[a] == pr[b]) {
        if ((col[a] + cnt) % 2 != col[b]) flag = 0;
        continue;
      }
      int col1 = col[a], col2 = col[b];
      a = pr[a];
      b = pr[b];
      if (g[a].size() > g[b].size()) swap(a, b);
      for (auto x : g[a]) {
        pr[x] = b;
        g[b].push_back(x);
        col[x] = (col[x] + col1 + col2 + cnt) % 2;
      }
    }
    for (int i = 0; i < m; i++) {
      int a, b, p;
      cin >> a >> b >> p;
      a--;
      b--;
      if (pr[a] == pr[b]) {
        if ((col[a] + p) % 2 != col[b]) flag = 0;
        continue;
      }
      int col1 = col[a], col2 = col[b];
      a = pr[a];
      b = pr[b];
      if (g[a].size() > g[b].size()) swap(a, b);
      for (auto x : g[a]) {
        pr[x] = b;
        g[b].push_back(x);
        col[x] = (col[x] + col1 + col2 + p) % 2;
      }
    }
    if (!flag) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++)
      for (auto to : tree[i])
        if (to.first > i) {
          if (to.second != -1)
            cout << i + 1 << " " << to.first + 1 << " " << to.second << "\n";
          else {
            if (col[i] == col[to.first])
              cout << i + 1 << " " << to.first + 1 << " " << 0 << "\n";
            else
              cout << i + 1 << " " << to.first + 1 << " " << 1 << "\n";
          }
        }
  }
}
