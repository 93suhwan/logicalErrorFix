#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<long long> v(n);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      sum += v[i];
    }
    bool ans = 0;
    for (int i = 2; (i * i) <= sum; i++) {
      if (sum % i == 0) ans = 1;
    }
    if (ans) {
      cout << n << endl;
      for (int i = 1; i <= n; i++) cout << i << " ";
      cout << endl;
    } else {
      for (int i = 0; i < n; i++) {
        for (int j = 2; (j * j) <= (sum - v[i]); j++) {
          if ((sum - v[i]) % j == 0) {
            cout << n - 1 << endl;
            for (int k = 1; k <= n; k++) {
              if (k == i + 1) continue;
              cout << k << " ";
            }
            cout << endl;
            goto mk;
          }
        }
      }
    }
  mk:;
  }
  return 0;
}
