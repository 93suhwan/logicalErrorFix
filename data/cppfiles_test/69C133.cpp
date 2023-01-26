#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const long long N = 200000 + 5;
const long long mod = 1e9 + 7;
long long func(long long n1, long long n2) {
  string s1 = to_string(n1);
  string s2 = to_string(n2);
  long long len1 = s1.length();
  long long len2 = s2.length();
  long long dp[len1 + 1][len2 + 1];
  memset(dp, 0, sizeof(dp));
  long long i, j, k, l;
  i = 0;
  j = 0;
  long long cnt = 0;
  while (i < len1 && j < len2) {
    if (s1[i] == s2[j]) {
      i++;
      j++;
      cnt++;
    } else {
      j++;
    }
  }
  long long ans = 0;
  ans += len2 - cnt;
  ans += len1 - i;
  return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long T;
  cin >> T;
  while (T--) {
    long long n;
    cin >> n;
    long long num = 1;
    long long ans = INF;
    long long temp = (1ll << 31);
    while (num <= INF) {
      long long op = func(num, n);
      ans = min(ans, op);
      num *= 2;
    }
    cout << ans << "\n";
  }
}
