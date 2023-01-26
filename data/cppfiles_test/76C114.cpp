#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long dp[N], sum[N], n, m;
void solve() {
  int temp, l, r;
  cin >> n >> m;
  dp[1] = sum[1] = 1;
  for (int i = 2; i <= n; i++) {
    for (int j = i; j >= 2;) {
      temp = i / j;
      r = j;
      l = i / (temp + 1) + 1;
      dp[i] = (dp[i] + (r - l + 1) * dp[temp]) % m;
      j = i / (temp + 1);
    }
    dp[i] = (dp[i] + sum[i - 1]) % m;
    sum[i] = (sum[i - 1] + dp[i]) % m;
  }
  cout << dp[n] << endl;
}
int main() { solve(); }
