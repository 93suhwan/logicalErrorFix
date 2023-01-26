#include <bits/stdc++.h>
using namespace std;
struct compare {
  bool operator()(const pair<long long, long long> &a,
                  const pair<long long, long long> &b) {
    return a.first > b.first;
  }
};
bool comp(const pair<long long, long long> &a,
          const pair<long long, long long> &b) {
  if (a.first == b.first) {
    return a.second < b.second;
  }
  return a.first < b.first;
}
bool compp(const pair<long long, long long> &a,
           const pair<long long, long long> &b) {
  if (a.first == b.first) {
    return a.second > b.second;
  }
  return a.first < b.first;
}
long long gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
long long mod_power(long long a, long long b) {
  if (b == 0) {
    return 1;
  }
  long long temp = mod_power(a, b / 2);
  temp %= 998244353;
  temp *= temp;
  temp %= 998244353;
  if (b % 2 == 1) {
    temp *= a;
    temp %= 998244353;
  }
  return temp;
}
bool ispal(string s) {
  long long fst = 0;
  long long lst = s.length() - 1;
  while (fst < lst) {
    if (s[fst] == s[lst]) {
      fst++;
      lst--;
    } else {
      return false;
    }
  }
  return true;
}
long long check(long long ans, vector<long long> &v) {
  long long n = v.size();
  n--;
  long long tot = 0;
  for (long long i = n; i >= 0; i--) {
    tot += ans / v[i];
    ans %= v[i];
  }
  return tot;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  vector<vector<long long> > p(501, vector<long long>(501, 0));
  vector<vector<long long> > ncr(501, vector<long long>(501, 0));
  ncr[0][0] = 1;
  for (long long i = 1; i <= 500; i++) {
    p[i][0] = 1;
    ncr[i][0] = 1;
    for (long long j = 1; j <= 500; j++) {
      p[i][j] = (p[i][j - 1] * i) % 998244353;
      ncr[i][j] = (ncr[i - 1][j] + ncr[i - 1][j - 1]) % 998244353;
    }
  }
  vector<vector<long long> > dp(501, vector<long long>(501, 0));
  for (long long i = 0; i <= 500; i++) {
    dp[0][i] = 1;
  }
  while (t--) {
    long long n, k;
    cin >> n >> k;
    for (long long i = 2; i <= n; i++) {
      for (long long j = 1; j < i; j++) {
        dp[i][j] = p[j][i];
      }
      for (long long j = i; j <= k; j++) {
        for (long long itr = 0; itr <= i; itr++) {
          dp[i][j] += ((((dp[i - itr][j - i + 1] * p[i - 1][itr]) % 998244353) *
                        ncr[i][itr]) %
                       998244353) %
                      998244353;
          dp[i][j] %= 998244353;
        }
      }
    }
    cout << dp[n][k] << "\n";
  }
  return 0;
}
