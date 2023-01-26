#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> v[i];
    }
    int m = n;
    while (m >= 1) {
      for (int i = 1; i <= n; i++) {
        int j = 1;
        while (true) {
          long long sum = v[i], z = 1;
          for (int k = i + j; k <= n; k++) {
            sum += v[k];
            z++;
            if (z == m) break;
          }
          if (z != m) break;
          bool ans = 0;
          for (int k = 2; (k * k) <= sum; k++) {
            if (sum % k == 0) {
              ans = 1;
              break;
            }
          }
          if (ans) {
            cout << m << endl;
            cout << i << " ";
            for (int l = 1; l < m; l++) cout << i + (j++) << " ";
            cout << endl;
            goto mk;
          }
          j++;
        }
      }
      m--;
    }
  mk:;
  }
  return 0;
}
