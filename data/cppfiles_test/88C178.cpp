#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n];
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
    }
    string ans = "NO";
    if (n % 2 == 0) {
      cout << "YES\n";
      continue;
    }
    bool ok = false;
    for (long long i = 0; i < n; i++) {
      if (a[i] >= a[i + 1]) ok = true;
    }
    if (ok) ans = "YES";
    cout << ans << endl;
  }
  return 0;
}
