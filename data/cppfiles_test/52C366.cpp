#include <bits/stdc++.h>
using namespace std;
void init_code() {}
int main() {
  init_code();
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long num = 1, res = 0;
    while (k) {
      if (k & 1) {
        res += num;
        res %= 1000000000 + 7;
      }
      k >>= 1;
      num *= n;
      num %= 1000000000 + 7;
    }
    cout << res << "\n";
  }
  return 0;
}
