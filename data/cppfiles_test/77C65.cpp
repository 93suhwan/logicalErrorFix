#include <bits/stdc++.h>
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
using namespace std;
const long long int N = 4e6 + 20, mod = 1e9 + 7, inf = 1e9;
vector<int> tajz[N];
int dp[N];
int main() {
  ios ::sync_with_stdio(0);
  cin.tie(0);
  int T = 1;
  while (T--) {
    int n, m;
    cin >> n >> m;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 2; 2 * i <= n; i++) dp[2 * i]++;
    for (int i = 3; i < n + 1; i++) {
      dp[i] += (2 * dp[i - 1] + 1) % m;
      dp[i] %= m;
      for (int j = 2; j * i <= n; j++) {
        dp[j * i] = (dp[j * i] + (-dp[i - 1] + dp[i] + m) % m) % m;
      }
    }
    cout << dp[n];
  }
}
