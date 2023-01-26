#include <bits/stdc++.h>
const long long mod = 998244353;
const long long inf = 1e18 + 5;
const long long infi = 2e9;
using namespace std;
const int siz = 2005;
char mat[siz][siz];
int vis[siz][siz], n, m;
vector<pair<int, int>> v;
int dfs(int x, int y) {
  pair<int, int> k = {x, y};
  int ans = 0, cnt = 0;
  while (true) {
    cnt++;
    if (cnt == 100) break;
    if (k.first > n || k.first <= 0 || k.second > m || k.second <= 0) {
      ans = 1;
      break;
    }
    if (vis[k.first][k.second] > -1) {
      ans = vis[k.first][k.second] + 1;
      break;
    }
    if (vis[k.first][k.second] == -2) {
      int idx = 0;
      for (long long i = 0; i < v.size(); i++)
        if (v[i] == k) idx = i;
      for (long long i = idx; i < v.size(); i++)
        vis[v[i].first][v[i].second] = v.size() - idx;
      ans = v.size() - idx + 1;
      break;
    }
    v.push_back(k);
    vis[k.first][k.second] = -2;
    if (mat[k.first][k.second] == 'R')
      k.second++;
    else if (mat[k.first][k.second] == 'L')
      k.second--;
    else if (mat[k.first][k.second] == 'D')
      k.first++;
    else if (mat[k.first][k.second] == 'U')
      k.first--;
    ans++;
  }
  for (int i = v.size() - 1; i >= 0; i--) {
    if (vis[v[i].first][v[i].second] != -2) continue;
    vis[v[i].first][v[i].second] = ans;
    ans++;
  }
  v.clear();
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int T;
  cin >> T;
  for (long long i = 0; i < siz; i++)
    for (long long j = 0; j < siz; j++) vis[i][j] = -1;
  while (T--) {
    cin >> n >> m;
    for (long long i = 1; i < n + 1; i++) {
      string s;
      cin >> s;
      for (long long j = 1; j < m + 1; j++) mat[i][j] = s[j - 1];
    }
    for (long long i = 1; i < n + 1; i++)
      for (long long j = 1; j < m + 1; j++)
        if (vis[i][j] == -1) dfs(i, j);
    pair<pair<long long, long long>, long long> ans = {{1, 1}, 0};
    for (long long i = 1; i < n + 1; i++)
      for (long long j = 1; j < m + 1; j++)
        if (vis[i][j] > ans.second) ans = {{i, j}, vis[i][j]};
    cout << ans.first.first << " " << ans.first.second << " " << ans.second
         << "\n";
    for (long long i = 1; i < n + 1; i++)
      for (long long j = 1; j < m + 1; j++) vis[i][j] = -1;
  }
}
