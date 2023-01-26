#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long MOD2 = 998244353;
long long power(long long a, long long b) {
  long long res = 1;
  a = a % MOD;
  while (b > 0) {
    if (b & 1) {
      res = (res * a) % MOD;
    }
    a = (a * a) % MOD;
    b >>= 1;
  }
  return res;
}
long long fermat_inv(long long y) { return power(y, MOD - 2); }
long long gcd(long long a, long long b) { return (b == 0) ? a : gcd(b, a % b); }
void solveQuestion() {
  long long n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  if (a == b) {
    cout << "0\n";
    return;
  }
  long long cntA0 = count(a.begin(), a.end(), '0'),
            cntA1 = count(a.begin(), a.end(), '1');
  long long cntB0 = count(b.begin(), b.end(), '0'),
            cntB1 = count(b.begin(), b.end(), '1');
  if ((cntA0 == cntB0 && cntA1 == cntB1) &&
      (cntB1 == 1 + cntA0 && cntB0 == cntA1 - 1)) {
    long long ans1 = 0, ans2 = 0;
    for (long long i = 0; i < n; i++) {
      if (a[i] != b[i]) {
        ans1++;
      }
    }
    for (long long i = 0; i < n; i++) {
      if (a[i] == b[i]) {
        ans2++;
      }
    }
    cout << min(ans1, ans2) << "\n";
  } else if ((cntA0 == cntB0 && cntA1 == cntB1)) {
    long long ans = 0;
    for (long long i = 0; i < n; i++) {
      if (a[i] != b[i]) {
        ans++;
      }
    }
    cout << ans << "\n";
  } else if ((cntB1 == 1 + cntA0 && cntB0 == cntA1 - 1)) {
    long long ans = 0;
    for (long long i = 0; i < n; i++) {
      if (a[i] == b[i]) {
        ans++;
      }
    }
    cout << ans << "\n";
  } else {
    cout << "-1\n";
    return;
  }
}
int32_t main(int32_t argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long tt = 1;
  cin >> tt;
  while (tt-- > 0) {
    solveQuestion();
  }
  return 0;
}
