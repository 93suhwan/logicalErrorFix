#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1000005;
const long long inf = 0x3f3f3f3f;
long long s[maxn];
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  long long n, m;
  cin >> n >> m;
  vector<vector<char>> a;
  a.resize(n + 1, vector<char>(m + 1));
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      if (a[i][j - 1] == 'X' && a[i - 1][j] == 'X') {
        s[j] = 1;
      }
    }
  }
  for (long long i = 1; i <= m; i++) {
    s[i] += s[i - 1];
  }
  long long q;
  cin >> q;
  while (q--) {
    long long l, r;
    cin >> l >> r;
    if (s[r] - s[l]) {
      cout << "NO\n";
      ;
    } else {
      cout << "YES\n";
      ;
    }
  }
}
