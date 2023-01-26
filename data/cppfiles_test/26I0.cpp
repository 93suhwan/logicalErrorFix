#include <bits/stdc++.h>
using namespace std;
int t;
long long n;
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    long long res = 1;
    for (int i = 1; i <= 2 * n; i++) {
      res *= i;
      res = res % (long long)(1e9 + 7);
    }
    cout << res / 2 << endl;
  }
}
