#include <bits/stdc++.h>
using namespace std;
const long long N = 2e3 + 5;
void nxt(char &x) {
  if (x == 'z')
    x = 'a';
  else
    x++;
}
void solve() {
  long long n, m, k;
  cin >> n >> m >> k;
  vector<string> mat(n, string(m, '.'));
  char x = 'a';
  if (m & 1) {
    for (long long i = 0; i < n; i += 2) {
      mat[i][m - 1] = mat[i + 1][m - 1] = x;
      nxt(x);
    }
    m--;
  }
  if (n & 1) {
    for (long long j = 0; j < m; j += 2) {
      mat[n - 1][j] = mat[n - 1][j + 1] = x;
      nxt(x);
    }
    k -= m / 2;
    n--;
  }
  if (n * m / 2 < k or k & 1 or k < 0) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  for (long long i = 0; i < n; i += 2) {
    for (long long j = 0; j < m; j += 2) {
      if (k) {
        if (i and mat[i - 1][j] == x) nxt(x);
        if (j and mat[i][j - 1] == x) nxt(x);
        if (i and mat[i - 1][j] == x) nxt(x);
        mat[i][j] = mat[i][j + 1] = x;
        nxt(x);
        mat[i + 1][j] = mat[i + 1][j + 1] = x;
        nxt(x);
        k -= 2;
      } else {
        if (i and mat[i - 1][j] == x) nxt(x);
        if (j and mat[i][j - 1] == x) nxt(x);
        if (i and mat[i - 1][j] == x) nxt(x);
        mat[i][j] = mat[i + 1][j] = x;
        nxt(x);
        mat[i][j + 1] = mat[i + 1][j + 1] = x;
        nxt(x);
      }
    }
  }
  for (string &x : mat) cout << x << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  long long T = 1;
  cin >> T;
  for (long long i = 1; i <= T; i++) {
    solve();
  }
}
string solvegg() {
  long long n, m, k;
  cin >> n >> m >> k;
  m -= m % 2;
  if (n * m / 2 < k) return "NO";
  return "YES";
}
