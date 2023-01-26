#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    n--;
    long long x = 1;
    long long count = 0;
    while (n > 0) {
      if (x >= k) {
        break;
      }
      n -= x;
      count++;
      x *= 2;
    }
    if (n < 0) {
      n = 0;
    }
    long long zz = n / k;
    if (n % k) {
      zz++;
    }
    cout << count + zz << '\n';
  }
}
