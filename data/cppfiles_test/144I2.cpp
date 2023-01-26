#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long i, j, k, n, m;
  cin >> n >> m >> k;
  long long nbm = n / m, r = n % m;
  long long mnr = m - r;
  long long sm = min(nbm * mnr, r * (nbm + 1));
  long long a[mnr][nbm], b[r][nbm + 1];
  long long cnt = 1;
  for (i = 0; i < mnr; i++) {
    for (j = 0; j < nbm; j++) {
      a[i][j] = cnt;
      cnt++;
    }
  }
  for (i = 0; i < r; i++) {
    for (j = 0; j < nbm + 1; j++) {
      b[i][j] = cnt;
      cnt++;
    }
  }
  long long i1 = 0, j1 = 0, i2 = 0, j2 = 0;
  while (k--) {
    for (i = 0; i < mnr; i++) {
      cout << nbm << " ";
      for (j = 0; j < nbm; j++) {
        cout << a[i][j] << " ";
      }
      cout << "\n";
    }
    for (i = 0; i < r; i++) {
      cout << nbm + 1 << " ";
      for (j = 0; j < nbm + 1; j++) {
        cout << b[i][j] << " ";
      }
      cout << "\n";
    }
    cnt = 0;
    while (cnt < sm) {
      if (j1 >= nbm) {
        j1 = 0;
        i1++;
      }
      if (i1 >= mnr) {
        i1 = 0;
      }
      if (j2 >= nbm + 1) {
        j2 = 0;
        i2++;
      }
      if (i2 >= r) {
        i2 = 0;
      }
      swap(a[i1][j1], b[i2][j2]);
      i1++;
      i2++;
      j1++;
      j2++;
      cnt++;
    }
  }
  cout << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
