#include <bits/stdc++.h>
using namespace std;
long long fact[5003], ifact[5003];
long long mod = 998244353;
long long powwwer(long long i, long long j) {
  if (j == 0) return 1;
  long long w = powwwer(i, j / 2);
  w = (w * w) % mod;
  if (j % 2 == 1) {
    w = (w * i) % mod;
  }
  return w;
}
int main() {
  fact[0] = 1;
  ifact[0] = powwwer(fact[0], mod - 2);
  for (int i = 1; i <= 5001; i++) {
    fact[i] = (fact[i - 1] * 1LL * i) % mod;
    ifact[i] = powwwer(fact[i], mod - 2);
  }
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int cnt = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '1') cnt++;
  }
  if (cnt < k) {
    cout << 1 << endl;
    return 0;
  }
  long long ans = 1;
  for (int i = 0; i < s.size(); i++) {
    int cnt1 = 0;
    int cnt0 = 0;
    int j = i;
    while (j >= 0 && cnt1 <= k) {
      if (s[j] == '1')
        cnt1++;
      else
        cnt0++;
      j--;
    }
    if (cnt1 > k) cnt1--;
    if (s[i] == '1') {
      if (cnt0 > 0) {
        long long z = (fact[cnt1 + cnt0 - 1] * ifact[cnt0 - 1]) % mod;
        z = (z * ifact[cnt1]) % mod;
        ans = (ans + z) % mod;
      }
    } else {
      if (cnt1 > 0) {
        long long z = (fact[cnt1 + cnt0 - 1] * ifact[cnt1 - 1]) % mod;
        z = (z * ifact[cnt0]) % mod;
        ans = (ans + z) % mod;
      }
    }
  }
  cout << ans << endl;
}
