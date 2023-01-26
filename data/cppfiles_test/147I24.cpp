#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string a[n];
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n; ++i) {
    int t = a[i].length();
    int f[t];
    f[0] = 1;
    for (int j = 1; j < t; ++j) {
      if (a[i][j] == 'E')
        f[j] = f[j - 1];
      else if (a[i][j] == 'N') {
        if (f[j - 1] == 0)
          f[j] = 1;
        else if (f[j - 1] == 1)
          f[j] = 0;
      }
    }
    cout << "\n";
    if (a[i][t - 1] == 'N' && f[t - 1] == 0)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
  return 0;
}
