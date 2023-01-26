#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long T, n;
  cin >> T;
  while (T--) {
    cin >> n;
    long long m = 1;
    for (long long i = 3; i <= 2 * n; i++) m = m * i % 1000000007;
    cout << m << endl;
  }
}
