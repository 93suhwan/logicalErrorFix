#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n], max = -1;
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] > max) max = a[i];
    }
    long long c = 0, k = a[n - 1];
    if (k == max) {
      cout << c << "\n";
      return 0;
    }
    for (long long i = n - 2; i >= 0; i--) {
      if (a[i] > k) {
        k = a[i];
        c++;
      }
    }
    cout << c << "\n";
  }
  return 0;
}
