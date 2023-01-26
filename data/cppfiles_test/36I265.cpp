#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long half = n / 2;
    for (long long i = 1; i <= half; i++) {
      cout << "a";
    }
    long long temp;
    if (n & 1) {
      cout << "bc";
      temp = 2;
    } else {
      cout << "b";
      temp = 1;
    }
    for (long long i = half + 1 + temp; i <= n; i++) {
      cout << "a";
    }
    cout << endl;
  }
}
