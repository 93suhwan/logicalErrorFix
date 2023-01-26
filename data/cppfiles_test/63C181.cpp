#include <bits/stdc++.h>
long long int M = 1000000007;
using namespace std;
vector<long long int> adj1[1001];
vector<long long int> adj2[1001];
long long int v1[1001];
long long int v2[1001];
long long int vis1[1001], vis2[1001];
void dfs1(long long int x) {
  vis1[x] = 1;
  for (auto j : adj1[x]) {
    if (!vis1[j]) {
      v1[j] = 0;
      dfs1(j);
    }
  }
}
void dfs2(long long int x) {
  vis2[x] = 1;
  for (auto j : adj2[x]) {
    if (!vis2[j]) {
      v2[j] = 0;
      dfs2(j);
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << setprecision(25);
  ;
  long long int T = 1;
  while (T--) {
    long long int n, m1, m2;
    cin >> n >> m1 >> m2;
    for (long long int i = 0; i < m1; i++) {
      long long int x, y;
      cin >> x >> y;
      adj1[x].push_back(y);
      adj1[y].push_back(x);
    }
    for (long long int i = 0; i < m2; i++) {
      long long int x, y;
      cin >> x >> y;
      adj2[x].push_back(y);
      adj2[y].push_back(x);
    }
    vector<pair<long long int, long long int>> ans;
    for (long long int i = 1; i <= n; i++) {
      for (long long int j = 1; j <= n; j++) {
        vis1[j] = 0;
        vis2[j] = 0;
        v1[j] = 0;
        v2[j] = 0;
        if (j != i) v1[j] = 1;
        if (j != i) v2[j] = 1;
      }
      dfs1(i);
      dfs2(i);
      for (long long int j = 1; j <= n; j++) {
        if ((v1[j] == 1 && v2[j] == 1)) {
          ans.push_back({i, j});
          adj1[i].push_back(j);
          adj1[j].push_back(i);
          adj2[i].push_back(j);
          adj2[j].push_back(i);
          break;
        }
      }
    }
    cout << ans.size() << endl;
    for (long long int i = 0; i < ans.size(); i++)
      cout << ans[i].first << " " << ans[i].second << endl;
  }
}
