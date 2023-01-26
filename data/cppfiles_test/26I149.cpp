#include <bits/stdc++.h>
using namespace std;
long long t;
long long n;
const long long mod = 1e9 + 7;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    long long res = 1;
    for (long long i = 1; i <= n * 2; i++) {
      res = ((res) * (i)) % mod;
    }
    cout << ((res % mod) / 2) << endl;
  }
}
