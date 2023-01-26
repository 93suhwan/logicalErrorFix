#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int M = 2e5 + 5;
vector<int> dvs[M];
void seive() {
  for (int i = 2; i < M; i++) {
    for (int j = i; j < M; j += i) {
      dvs[j].push_back(i);
    }
  }
}
long long dp[M];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, mod;
  cin >> n >> mod;
  dp[1] = 1;
  long long sum = 1;
  for (long long i = 2; i <= n; i++) {
    long long sq = sqrt(i);
    for (long long j = 1; j <= sq; j++) {
      dp[i] += dp[i / j];
      if (j == sq) {
        if ((i / j) == j) {
        } else {
          dp[i] += ((i / j) - (i / (j + 1))) * dp[j];
        }
      } else {
        dp[i] += ((i / j) - (i / (j + 1))) * dp[j];
      }
      dp[i] %= mod;
    }
    dp[i] += sum;
    sum += dp[i];
    sum %= mod;
  }
  cout << dp[n] << endl;
  return 0;
}
