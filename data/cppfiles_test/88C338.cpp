#include <bits/stdc++.h>
using namespace std;
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    long long a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    if (n % 2 == 0) {
      cout << "YES\n";
      continue;
    }
    bool f = 0;
    for (int i = 1; i < n; i++) {
      if (a[i] <= a[i - 1]) {
        f = 1;
        break;
      }
    }
    if (f)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
