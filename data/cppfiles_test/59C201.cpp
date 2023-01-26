#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 5;
const long long MOD = 1e9 + 7;
const long long INF = 1e9;
const long double EPS = 1e-9;
void sol() {
  long long i, j = 1, k, l, m, n;
  cin >> n;
  int a[n][5];
  for (i = 0; i < n; i++) {
    for (j = 0; j < 5; j++) cin >> a[i][j];
  }
  bool ch = 0;
  for (i = 0; i < 5; i++) {
    for (j = i + 1; j < 5; j++) {
      int l = 0, m = 0, p = 0;
      for (k = 0; k < n; k++) {
        if (a[k][i] == 1 && a[k][j] == 0)
          l++;
        else if (a[k][i] == 0 && a[k][j] == 1)
          m++;
        else if (a[k][i] == 1 && a[k][j] == 1)
          p++;
        int req = max(0ll, n / 2 - l) + max(0ll, n / 2 - m);
        if (req <= p) {
          ch = 1;
          break;
        }
      }
    }
  }
  if (ch) {
    cout << "YES\n";
  } else
    cout << "NO\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    sol();
  }
}
