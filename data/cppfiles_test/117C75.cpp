#include <bits/stdc++.h>
using namespace std;
long long mo = 1e9 + 7;
long long n, m;
vector<string> v(n);
void calc(long long y, long long x) {
  if (y < 0 || y >= n || x < 0 || x >= m || v[y][x] != '.') {
    return;
  }
  long long count = 0;
  if (y - 1 >= 0 && v[y - 1][x] == '.') {
    count++;
  }
  if (x - 1 >= 0 && v[y][x - 1] == '.') {
    count++;
  }
  if (y + 1 < n && v[y + 1][x] == '.') {
    count++;
  }
  if (x + 1 < m && v[y][x + 1] == '.') {
    count++;
  }
  if (count <= 1) {
    v[y][x] = '+';
    calc(y + 1, x);
    calc(y - 1, x);
    calc(y, x + 1);
    calc(y, x - 1);
  }
}
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    v.clear();
    v.resize(n);
    for (long long i = 0; i < n; ++i) {
      cin >> v[i];
    }
    long long x, y;
    for (long long i = 0; i < n; ++i) {
      for (long long j = 0; j < m; ++j) {
        if (v[i][j] == 'L') {
          y = i;
          x = j;
          break;
        }
      }
    }
    calc(y + 1, x);
    calc(y - 1, x);
    calc(y, x + 1);
    calc(y, x - 1);
    for (long long i = 0; i < n; ++i) {
      cout << v[i] << "\n";
    }
  }
}
