#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    long long mn = n - 1, mx = ((long long)n * (n - 1)) / 2;
    if (m < mn or m > mx) {
      cout << "NO\n";
      continue;
    }
    k -= 2;
    if (n == 1 and k >= 0)
      cout << "YES\n";
    else if (n != 1 and k >= 2)
      cout << "YES\n";
    else if (n != 1 and k == 1 and m == mx)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
