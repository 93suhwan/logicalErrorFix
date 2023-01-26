#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n];
    long long max = -1;
    long long index;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] > max) {
        max = a[i];
        index = i;
      }
    }
    long long maxvalue = 10000000000;
    for (long long l = 0; l < n; l++) {
      for (long long r = l; r < n; r++) {
        if (r + l - index < n && r + l - index >= 0) {
          for (long long i = 0; i <= r - l; i++) {
            a[l + i] = a[l + i] & a[r - i];
          }
          maxvalue = min(maxvalue, a[index] & a[r + l - index]);
        }
      }
    }
    cout << maxvalue << endl;
  }
}
