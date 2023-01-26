#include <bits/stdc++.h>
using namespace std;
long long infi = 1e18 + 10;
long long MOD = 1e9 + 7;
const long long N = 1e5 + 10;
const long long M = 998244353;
long long dx[] = {1, 0, -1, 0};
long long dy[] = {0, 1, 0, -1};
vector<long long> dp(N);
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
    long long a, b;
    cin >> a >> b;
    long long ans = 0;
    for (long long x = 1; x <= 2; x++) {
      long long k;
      cin >> k;
      vector<long long> v(k);
      for (long long i = 0; i < k; i++) {
        cin >> v[i];
      }
      long long curr_ans = (v[k - 1] - v[0]) * b;
      ans = max(ans, curr_ans);
    }
    for (long long x = 1; x <= 2; x++) {
      long long k;
      cin >> k;
      vector<long long> v(k);
      for (long long i = 0; i < k; i++) {
        cin >> v[i];
      }
      long long curr_ans = (v[k - 1] - v[0]) * a;
      ans = max(ans, curr_ans);
    }
    cout << ans << "\n";
  }
}
