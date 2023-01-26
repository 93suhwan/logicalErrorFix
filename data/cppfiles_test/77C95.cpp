#include <bits/stdc++.h>
using namespace std;
void setIO(string name) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((name + ".in").c_str(), "r", stdin);
  freopen((name + ".out").c_str(), "w", stdout);
}
template <typename T>
void PVecPrint(vector<T>& v) {
  for (int i = 0; i < (int)v.size(); i++)
    cout << v[i].first << "," << v[i].second << ' ';
  cout << '\n';
}
template <class T>
void VecPrint(vector<T>& v) {
  for (int i = 0; i < v.size(); i++) cout << v[i] << ' ';
  cout << '\n';
}
string dtob(int n) {
  string ans(4, '0');
  int id = 3;
  while (n > 0) {
    if (n % 2) ans[id] = '1';
    --id;
    n /= 2;
  }
  return ans;
}
vector<string> str(16);
int n, m;
vector<vector<int> > v(1010, vector<int>(1010)), vis;
int cnt = 0;
vector<pair<int, int> > dir{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int isin(int x, int y) {
  if (x > -1 and x < n and y > -1 and y < m) return 1;
  return 0;
}
void dfs(int x, int y) {
  vis[x][y] = 1;
  int num = v[x][y];
  ++cnt;
  for (int i = 0; i < 4; i++) {
    if (str[num][i] == '1') continue;
    if (isin(x + dir[i].first, y + dir[i].second) and
        !vis[x + dir[i].first][y + dir[i].second])
      dfs(x + dir[i].first, y + dir[i].second);
  }
}
int main() {
  for (int i = 0; i < 16; i++) str[i] = dtob(i);
  cin >> n >> m;
  vis = v;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> v[i][j];
      vis[i][j] = 0;
    }
  }
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!vis[i][j]) {
        cnt = 0;
        dfs(i, j);
        ans.push_back(cnt);
      }
    }
  }
  sort(ans.begin(), ans.end(), greater<int>());
  VecPrint<int>(ans);
}
