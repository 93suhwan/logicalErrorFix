#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
long long n, m, q;
long long mat[1005][1005] = {};
long long ans = 0;
bool valid(long long x, long long y) {
  if (x < n && y < m && x >= 0 && y >= 0 && mat[x][y] == 0) return true;
  return false;
}
void solve() {
  cin >> n >> m >> q;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      long long x = n - i, y = m - j;
      ans += min(2 * x - 1, 2 * y) + min(2 * y - 1, 2 * x) - 1;
    }
  }
  for (long long i = 0; i < q; i++) {
    long long x, y;
    cin >> x >> y;
    x--, y--;
    long long c = 0;
    long long aa = 0, bb = 0, cc = 0, dd = 0;
    long long b = 1;
    bool p = mat[x][y];
    mat[x][y] = 0;
    bool pa = true, push_back = true, pc = true, pd = true;
    for (long long i = x, j = y; i < n && j < m; i++, j++) {
      if (mat[i][j]) break;
      if (pa && valid(i + 1, j))
        aa++;
      else
        pa = false;
      if (pa && valid(i + 1, j) && valid(i + 1, j + 1)) aa++;
      if (push_back && valid(i, j + 1))
        bb++;
      else
        push_back = false;
      if (push_back && valid(i, j + 1) && valid(i + 1, j + 1)) bb++;
    }
    for (long long i = x, j = y; i >= 0 && j >= 0; i--, j--) {
      if (mat[i][j]) break;
      if (pc && valid(i - 1, j)) {
        cc++;
        if (valid(i - 1, j - 1)) cc++;
      } else
        pc = false;
      if (pd && valid(i, j - 1)) {
        dd++;
        if (valid(i - 1, j - 1)) dd++;
      } else
        pd = false;
    }
    c = b + aa + bb + cc + dd + cc * bb + dd * aa;
    if (p) {
      ans += c;
    } else
      ans -= c;
    mat[x][y] = p ^ 1;
    cout << ans << endl;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  t = 1;
  while (t--) solve();
}
