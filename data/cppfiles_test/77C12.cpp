#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e6 + 100;
int n, m;
int dp[maxn];
int dif[maxn];
void solve() {
  cin >> n >> m;
  dif[1] = 1;
  dif[2] = -1;
  int now = 0;
  for (int i = 1; i <= n; i++) {
    now = (now + dif[i]) % m;
    dp[i] = now;
    ;
    if (i + 1 <= n) dif[i + 1] = (dif[i + 1] + now) % m;
    for (int j = 2 * i; j <= n; j += i) {
      int l = j;
      int r = j + j / i;
      ;
      if (l <= n) dif[l] = (dif[l] + dp[i]) % m;
      if (r <= n) dif[r] = (dif[r] - dp[i] + m) % m;
    }
  }
  cout << dp[n] << '\n';
}
int main() { solve(); }
