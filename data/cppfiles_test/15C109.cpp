#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long inf = 2e18 + 5;
vector<string> mat;
bool marked[20][20];
long long n, m, k;
bool check(long long x, long long y) {
  long long c = 1;
  long long i = 1;
  while (true) {
    if (x - i >= 0 && y - i >= 0 && y + i < m && mat[x - i][y - i] == '*' &&
        mat[x - i][y + i] == '*')
      c++;
    else {
      break;
    }
    i++;
  }
  if (c <= k)
    return false;
  else {
    marked[x][y] = true;
    for (long long i = (1); i < (c); i++) {
      marked[x - i][y - i] = true;
      marked[x - i][y + i] = true;
    }
    return true;
  }
}
void solve() {
  cin >> n >> m >> k;
  mat.clear();
  for (long long i = (0); i < (20); i++)
    for (long long j = (0); j < (20); j++) marked[i][j] = false;
  long long f = 0;
  string s;
  for (long long i = (0); i < (n); i++) {
    cin >> s;
    mat.push_back(s);
  }
  for (long long i = n - 1; i >= 0; i--) {
    for (long long j = m - 1; j >= 0; j--) {
      if (mat[i][j] == '*' && !check(i, j) && !marked[i][j]) {
        f = 1;
      }
    }
    if (f == 1) break;
  }
  if (f == 1)
    cout << "NO\n";
  else
    cout << "YES\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long cases = 1;
  cin >> cases;
  while (cases--) solve();
  return 0;
}
