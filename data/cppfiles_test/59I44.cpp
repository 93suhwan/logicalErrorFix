#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int a[n][5];
    for (long long int i = 0; i < n; i++) {
      for (long long int j = 0; j < 5; j++) cin >> a[i][j];
    }
    long long int f = 0;
    for (long long int i = 0; i < 5; i++) {
      set<long long int> s;
      for (long long int k = 0; k < n; k++) {
        if (a[i][k] == 1) s.insert(k);
        for (long long int j = i + 1; j < 5; j++)
          if (a[k][j] == 1) s.insert(j);
      }
      if (s.size() == n) f = 1;
    }
    if (f)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
