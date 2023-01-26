#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n, i, maxi = 0, k;
    cin >> n;
    long long int a[n];
    for (i = 0; i < n; ++i) {
      cin >> a[i];
    }
    for (i = 0; i < n - 1; ++i) {
      if (a[i] * a[i + 1] > maxi) {
        maxi = a[i] * a[i + 1];
      }
    }
    cout << maxi << "\n";
  }
  return 0;
}
