#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<char>> v;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
bool isv(int i, int j) {
  return (i >= 0 && j >= 0 && i < n && j < m && v[i][j] != '#');
}
bool sat(int i, int j) {
  if (!isv(i, j)) return 0;
  int count = 0;
  for (int q = 0; q < 4; q++)
    count += (isv(i + dx[q], j + dy[q]) && v[i + dx[q]][j + dy[q]] == '.');
  return (count < 2);
}
void dfs(int i, int j) {
  for (int q = 0; q < 4; q++) {
    int x = i + dx[q], y = j + dy[q];
    if (sat(x, y) && v[x][y] != '+') {
      v[x][y] = '+';
      dfs(x, y);
    }
  }
}
int main() {
  int _TC, sti, stj;
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> _TC;
  while (_TC--) {
    string s;
    cin >> n >> m;
    v.resize(n);
    for (int j = 0; j < n; j++) v[j].resize(m);
    for (int i = 0; i < n; i++) {
      cin >> s;
      for (int j = 0; j < m; j++) {
        v[i][j] = s[j];
        if (s[j] == 'L') {
          sti = i;
          stj = j;
          v[i][j] = '+';
        }
      }
    }
    dfs(sti, stj);
    v[sti][stj] = 'L';
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) cout << v[i][j];
      cout << '\n';
    }
  }
}
