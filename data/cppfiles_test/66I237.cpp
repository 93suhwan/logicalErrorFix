#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    long long k;
    cin >> k;
    long long n = ceil(sqrt(k));
    long long r = 0, c = 0;
    if (n * n - k >= n) {
      r = n - (n * n - k - n) - 1;
      c = n;
    } else {
      r = n;
      c = n * n - k + 1;
    }
    cout << r << ' ' << c << endl;
  }
  return 0;
}
