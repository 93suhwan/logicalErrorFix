#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long i, j, n, z, m, k, sum = 0, q, x, y, count = 0, first = 0;
    cin >> n;
    long long a[n][5];
    vector<pair<long long, long long>> v(5, {100000000, -1});
    for (i = 0; i < n; i++) {
      for (j = 0; j < 5; j++) {
        cin >> a[i][j];
        if (a[i][j] < v[j].first) {
          v[j].first = a[i][j];
          v[j].second = i;
        }
      }
    }
    for (i = 0; i < 5; i++) {
      x = v[i].second;
      vector<long long> val(n, 0);
      count = n;
      for (j = 0; j < n; j++) {
        for (k = 0; k < 5; k++) {
          if (a[j][k] >= a[x][k]) {
            val[j]++;
            if (val[j] == 3) count--;
          }
        }
      }
      if (count == 0) {
        cout << x + 1 << "\n";
        first++;
        break;
      }
    }
    if (first == 0) cout << "-1\n";
  }
  return 0;
}
