#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2e6 + 5;
const long long mod = 1e9 + 7;
int main() {
  int t;
  cin >> t;
  long long n, k;
  while (t--) {
    cin >> n >> k;
    long long sum = 0, temp = 1;
    while (k) {
      if (k % 2 == 1) {
        sum += temp;
        sum %= mod;
      }
      temp *= n;
      temp %= mod;
      k /= 2;
    }
    cout << sum << endl;
  }
  return 0;
}
