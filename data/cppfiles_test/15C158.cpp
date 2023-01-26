#include <bits/stdc++.h>
using namespace std;
vector<string> s;
vector<string> visited;
long long n, m, k;
void check(int i, int j) {
  if (i + 1 < k || (j + 1 < k) || (m - j - 1) < k) return;
  long long a = i;
  long long l = j;
  long long r = j;
  long long temp = -1;
  while (a >= 0 && r < m && l >= 0) {
    if (s[a][l] == '*' && s[a][r] == '*')
      temp++;
    else
      break;
    a--;
    l--;
    r++;
  }
  a = i;
  l = j;
  r = j;
  if (temp >= k) {
    while (temp-- > -1 && a >= 0 && r < m && l >= 0) {
      visited[a][l] = '1';
      visited[a][r] = '1';
      a--;
      l--;
      r++;
    }
  }
}
void solve() {
  cin >> n >> m >> k;
  s.resize(n);
  visited.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    visited[i] = s[i];
    for (int j = 0; j < m; j++) visited[i][j] = '0';
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i][j] == '*') {
        check(i, j);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i][j] == '*' && visited[i][j] == '0') {
        cout << "NO" << endl;
        return;
      }
    }
  }
  cout << "YES" << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t-- > 0) {
    solve();
  }
  return 0;
}
