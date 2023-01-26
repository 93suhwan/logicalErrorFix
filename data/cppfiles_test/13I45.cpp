#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const long long INFI = 1e9 + 228;
const ll INFL = 1e18 + 228;
const ld INFLD = 1e18 + 228;
const ld PI = acos(-1);
const long long MAXN = 1e5 + 228;
vector<pair<long long, long long> > DD = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
char ans[105][105];
char get(long long i, long long j, long long i2, long long j2) {
  set<char> q = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k'};
  for (auto u : DD) {
    long long i3 = i + u.first;
    long long j3 = j + u.second;
    long long i4 = i2 + u.first;
    long long j4 = j2 + u.second;
    if (i3 >= 0 && j3 >= 0 && i3 < 105 && j3 < 105) {
      q.erase(ans[i3][j3]);
    }
    if (i4 >= 0 && j4 >= 0 && i4 < 105 && j4 < 105) {
      q.erase(ans[i4][j4]);
    }
  }
  return *q.begin();
}
void run() {
  long long n, m, k;
  cin >> n >> m >> k;
  for (long long i = 1; i <= n; ++i) {
    for (long long j = 1; j <= m; ++j) ans[i][j] = '.';
  }
  if (n % 2 != 0) {
    if (k >= m / 2 && (k - m / 2) % 2 == 0) {
      cout << "YES" << endl;
      for (long long j = 1; j <= m && k > 0; j += 2) {
        for (long long i = 1; i <= n && k > 0; ++i) {
          char now = get(i, j, i, j + 1);
          ans[i][j] = now;
          ans[i][j + 1] = now;
          k--;
        }
      }
    } else {
      cout << "NO" << endl;
      return;
    }
  } else if (m % 2 == 0) {
    if (k % 2 == 0) {
      cout << "YES" << endl;
      for (long long j = 1; j <= m && k > 0; j += 2) {
        for (long long i = 1; i <= n && k > 0; ++i) {
          char now = get(i, j, i, j + 1);
          ans[i][j] = now;
          ans[i][j + 1] = now;
          k--;
        }
      }
    } else {
      cout << "NO" << endl;
      return;
    }
  } else {
    if (k % 2 == 0 && k <= (m / 2) * n) {
      cout << "YES" << endl;
      for (long long j = 1; j <= m && k > 0; j += 2) {
        for (long long i = 1; i <= n && k > 0; ++i) {
          char now = get(i, j, i, j + 1);
          ans[i][j] = now;
          ans[i][j + 1] = now;
          k--;
        }
      }
    } else {
      cout << "NO" << endl;
      return;
    }
  }
  if (k > 0) cout << 7 / 0;
  for (long long j = 1; j <= m; ++j) {
    for (long long i = 1; i <= n; ++i) {
      if (ans[i][j] == '.') {
        char now = get(i, j, i + 1, j);
        ans[i][j] = now;
        ans[i + 1][j] = now;
      }
    }
  }
  for (long long i = 1; i <= n; ++i) {
    for (long long j = 1; j <= m; ++j) {
      cout << ans[i][j];
    }
    cout << endl;
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) run();
  return 0;
}
