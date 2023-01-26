#include <bits/stdc++.h>
using namespace std;
long long int recpow(long long int base, long long int exp) {
  long long int result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((long long int)result * base) % 1000000007;
    base =
        ((long long int)(base % 1000000007) * (base % 1000000007)) % 1000000007;
    exp >>= 1;
  }
  return (result % 1000000007);
}
bool comp(const pair<long long int, long long int>& a,
          const pair<long long int, long long int>& b) {
  return ((a.first == b.first and a.second > b.second) or a.first < b.first);
}
bool chk(long long int p, vector<pair<long long int, long long int>>& v) {
  int n = v.size();
  long long int i = 0;
  while (i < n) {
    if (p < v[i].first) return 0;
    p += v[i].second;
    i++;
  }
  return 1;
}
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int tc = 1;
  while (tc--) {
    long long int n, m;
    cin >> n >> m;
    vector<long long int> dp(n + 1, 0), pref(n + 1, 0);
    dp[1] = 1, pref[1] = 1;
    for (long long int i = 2; i < n + 1; i++) {
      dp[i] = (dp[i] + pref[i - 1]) % m;
      for (long long int j = 1; j * j <= i; ++j) {
        long long int tmp = i / j - i / (j + 1);
        dp[i] = (dp[i] + (tmp * dp[j]) % m) % m;
      }
      for (long long int j = 2; j * j <= i; ++j) {
        long long int tmp = i / j;
        if (tmp * tmp > i) {
          dp[i] = (dp[i] + dp[tmp]) % m;
        }
      }
      pref[i] = (pref[i - 1] + dp[i]) % m;
    }
    cout << dp[n] << "\n";
  }
  return 0;
}
