#include <bits/stdc++.h>
using namespace std;
long long x = -1, y = -1;
bool valid(vector<vector<char> > &a, long long i, long long j) {
  if ((i < 0) || (i >= a.size())) return false;
  if ((j < 0) || (j >= a[i].size())) return false;
  if (a[i][j] == '#') return false;
  return true;
}
void check(vector<vector<char> > &a, vector<vector<bool> > &f, long long i,
           long long j) {
  if ((i < 0) || (i >= a.size())) return;
  if ((j < 0) || (j >= a[i].size())) return;
  if (f[i][j]) return;
  if (a[i][j] == '#' || a[i][j] == '+' || a[i][j] == 'L') return;
  bool l = valid(a, i, j - 1);
  bool t = valid(a, i - 1, j);
  bool r = valid(a, i, j + 1);
  bool d = valid(a, i + 1, j);
  long long count = 0;
  if (l) count++;
  if (t) count++;
  if (r) count++;
  if (d) count++;
  if (count <= 2)
    a[i][j] = '+';
  else
    return;
  f[i][j] = true;
  check(a, f, i - 1, j);
  check(a, f, i + 1, j);
  check(a, f, i, j - 1);
  check(a, f, i, j + 1);
  return;
}
void solve() {
  long long n, m;
  cin >> n >> m;
  vector<vector<char> > a;
  vector<vector<bool> > f;
  for (long long i = 0; i < n; i++) {
    vector<char> aa(m);
    vector<bool> ff(m, false);
    a.push_back(aa);
    f.push_back(ff);
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      cin >> a[i][j];
      if (a[i][j] == 'L') {
        x = i;
        y = j;
      }
    }
  }
  f[x][y] = true;
  check(a, f, x - 1, y);
  check(a, f, x + 1, y);
  check(a, f, x, y - 1);
  check(a, f, x, y + 1);
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      cout << a[i][j];
    }
    cout << "\n";
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
