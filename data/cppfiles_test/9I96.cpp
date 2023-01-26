#include <bits/stdc++.h>
using namespace std;
const long double pi = acos(-1);
vector<vector<long long>> v;
long long n, m;
void fun(long long x, long long y) {
  if (x >= n || y >= m || y < 0) return;
  if (x == n - 1) {
    cout << y + 1 << ' ';
    return;
  }
  if (v[x][y] == 1) {
    v[x][y] = 2;
    fun(x, y + 1);
  } else if (v[x][y] == 2) {
    v[x][y] = 2;
    fun(x + 1, y);
  } else if (v[x][y] == 3) {
    v[x][y] = 2;
    fun(x, y - 1);
  }
}
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long k;
  cin >> n >> m >> k;
  v = vector<vector<long long>>(n, vector<long long>(m));
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      cin >> v[i][j];
    }
  }
  vector<long long> c(k);
  for (long long i = 0; i < k; i++) {
    cin >> c[i];
  }
  for (long long i = 0; i < k; i++) {
    fun(0, c[i] - 1);
  }
  cout << endl;
  return 0;
}
