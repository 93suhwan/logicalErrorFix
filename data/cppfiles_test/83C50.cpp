#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int Mod = 1000000007;
const int maxN = 5e3 + 2;
int tt, n;
string s;
int nxt[maxN][maxN];
ll dp[maxN];
void Init() {
  cin >> tt;
  while (tt--) {
    cin >> n >> s;
    s += "A";
    for (int i = n; i >= 0; --i) {
      for (int j = i - 1; j >= 0; --j) {
        if (s[i] == s[j]) {
          nxt[j][i] = nxt[j + 1][i + 1] + 1;
        } else
          nxt[j][i] = 0;
      }
    }
    for (int i = 0; i < n; ++i) {
      dp[i] = ((dp[i] > n - i) ? dp[i] : n - i);
      for (int j = 0; j < i; ++j) {
        if (s[i + nxt[j][i]] > s[j + nxt[j][i]])
          dp[i] =
              ((dp[i] > dp[j] + n - nxt[j][i] - i) ? dp[i]
                                                   : dp[j] + n - nxt[j][i] - i);
      }
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
      ans = ((ans > dp[i]) ? ans : dp[i]);
      dp[i] = 0;
    }
    cout << ans << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  Init();
}
