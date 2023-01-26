#include <bits/stdc++.h>
using namespace std;
vector<vector<char>> mat;
vector<vector<bool>> vis;
long long n, m, li, lj;
string s;
long long di[4] = {0, 0, 1, -1};
long long dj[4] = {1, -1, 0, 0};
bool safe(long long i, long long j) {
  return (i >= 0 and j >= 0 and i < n and j < m and mat[i][j] == '.');
}
void check(long long i, long long j, long long pi, long long pj) {
  if (not safe(i, j) or vis[i][j]) {
    return;
  }
  vis[i][j] = true;
  long long posi = -1, posj = -1;
  for (long long k = 0; k < 4; k++) {
    long long i_ = i + di[k], j_ = j + dj[k];
    if (i_ == pi and j_ == pj) continue;
    if (safe(i_, j_)) {
      if (posi == -1) {
        posi = i_;
        posj = j_;
      } else
        return;
    }
  }
  mat[i][j] = '+';
  check(posi, posj, i, j);
}
void solve() {
  cin >> n >> m;
  mat = vector<vector<char>>(n, vector<char>(m));
  vis = vector<vector<bool>>(n, vector<bool>(m));
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      cin >> mat[i][j];
      if (mat[i][j] == 'L') {
        li = i;
        lj = j;
      }
    }
  }
  for (long long k = 0; k < 4; k++) {
    check(li + di[k], lj + dj[k], li, lj);
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      cout << mat[i][j];
    }
    cout << endl;
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
