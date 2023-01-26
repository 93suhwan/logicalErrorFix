#include <bits/stdc++.h>
using namespace std;
const int mxn = 2e5 + 5, mod = 1e9 + 7;
int main(void) {
  {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  };
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    if (n % 2 == 0) {
      cout << "YES\n";
    }
    bool ok = 1;
    for (int i = 1; i < n; i++) {
      ok &= a[i] > a[i - 1];
    }
    if (ok) {
      if ((n + 1) & (n) == 0)
        cout << "YES\n";
      else
        cout << "NO\n";
    } else
      cout << "YES\n";
  }
}
