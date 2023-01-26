#include <bits/stdc++.h>
using namespace std;
using cd = complex<double>;
mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
const long long N = 1e6 + 5;
long long a[N], n, d[N][2][2];
pair<long long, long long> p[N][2][2];
long long sg(long long x) {
  if (x == 0)
    return 1;
  else
    return -1;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long q;
  cin >> q;
  while (q--) {
    cin >> n;
    for (long long i = 1; i <= n; i++) {
      cin >> a[i];
      d[i][0][0] = d[i][0][1] = d[i][1][0] = d[i][1][1] = 2e18;
    }
    d[1][0][1] = d[1][0][0] = -2e18;
    for (long long i = 1; i < n; i++) {
      for (long long j = 0; j < 2; j++) {
        for (long long k = 0; k < 2; k++) {
          for (long long v = 0; v < 2; v++) {
            if (d[i][j][k] > 1e18) continue;
            long long x = j ? d[i][j][k] : a[i] * sg(k);
            long long y = j ? a[i] * sg(k) : d[i][j][k];
            long long z = a[i + 1] * sg(v);
            if (x < y) continue;
            if (z > x) {
              if (d[i + 1][0][v] > y) {
                d[i + 1][0][v] = y;
                p[i + 1][0][v] = {j, k};
              }
            } else if (z > y) {
              if (d[i + 1][1][v] > x) {
                d[i + 1][1][v] = x;
                p[i + 1][1][v] = {j, k};
              }
            }
          }
        }
      }
    }
    long long x = -1, y = -1;
    for (long long i = 0; i < 2; i++) {
      for (long long j = 0; j < 2; j++) {
        if (d[n][i][j] < 2e18) {
          x = i;
          y = j;
        }
      }
    }
    if (x == -1)
      cout << "NO" << endl;
    else {
      for (long long i = n; i >= 1; i--) {
        if (y) a[i] *= -1;
        pair<long long, long long> v = p[i][x][y];
        x = v.first;
        y = v.second;
      }
      cout << "YES" << endl;
      for (long long i = 1; i <= n; i++) {
        cout << a[i] << " ";
      }
      cout << endl;
    }
  }
}
