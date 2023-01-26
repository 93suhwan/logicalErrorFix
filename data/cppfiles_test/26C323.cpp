#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long n, k;
int T;
int main() {
  cin >> T;
  while (T--) {
    cin >> n;
    long long ans = 1;
    for (long long i = 2; i <= n * 2 - 1; i++) {
      ans = (ans * i) % mod;
    }
    ans = (ans * n) % mod;
    cout << ans << endl;
  }
}
