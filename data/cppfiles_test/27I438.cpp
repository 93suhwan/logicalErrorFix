#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    long long int n, m, k;
    cin >> n >> m >> k;
    if (k == 0 || k == 1)
      cout << "NO\n";
    else if (k == 2) {
      if (m <= 1)
        cout << "YES\n";
      else
        cout << "NO\n";
    } else if (k > 2) {
      if (m == (n * (n - 1)) / 2)
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  }
}
