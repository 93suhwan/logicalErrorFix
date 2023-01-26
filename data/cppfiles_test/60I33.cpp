#include <bits/stdc++.h>
using namespace std;
const int NMAX = 200000;
int n;
int a[1 + NMAX + 1];
int cautareBinara(int st, int dr, int val) {
  int sol = st - 1;
  while (st <= dr) {
    int mij = (st + dr) / 2;
    if (a[mij] <= val) {
      sol = mij;
      st = mij + 1;
    } else {
      dr = mij - 1;
    }
  }
  return sol;
}
int main() {
  int t;
  cin >> t;
  a[0] = INT_MIN;
  while (t--) {
    cin >> n;
    long long suma = 0ll;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      suma += a[i];
    }
    if (2.0 * suma / n != 2ll * suma / n) {
      cout << 0 << '\n';
      continue;
    }
    int medie = suma / n;
    sort(a + 1, a + 1 + n);
    int sol = 0;
    a[n + 1] = INT_MAX;
    int indexCrt = 1;
    while (indexCrt <= n && 2 * medie - a[indexCrt] >= a[indexCrt]) {
      int indexSt =
          cautareBinara(indexCrt + 1, n + 1, 2 * medie - a[indexCrt] - 1);
      int indexDr = cautareBinara(indexCrt + 1, n + 1, 2 * medie - a[indexCrt]);
      indexCrt++;
      if (indexSt == -1 || indexDr == -1) continue;
      sol += indexDr - indexSt;
    }
    cout << sol << '\n';
  }
  return 0;
}
