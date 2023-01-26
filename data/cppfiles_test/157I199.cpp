#include <bits/stdc++.h>
using namespace std;
template <typename T>
T gcd(T a, T b) {
  if (a % b) return gcd(b, a % b);
  return b;
}
template <typename T>
T lcm(T a, T b) {
  return (a * (b / gcd(a, b)));
}
vector<string> tokenizer(string str, char ch) {
  std::istringstream var((str));
  vector<string> v;
  string t;
  while (getline((var), t, (ch))) {
    v.push_back(t);
  }
  return v;
}
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cout << *it << " = " << a << "\n";
  err(++it, args...);
}
void file_i_o() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
long long solve(string s, long long k) {
  if (!k) return 1;
  long long n = s.length();
  vector<long long> dp(n + 1), lenofsubstr(n);
  dp[0] = 1;
  long long cnt = 0, si = 0;
  for (long long i = 0; i < n; i++) {
    if (s[i] == '1') cnt++;
    if (cnt < k)
      lenofsubstr[i] = -1;
    else {
      while (cnt > k) {
        if (s[si] == '1') cnt--;
        si++;
      }
      lenofsubstr[i] = i - si + 1;
    }
  }
  vector<vector<long long> > comb(5001, vector<long long>(5001, 1));
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= i; j++) {
      if (i == j) continue;
      comb[i][j] =
          (comb[i - 1][j - 1] % 998244353 + comb[i - 1][j] % 998244353) %
          998244353;
    }
  }
  for (long long i = 0; i < n; i++) {
    if (lenofsubstr[i] == -1)
      dp[i + 1] = 1;
    else {
      dp[i + 1] = dp[i];
      if (s[i] == '1' && lenofsubstr[i] != i + 1)
        dp[i + 1] += comb[lenofsubstr[i] - 1][k];
      else if (s[i] == '0')
        dp[i + 1] += comb[lenofsubstr[i] - 1][k - 1];
      dp[i + 1] %= 998244353;
    }
  }
  return dp[n];
}
int32_t main() {
  clock_t begin = clock();
  file_i_o();
  long long n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  cout << solve(s, k) << "\n";
  return 0;
}
