#include <bits/stdc++.h>
using namespace std;
long long infi = 1e18 + 10;
long long MOD = 1e9 + 7;
const long long N = 1e6 + 10;
const long long M = 998244353;
long long dx[] = {1, 0, -1, 0};
long long dy[] = {0, 1, 0, -1};
void init_code() {}
long long binexp(long long a, long long b, long long p) {
  a %= p;
  long long ans = 1;
  while (b > 0) {
    if (b & 1) ans = (ans * a) % p;
    a = (a * a) % p;
    b >>= 1;
  }
  return ans;
}
long long mod_inverse(long long n, long long p) { return binexp(n, p - 2, p); }
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    vector<long long> v(7);
    bool found = false;
    for (long long i = 0; i < 7; i++) cin >> v[i];
    for (long long i = 0; i < 7; i++) {
      for (long long j = i + 1; j < 7; j++) {
        for (long long k = j + 1; k < 7; k++) {
          if (v[i] + v[j] + v[k] == v[6]) {
            if (!found) {
              found = true;
              cout << v[i] << " " << v[j] << " " << v[k] << "\n";
            }
          }
        }
      }
    }
  }
}
