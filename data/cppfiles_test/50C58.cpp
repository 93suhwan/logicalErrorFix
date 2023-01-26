#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353, N = 500005;
long long a, b, c, d, e, f, g = 1, h[N], arr[N], dp[N][2], pre[N][2];
string s;
vector<long long> v;
void solve() {
  cin >> a;
  for (long long i = 1; i <= a; i++) {
    cin >> arr[i];
  }
  stack<long long> stc;
  dp[0][0] = pre[0][0] = 1;
  for (long long i = 1; i <= a; i++) {
    while (stc.size() and arr[stc.top()] >= arr[i]) stc.pop();
    dp[i][0] = (!stc.size()
                    ? (pre[i - 1][1] * arr[i]) % mod
                    : (dp[stc.top()][0] +
                       (pre[i - 1][1] - pre[stc.top() - 1][1] + mod) * arr[i]) %
                          mod);
    dp[i][1] = (!stc.size()
                    ? (pre[i - 1][0] * arr[i]) % mod
                    : (dp[stc.top()][1] +
                       (pre[i - 1][0] - pre[stc.top() - 1][0] + mod) * arr[i]) %
                          mod);
    pre[i][0] = (dp[i][0] + pre[i - 1][0]) % mod;
    pre[i][1] = (dp[i][1] + pre[i - 1][1]) % mod;
    stc.push(i);
  }
  cout << (a % 2 ? (dp[a][1] - dp[a][0] + mod) % mod
                 : (dp[a][0] - dp[a][1] + mod) % mod)
       << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  while (g--) solve();
}
