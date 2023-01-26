#include <bits/stdc++.h>
using namespace std;
const long long MAX = 1e9 + 1;
const long long MOD = 1e9 + 7;
void solve() {
  long long n;
  cin >> n;
  string st;
  cin >> st;
  long long c = 0;
  char d[n][n];
  for (long long i = 0; i < n; i++) {
    if (st[i] == '1') c++;
  }
  if (c == n) {
    cout << "YES\n";
    for (long long i = 0; i < n; i++)
      for (long long j = 0; j < n; j++) d[i][j] = '=';
    for (long long i = 0; i < n; i++) d[i][i] = 'X';
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < n; j++) {
        cout << d[i][j];
      }
      cout << "\n";
    }
    return;
  }
  if (c >= ((n + 1) / 2)) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  for (long long i = 0; i < n; i++)
    for (long long j = 0; j < n; j++) d[i][j] = 'c';
  for (long long i = 0; i < n; i++) d[i][i] = 'X';
  for (long long i = 0; i < n; i++) {
    if (st[i] == '1') {
      for (long long j = 0; j < n; j++) {
        if (i != j) d[i][j] = '=';
        if (i != j) d[j][i] = '=';
      }
    }
  }
  for (long long i = 0; i < n; i++) {
    if (st[i] == '2') {
      for (long long j = 0; j < n; j++) {
        if (d[i][j] != 'c' || d[j][i] != 'c') {
          continue;
        } else {
          d[i][j] = '+';
          d[j][i] = '-';
          break;
        }
      }
    }
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < n; j++) {
      if (d[i][j] == 'c') {
        d[i][j] = '=';
      }
    }
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < n; j++) {
      cout << d[i][j];
    }
    cout << "\n";
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
