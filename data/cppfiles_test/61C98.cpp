#include <bits/stdc++.h>
using namespace std;
const int mxn = 20000005;
vector<int> adj[200005];
int vis[200005];
vector<int> ans;
void dfs(int u) {
  vis[u] = 1;
  int track = 0;
  ans.push_back(u);
  int sz = adj[u].size();
  for (int i = 0; i < sz; i++) {
    if (vis[adj[u][i]]) continue;
    if (track > 0) ans.push_back(u);
    track = 1;
    dfs(adj[u][i]);
  }
  if (track > 0) ans.push_back(u);
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string a;
    cin >> a;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
      if (a[i] != '?') {
        ans.push_back(i);
      }
    }
    vector<char> track;
    track.push_back('B');
    track.push_back('R');
    int sz = ans.size();
    if (ans.size() == 0) {
      for (int i = 0; i < n; i++) {
        if (i % 2)
          cout << 'B';
        else
          cout << "R";
      }
      cout << '\n';
    } else if (ans.size() == n)
      cout << a << '\n';
    else {
      for (int i = 0; i < sz; i++) {
        if (i == 0) {
          int tr = 0;
          if (a[ans[i]] == 'B')
            tr = 0;
          else
            tr = 1;
          for (int j = ans[i] - 1; j >= 0; j--) {
            a[j] = track[tr ^ 1];
            tr ^= 1;
          }
        } else {
          int tr = 0;
          if (a[ans[i]] == 'B')
            tr = 0;
          else
            tr = 1;
          for (int j = ans[i] - 1; j > ans[i - 1]; j--) {
            a[j] = track[tr ^ 1];
            tr ^= 1;
          }
        }
      }
      int tr = 0;
      if (a[ans[sz - 1]] == 'B')
        tr = 0;
      else
        tr = 1;
      for (int j = ans[sz - 1] + 1; j < n; j++) {
        a[j] = track[tr ^ 1];
        tr ^= 1;
      }
      cout << a << '\n';
    }
  }
  return 0;
}
