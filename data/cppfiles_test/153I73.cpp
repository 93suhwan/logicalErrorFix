#include <bits/stdc++.h>
std::mt19937 rng(
    (unsigned int)std::chrono::steady_clock::now().time_since_epoch().count());
using namespace std;
void solve(int ttt) {
  int n;
  cin >> n;
  vector<vector<int> > freq(n, vector<int>(26, 0));
  for (long long int i = 0; i < n; i++) {
    string s;
    cin >> s;
    int sz = s.size();
    for (long long int j = 0; j < sz; j++) {
      freq[i][s[j] - 'a']++;
    }
  }
  vector<int> dp(1 << n, 1);
  dp[0] = 0;
  int dp2[1 << (23)];
  for (long long int i = 0; i < n; i++) {
    long long int res = 1;
    for (long long int j = 0; j < 26; j++) {
      long long int cnt = freq[i][j] + 1;
      res *= cnt;
      res %= 998244353;
    }
    dp[(1 << i)] = res;
  }
  for (int l = 0; l < 26; l++) {
    for (long long int i = 0; i < n; i++) {
      dp2[(1 << i)] = freq[i][l] + 1;
    }
    for (int i = 1; i < (1 << n); i++) {
      int tmp1 = i & (-i);
      int j = (i ^ (tmp1));
      if (j == 0) continue;
      int tmp2 = j & (-j);
      int k = (i ^ (tmp2));
      long long int res = min(dp2[j], dp2[k]);
      dp2[i] = res;
      dp[i] *= res;
      dp[i] %= 998244353;
    }
  }
  for (long long int i = 0; i < 1 << n; i++)
    if (!(__builtin_popcount(i) & 1)) dp[i] = (-dp[i] + 998244353) % 998244353;
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < (1 << n); j++) {
      if (j & (1 << i)) {
        int x = j ^ (1 << i);
        dp[j] += dp[x];
        dp[j] %= 998244353;
      }
    }
  }
  long long int res = 0;
  for (long long int i = 0; i < (1 << n); i++) {
    long long int k = 0;
    long long int indSum = 0;
    for (long long int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        indSum += (j + 1);
        k++;
      }
    }
    dp[i] %= 998244353;
    dp[i] += 998244353;
    dp[i] %= 998244353;
    long long int tmp = (long long int)dp[i] * k * indSum;
    res ^= tmp;
  }
  cout << res << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int ttt;
  ttt = 1;
  for (long long int i = 0; i < ttt; i++) solve(i);
}
