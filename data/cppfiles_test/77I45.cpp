#include <bits/stdc++.h>
using namespace std;
int a[1001][1001];
bool used[1001][1001];
int color[1001][1001];
int d[1000005];
int n, m;
string bin[] = {"0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000",
                "1001", "1010", "1011", "1100", "1101", "1110", "1111"};
void dfs(int x, int y, int col) {
  color[x][y] = col;
  used[x][y] = true;
  string s = bin[a[x][y] - 1];
  if (s[0] == '0' && x > 0 && !used[x - 1][y]) {
    dfs(x - 1, y, col);
  }
  if (s[1] == '0' && y < m && !used[x][y + 1]) {
    dfs(x, y + 1, col);
  }
  if (s[2] == '0' && x < n && !used[x + 1][y]) {
    dfs(x + 1, y, col);
  }
  if (s[3] == '0' && y > 0 && !used[x][y - 1]) {
    dfs(x, y - 1, col);
  }
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  int col = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (!used[i][j]) {
        dfs(i, j, col);
        col++;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      d[color[i][j]]++;
    }
  }
  vector<int> v;
  for (int i = 1; i <= 1e6; i++) {
    if (d[i] > 0) v.push_back(d[i]);
  }
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
}
