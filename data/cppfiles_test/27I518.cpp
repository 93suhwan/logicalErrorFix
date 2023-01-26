#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    int dia = 0;
    if (m == 0) {
      if (n == 1)
        dia = 1;
      else
        dia = INT_MAX;
    } else {
      if (m < n - 1)
        dia = INT_MAX;
      else if (m > (n * (n - 1)) / 2)
        dia = INT_MAX;
      else if (m == (n * (n - 1)) / 2)
        dia = 2;
      else
        dia = 3;
    }
    if (dia < k)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
