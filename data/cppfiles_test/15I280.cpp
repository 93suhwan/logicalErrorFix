#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long n, m, k;
vector<string> v, a;
void up(long long i, long long j, long long cur, long long cur2) {
  long long kk = cur2;
  while (cur2 >= 0 and i < n and j >= 0) {
    a[i][j] = '2';
    i++, j--;
    cur2--;
  }
  i--, j++;
  while (cur2 <= kk + 1 and i >= 0 and j >= 0) {
    a[i][j] = '2';
    i--, j--;
    cur2++;
  }
}
void ch2(long long i, long long j, long long cur, long long cur2) {
  if (cur2 >= k) {
    up(i, j, cur, cur2);
  }
  if (i - 1 >= 0 and j + 1 < m and v[i - 1][j + 1] == '*' and cur2 < cur) {
    cur2++;
    ch2(i - 1, j + 1, cur, cur2);
  } else
    return;
}
void ch(long long i, long long j, long long cur) {
  if (cur >= k) {
    ch2(i, j, cur, 0);
  }
  if (i + 1 < n and j + 1 < m and v[i + 1][j + 1] == '*') {
    cur++;
    ch(i + 1, j + 1, cur);
  } else
    return;
}
void solve() {
  cin >> n >> m >> k;
  v.resize(n), a.resize(n);
  for (long long i = 0; i < n; i++) cin >> v[i], a[i] = v[i];
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      if (v[i][j] == '.')
        a[i][j] = '2';
      else
        a[i][j] = '0';
    }
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      if (v[i][j] == '*') {
        ch(i, j, 0);
      }
    }
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      if (a[i][j] == '0') {
        cout << "NO"
             << "\n";
        return;
      }
    }
  }
  cout << "YES"
       << "\n";
  v.clear(), a.clear();
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(6) << "\n";
  long long tt;
  cin >> tt;
  while (tt--) solve();
  cerr << "\n"
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec"
       << "\n";
}
