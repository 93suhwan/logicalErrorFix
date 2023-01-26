#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, maximum, maxmin = INT_MIN;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++) {
      for (int j = i + 1; j <= n; j++) {
        if (*min_element(a + i, a + j) > maxmin) {
          maxmin = *min_element(a + i, a + j);
        }
      }
    }
    maximum = *max_element(a, a + n);
    long int ans = maximum * maxmin;
    cout << ans << endl;
  }
}
