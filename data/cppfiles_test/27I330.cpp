#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1;
int T;
long long n, m, k;
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  cin >> T;
  while (T--) {
    cin >> n >> m >> k;
    if (k <= 1 || m < n - 1 || m > n * (n - 1) / 2)
      cout << "NO\n";
    else if (n == 1)
      cout << "YES\n";
    else if (n == 2) {
      if (k >= 3)
        cout << "YES\n";
      else
        cout << "NO\n";
    }
    if (m == n * (n - 1) / 2) {
      if (k >= 3)
        cout << "YES\n";
      else
        cout << "NO\n";
    }
    if (k >= 4)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
