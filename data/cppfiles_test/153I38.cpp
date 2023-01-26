#include <bits/stdc++.h>
using namespace std;
long long lowbit(long long n) { return n & (-n); }
long long n;
vector<vector<long long>> hist;
vector<vector<long long>> cc;
vector<long long> dp;
long long count_place(long long num) {
  if (num % 2 == 1) return 0;
  return count_place(num / 2) + 1;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  vector<string> strs(n);
  hist = vector<vector<long long>>(n, vector<long long>(26));
  for (long long i = 0; i < n; i++) cin >> strs[i];
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < strs[i].size(); j++) hist[i][strs[i][j] - 'a']++;
  }
  long long maxS = (1 << n);
  cc = vector<vector<long long>>(maxS, vector<long long>(26, 0));
  for (long long s = 1; s < maxS; s++) {
    long long j = count_place(lowbit(s));
    long long ps = s - lowbit(s);
    for (long long i = 0; i < 26; i++) cc[s][i] = max(hist[j][i], cc[ps][i]);
  }
  dp = vector<long long>(maxS, 0);
  dp[0] = 1;
  for (long long s = 1; s < maxS; s++) {
    long long j = count_place(lowbit(s));
    long long ps = s - lowbit(s);
    long long cur = 1, prev = 1;
    for (long long i = 0; i < 26; i++) {
      if (hist[j][i] > cc[ps][i]) {
        prev *= cc[ps][i] + 1;
        cur *= hist[j][i] + 1;
        prev %= 998244353;
        cur %= 998244353;
      } else {
        prev *= hist[j][i] + 1;
        cur *= hist[j][i] + 1;
        prev %= 998244353;
        cur %= 998244353;
      }
    }
    long long incre = (cur - prev + 998244353) % 998244353;
    dp[s] = (dp[ps] + incre) % 998244353;
  }
  dp[0] = 0;
  long long total = 0;
  long long ans = 0;
  for (long long s = 0; s < maxS; s++) {
    long long addition = 0;
    long long count = 0;
    for (int i = 0; i < n; i++) {
      if ((1 << i) & s) {
        addition += i + 1;
        count++;
      }
    }
    long long ca = (dp[s] % 998244353) * addition * count;
    ans ^= ca;
  }
  cout << ans << endl;
}
