#include <bits/stdc++.h>
const int mod = 1000000007;
const int INF = 2e9 + 2;
const int N = 2e5 + 5;
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b) {
  return (a.first > b.first || (a.first == b.first && a.second < b.second));
}
int n, m, k;
void help(vector<std::vector<char>> &v, int x, int y,
          vector<std::vector<int>> &vis) {
  int a = x - 1, b = y - 1, c = x - 1, d = y + 1, l = 0;
  while (a >= 0 && b >= 0 && c >= 0 && d < m && v[a][b] == '*' &&
         v[c][d] == '*') {
    l++;
    a--, b--, c--, d++;
  }
  if (l < k) return;
  vis[x][y] = 1;
  a = x - 1, b = y - 1, c = x - 1, d = y + 1;
  while (l--) {
    vis[a][b] = 1, vis[c][d] = 1;
    a--, b--, c--, d++;
  }
}
void sol(int tc) {
  cin >> n >> m >> k;
  std::vector<std::vector<int>> v(n, std::vector<int>(m, 0));
  std::vector<std::vector<char>> a(n, std::vector<char>(m, '0'));
  for (long long i = 0; i < (long long)n; i++)
    for (long long j = 0; j < (long long)m; j++) cin >> a[i][j];
  for (long long i = 0; i < (long long)n; i++) {
    for (long long j = 0; j < (long long)m; j++) {
      if (a[i][j] == '*' && !v[i][j]) {
        help(a, i, j, v);
      }
    }
  }
  bool f = 0;
  for (long long i = 0; i < (long long)n; i++) {
    for (long long j = 0; j < (long long)m; j++) {
      if (a[i][j] == '*' && !v[i][j]) {
        cout << "NO\n";
        return;
      }
    }
  }
  cout << "YES\n";
}
int main() {
  int TC;
  TC = 1;
  cin >> TC;
  for (int tc = 1; tc <= TC; tc++) {
    sol(tc);
  }
  return 0;
}
