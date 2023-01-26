#include <bits/stdc++.h>
using namespace std;
signed main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<string> a(n + 2);
    string h;
    for (int i = 0; i < m + 2; ++i) {
      h += "#";
    }
    a[0] = h;
    a[n + 1] = h;
    for (int i = 1; i <= n; ++i) {
      string s;
      cin >> s;
      s = "#" + s + "#";
      a[i] = s;
    }
    deque<int> q;
    vector<char> vis(n * m);
    vector<int> ans(n * m);
    vector<vector<int>> graph(n * m);
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        int v = (i - 1) * m + (j - 1);
        if (a[i][j] == 'L') {
          q.push_back(v);
        }
        if (a[i][j] != '#') {
          if (a[i - 1][j] != '#') {
            graph[v].push_back(v - m);
          }
          if (a[i + 1][j] != '#') {
            graph[v].push_back(v + m);
          }
          if (a[i][j - 1] != '#') {
            graph[v].push_back(v - 1);
          }
          if (a[i][j + 1] != '#') {
            graph[v].push_back(v + 1);
          }
        }
      }
    }
    ans[q.front()] = 3;
    while (!q.empty()) {
      int v = q.front();
      q.pop_front();
      if (vis[v]) continue;
      vis[v] = 1;
      for (int i : graph[v]) {
        if (!vis[i]) {
          int c = 0;
          for (int j : graph[i]) {
            if (ans[j] > 1) {
              c++;
            }
          }
          if (graph[i].size() - c < 2 && c != 0) {
            ans[i] = 2;
            q.push_front(i);
          } else {
            ans[i] = 1;
            q.push_back(i);
          }
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        int l = ans[i * m + j];
        if (l == 1) {
          cout << ".";
        } else if (l == 0) {
          cout << a[i + 1][j + 1];
        } else if (l == 2) {
          cout << "+";
        } else {
          cout << "L";
        }
      }
      cout << '\n';
    }
  }
}
