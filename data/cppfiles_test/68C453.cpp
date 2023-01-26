#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long k = sqrt(n);
    if (k * k == n)
      cout << k << " " << 1 << endl;
    else {
      long long upper = k + 1;
      long long left = k;
      long long rem = n - k * k;
      if (rem <= upper) {
        cout << rem << " " << k + 1 << endl;
      } else {
        int q = rem - upper;
        cout << k + 1 << " " << (k + 1) - q << endl;
      }
    }
  }
  return 0;
}
