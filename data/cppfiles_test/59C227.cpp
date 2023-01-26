#include <bits/stdc++.h>
using namespace std;
const double pi = 3.14159265358979323846;
const int mod = 1e9 + 7;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n][5];
    int z = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 5; j++) {
        cin >> a[i][j];
      }
    }
    bool y = false;
    for (int i = 0; i < 5; i++) {
      for (int j = i + 1; j < 5; j++) {
        int d1 = 0, d2 = 0, d3 = 0;
        for (int k = 0; k < n; k++) {
          if (a[k][i] && a[k][j])
            d3++;
          else if (a[k][i])
            d1++;
          else if (a[k][j])
            d2++;
        }
        if (d1 + d2 + d3 == n && d1 <= n / 2 && d2 <= n / 2) {
          y = true;
        }
      }
    }
    if (y == true) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
