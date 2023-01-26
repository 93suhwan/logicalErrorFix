#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long res = 1;
    for (long long i = 3; i <= 2 * n; i++) {
      res = (res * i) % 1000000007;
    }
    cout << res << endl;
  }
  return 0;
}
