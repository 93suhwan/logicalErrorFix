#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long maxn = 5001;
vector<long long> fact(maxn, 1);
long long mod = 998244353;
void calFact() {
  for (long long i = 2; i < maxn; i++) fact[i] = (i * fact[i - 1]) % mod;
}
long long ncr(long long n, long long r) {
  long long ans = fact[n];
  ans /= fact[r];
  ans /= fact[n - r];
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  calFact();
  long long n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<long long> dp(n, 0);
  dp[0] = 1;
  bool first = false;
  for (long long i = 1; i < n; i++) {
    long long ones = 0, zeroes = 0;
    dp[i] = dp[i - 1];
    for (long long j = i; j >= 0; j--) {
      if (s[j] == '1') {
        if (ones == k) break;
        ones++;
      } else
        zeroes++;
    }
    if (ones < k) continue;
    long long temp;
    if (first == false) {
      temp = ncr(zeroes + ones, zeroes) - 1;
    } else {
      if (s[i] == '1') {
        temp = 0;
        if (zeroes > 0) {
          temp = ncr(zeroes + ones - 1, zeroes - 1);
        }
      } else {
        temp = 0;
        if (ones > 0) {
          temp = ncr(zeroes + ones - 1, zeroes);
        }
      }
    }
    first = true;
    dp[i] = (dp[i] + temp) % mod;
  }
  cout << dp[n - 1] << "\n";
}
