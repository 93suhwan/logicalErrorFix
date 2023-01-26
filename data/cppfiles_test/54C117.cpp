#include <bits/stdc++.h>
using namespace std;
vector<int> type(2 * 100005);
vector<int> type2(2 * 100005);
int first = 0;
int counter1 = 0;
int counter2 = 0;
int f2 = 0;
int counter12 = 0;
int counter22 = 0;
void dfs(int x, vector<pair<int, int> > adj[]) {
  if (type[x] == 1)
    counter1++;
  else
    counter2++;
  for (auto &i : adj[x]) {
    if (type[x] == 1) {
      if (type[i.first] == 0) {
        if (i.second == 1)
          type[i.first] = 1;
        else
          type[i.first] = 2;
        dfs(i.first, adj);
      } else if (type[i.first] != i.second)
        first = 1;
    } else {
      if (type[i.first] == 0) {
        if (i.second == 1)
          type[i.first] = 2;
        else
          type[i.first] = 1;
        dfs(i.first, adj);
      } else if (type[i.first] == i.second)
        first = 1;
    }
  }
}
void dfs2(int x, vector<pair<int, int> > adj[]) {
  if (type2[x] == 1)
    counter12++;
  else
    counter22++;
  for (auto &i : adj[x]) {
    if (type2[x] == 1) {
      if (type2[i.first] == 0) {
        if (i.second == 1)
          type2[i.first] = 1;
        else
          type2[i.first] = 2;
        dfs2(i.first, adj);
      } else if (type2[i.first] != i.second)
        f2 = 1;
    } else {
      if (type2[i.first] == 0) {
        if (i.second == 1)
          type2[i.first] = 2;
        else
          type2[i.first] = 1;
        dfs2(i.first, adj);
      } else if (type2[i.first] == i.second)
        f2 = 1;
    }
  }
}
void solve() {
  int n, m;
  cin >> n >> m;
  type.assign(n, 0);
  type2.assign(n, 0);
  vector<pair<int, int> > adj[n];
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a -= 1;
    b -= 1;
    string t;
    cin >> t;
    int temp = 1;
    if (t == "imposter") temp = 2;
    adj[a].push_back({b, temp});
    adj[b].push_back({a, temp});
  }
  int flag = 0;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (type[i] == 0) {
      int temp = 0;
      type[i] = 2;
      first = 0;
      counter1 = 0;
      counter2 = 0;
      dfs(i, adj);
      f2 = 0;
      type2[i] = 1;
      counter12 = 0;
      counter22 = 0;
      dfs2(i, adj);
      if (first == 1 && f2 == 1) flag = 1;
      if (first != 1) temp = counter2;
      if (f2 != 1) temp = max(temp, counter22);
      ans += temp;
    }
  }
  if (flag == 1)
    cout << -1 << endl;
  else {
    cout << ans << endl;
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
