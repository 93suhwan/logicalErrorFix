#include <bits/stdc++.h>
using namespace std;
unsigned long long t = 1, w, h, n, l, r, mid;
bool ok;
int dp[67], pd[67];
string s;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> s;
    ok = false;
    for (int i = 0; i < n; ++i) {
      dp[i + 1] = dp[i];
      pd[i + 1] = pd[i];
      if (s[i] == 'a')
        dp[i + 1]++;
      else
        pd[i + 1]++;
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = i + 1; j <= n; ++j) {
        if (dp[j] - dp[i - 1] == pd[j] - pd[i - 1]) {
          cout << i << " " << j << "\n";
          ok = true;
          break;
        }
      }
      if (ok) break;
    }
    if (!ok) cout << "-1 -1\n";
  }
}
