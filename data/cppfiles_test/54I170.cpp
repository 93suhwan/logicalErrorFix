#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void c_p_c() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
long long int n, k;
long long int fact[200003];
long long int inv[200003];
long long int findInverse(long long int x) {
  long long int pow = 1000000007 - 2;
  long long int ans = 1;
  while (pow) {
    if (pow & 1) ans = (ans * x) % 1000000007;
    pow = pow >> 1;
    x = (x * x) % 1000000007;
  }
  return ans;
}
long long int pw(long long int x, long long int y) {
  long long int ans = 1;
  while (y) {
    if (y & 1) {
      ans = (ans * x) % 1000000007;
    }
    y = y >> 1;
    x = (x * x) % 1000000007;
  }
  return ans;
}
int32_t main() {
  c_p_c();
  fact[0] = 1;
  for (long long int i = 1; i < 200003; i++) {
    fact[i] = (fact[i - 1] * i) % 1000000007;
  }
  inv[200002] = findInverse(fact[200002]);
  for (long long int i = 200001; i > -0; i--) {
    inv[i] = (inv[i + 1] * (i + 1)) % 1000000007;
  }
  inv[0] = inv[1];
  long long int t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    bool isEven = (n % 2 == 0) ? 1 : 0;
    long long int states = 0LL;
    long long int tot = 0;
    for (long long int i = 0; i < n; i++) {
      if (i % 2 == 0) {
        states = (states + (((fact[n] * inv[n - i]) % 1000000007) * (inv[i])) %
                               1000000007) %
                 1000000007;
      }
      tot = (tot +
             (((fact[n] * inv[n - i]) % 1000000007) * (inv[i])) % 1000000007) %
            1000000007;
    }
    long long int currState = 1LL;
    long long int ans = 0;
    for (long long int i = 0; i < k; i++) {
      if (isEven) {
        ans =
            (ans + (currState * pw(tot, k - i - 1)) % 1000000007) % 1000000007;
      }
      currState = (currState * ((!isEven + states) % 1000000007)) % 1000000007;
    }
    ans = (ans + currState) % 1000000007;
    cout << ans << "\n";
  }
  return 0;
}
