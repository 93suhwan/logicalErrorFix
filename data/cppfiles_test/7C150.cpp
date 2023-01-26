#include <bits/stdc++.h>
using namespace std;
const int N = 200050, P = 20;
long long gcd(long long x, long long y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}
long long ln[N];
long long st[P][N];
long long qry(long long x, long long y) {
  int z = ln[y - x + 1];
  return gcd(st[z][x], st[z][y - (1 << z) + 1]);
}
int main() {
  int t;
  cin >> t;
  ln[0] = -1;
  for (int i = 1; i < N; i++) ln[i] = ln[i >> 1] + 1;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n + 1], b[n];
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n - 1; i++) {
      b[i] = abs(a[i + 1] - a[i]);
      st[0][i] = b[i];
    }
    n--;
    for (int i = 1; i < P; i++)
      for (int j = 1; j <= n - (1 << i) + 1; j++)
        st[i][j] = gcd(st[i - 1][j], st[i - 1][j + (1 << i - 1)]);
    long long rez = 0;
    for (int i = 1; i <= n; i++)
      while (i + rez <= n && qry(i, i + rez) != 1) rez++;
    cout << rez + 1 << endl;
  }
  return 0;
}
