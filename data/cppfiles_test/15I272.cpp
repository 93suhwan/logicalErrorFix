#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long modd = 998244353;
const long long MAX = 1e5 + 5;
const long long inf = 1e9;
const long long ninf = -1e9;
long long n, m, k;
vector<string> v(11);
long long asd[11][20];
long long ans;
void go(long long x, long long y) {
  if (ans == 1) return;
  long long f = 0;
  if (asd[x][y] == 1) f = 1;
  long long h = 0;
  while (x - h >= 0 && y - h >= 0 && y + h < m && v[x - h][y - h] == '*' &&
         v[x - h][y + h] == '*') {
    h++;
  }
  h--;
  if (h < k && asd[x][y] == 0) {
    ans = 1;
    return;
  }
  h = 0;
  while (x - h >= 0 && y - h >= 0 && y + h < m && v[x - h][y - h] == '*' &&
         v[x - h][y + h] == '*') {
    asd[x - h][y - h] = 1;
    asd[x - h][y + h] = 1;
    h++;
  }
}
void solve() {
  for (long long i = 0; i < 11; i++) v[i].clear();
  ans = 0;
  cin >> n >> m >> k;
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
  }
  for (long long i = 0; i < 11; i++) {
    for (long long j = 0; j < 20; j++) asd[i][j] = 0;
  }
  for (long long i = n - 1; i >= 0; i--) {
    for (long long j = 0; j < m; j++) {
      if (v[i][j] == '*') go(i, j);
    }
  }
  if (ans == 1) {
    cout << "NO" << endl;
  } else
    cout << "YES" << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
