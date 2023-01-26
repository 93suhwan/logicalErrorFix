#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e16;
const double EPS = 1e-9;
const char nn = '\n';
const char ss = ' ';
const long long mod = 1e9 + 7;
long long n, m;
char findChar(long long i, long long j, long long h) {
  if (h) {
    if (i % 4 == 0) {
      if (j % 4)
        return 'b';
      else
        return 'a';
    } else if (i % 4 == 1) {
      if (j % 4)
        return 'd';
      else
        return 'c';
    } else if (i % 4 == 2) {
      if (j % 4)
        return 'h';
      else
        return 'g';
    } else {
      if (j % 4)
        return 'j';
      else
        return 'i';
    }
  } else {
    if (i % 4) return 'e';
    return 'f';
  }
}
void solve_test() {
  long long n, m, k;
  cin >> n >> m >> k;
  long long h, v;
  long long tot = (n * m) / 2;
  if (m % 2)
    h = n * (m - 1) / 2;
  else
    h = n * m / 2;
  if (n % 2)
    v = m * (n - 1) / 2;
  else
    v = n * m / 2;
  if (k > h || (h - k) % 2 || (tot - k) > v) {
    cout << (0 ? "YES" : "NO") << nn;
  } else {
    cout << (1 ? "YES" : "NO") << nn;
    vector<string> ans(n, string(m, '.'));
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < (m / 2) * 2; j += 2) {
        char ch = findChar(i, j, 1);
        ans[i][j] = ans[i][j + 1] = ch;
      }
    }
    if (m % 2) {
      for (long long i = 0; i < n; i += 2) {
        char ch = findChar(i, m - 1, 0);
        ans[i + 1][m - 1] = ans[i][m - 1] = ch;
      }
    }
    long long i = 0, j = 0;
    for (long long c = 1; c <= (h - k); c += 2) {
      if (j + 1 < m) {
        swap(ans[i][j + 1], ans[i + 1][j]);
        j += 2;
      } else {
        i += 2, j = 0;
        swap(ans[i][j + 1], ans[i + 1][j]);
        j += 2;
      }
    }
    for (auto &s : ans) cout << s << nn;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) solve_test();
  return 0;
}
