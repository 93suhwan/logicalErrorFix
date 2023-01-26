#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const long long MIN = -1e18, MAX = 1e18;
long long f[100][100];
char b[100][100];
void sol() {
  long long m, n, shit;
  cin >> m >> n >> shit;
  for (long long i = 1; i <= m; i++) {
    for (long long j = 1; j <= n; j++) {
      cin >> b[i][j];
    }
  }
  for (long long i = 1; i <= m; i++) {
    for (long long j = 1; j <= n; j++) {
      if (b[i][j] == '*') {
        long long d1 = 0, d2 = 0, temp;
        for (long long k = 1; k <= m + n; k++) {
          if (i - k > 0 and j - k > 0) {
            if (b[i - k][j - k] == '*') {
              d1++;
            } else {
              break;
            }
          } else
            break;
        }
        for (long long k = 1; k <= m + n; k++) {
          if (i - k > 0 and j + k <= n) {
            if (b[i - k][j + k] == '*') {
              d2++;
            }
          } else
            break;
        }
        temp = min(d1, d2);
        if (temp > 0) {
          f[i][j] = temp;
          for (long long k = 1; k <= temp; k++) {
            f[i - k][j - k] = max(f[i - k][j - k], temp);
            f[i - k][j + k] = max(f[i - k][j + k], temp);
          }
        }
      }
    }
  }
  for (long long i = 1; i <= m; i++) {
    for (long long j = 1; j <= n; j++) {
      if (b[i][j] == '*' and f[i][j] < shit) {
        cout << "NO" << '\n';
        return;
      }
    }
  }
  cout << "YES" << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    sol();
  }
}
