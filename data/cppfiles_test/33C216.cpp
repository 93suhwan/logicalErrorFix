#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    long long res = INT_MIN;
    cin >> a[0];
    for (int i = 1; i < n; i++) {
      cin >> a[i];
      res = max((long long)a[i] * a[i - 1], res);
    }
    cout << res << "\n";
  }
}
