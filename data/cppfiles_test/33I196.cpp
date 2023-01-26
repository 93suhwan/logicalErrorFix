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
      if (a[i] > maxi) {
        maxi = a[i];
        k = i;
      }
    }
    if (k == 0)
      cout << maxi * a[k + 1] << "\n";
    else if (k == n - 1)
      cout << maxi * a[k - 1] << "\n";
    else {
      if (a[k - 1] > a[k + 1])
        cout << maxi * a[k - 1] << "\n";
      else
        cout << maxi * a[k + 1] << "\n";
    }
  }
  return 0;
}
