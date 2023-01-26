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
    long long l = 0;
    long long r = n - 1;
    long long maxvalue = a[l] & a[r];
    while (l <= index) {
      while (r >= index) {
        if (l + index < n && r - index >= 0) {
          maxvalue = min(maxvalue, a[l + index] & a[r - index]);
        }
        r--;
      }
      l++;
    }
    cout << maxvalue << endl;
  }
}
