#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
int n;
string s;
int f[N], lcp[N][N];
void solve() {
  cin >> n >> s;
  s = '#' + s;
  for (int i = 1; i <= n; ++i) lcp[n + 1][i] = 0;
  for (int i = n; i; --i) {
    for (int j = 1; j < i; ++j) {
      lcp[i][j] = 0;
      if (s[i] == s[j]) lcp[i][j] = lcp[i + 1][j + 1] + 1;
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    f[i] = n - i + 1;
    for (int j = 1; j < i; ++j) {
      int c = lcp[i][j];
      if (i + c <= n) {
        if (s[i + c] > s[j + c]) f[i] = max(f[i], f[j] + n - i - c + 1);
      }
    }
    ans = max(ans, f[i]);
  }
  cout << ans << '\n';
}
int main() {
  cin.tie(0)->sync_with_stdio(false);
  int test_case;
  cin >> test_case;
  while (test_case--) solve();
}
