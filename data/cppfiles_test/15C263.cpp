#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    char c[n][m];
    int coun = 0;
    for (int i = 0; i < n; i++)
      for (int f = 0; f < m; f++) {
        cin >> c[i][f];
        if (c[i][f] == '*') coun++;
      }
    if (coun == 0)
      cout << "YES" << endl;
    else {
      for (int i = n - 1; i >= k; i--) {
        for (int f = k; f < m - k; f++) {
          int l = 1;
          if (c[i][f] != '.')
            while (f - l >= 0 && f + l < m && c[i - l][f - l] != '.' &&
                   c[i - l][f + l] != '.') {
              if (c[i - l][f - l] == '*') coun--;
              if (c[i - l][f + l] == '*') coun--;
              c[i - l][f - l] = c[i - l][f + l] = '1';
              l++;
            }
          if (l > k && c[i][f] == '*') coun--;
        }
      }
      if (coun == 0)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
  }
  return 0;
}
