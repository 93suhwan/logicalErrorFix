#include <bits/stdc++.h>
#pragma warning(disable : 4996)
#pragma comment(linker, "/STACK:16777216")
using namespace std;
const int INF = 1000000000 + 1e8;
const long long LINF = 2000000000000000000;
const int N = 1e5 + 10;
int add(int a, int b, int mod) { return a + b > mod ? a + b - mod : a + b; }
void solve() {
  int n, mod;
  cin >> n >> mod;
  vector<int> dp(n + 1, 0);
  dp[n] = 1;
  vector<int> suff(n + 1);
  suff[n] = 1;
  for (int i = n - 1; i >= 1; i--) {
    for (int j = 2; j <= n / i; j++) {
      int l = i * j;
      int r = i * j + j - 1;
      int val = add(suff[l], mod - (r + 1 > n ? 0 : suff[r + 1]), mod);
      dp[i] = add(dp[i], val, mod);
    }
    dp[i] = add(dp[i], suff[i + 1], mod);
    suff[i] = add(dp[i], suff[i + 1], mod);
  }
  cout << dp[1] << '\n';
}
signed main() {
  srand(time(0));
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tst = 1;
  while (tst--) {
    solve();
  }
}
