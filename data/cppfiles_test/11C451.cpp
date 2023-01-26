#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2 * 1000 * 100 + 10;
int n;
string words[MAXN];
int cnt[5][MAXN];
void solve() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> words[i];
    for (int j = 0; j < 5; ++j) {
      int tmp = count(words[i].begin(), words[i].end(), char(int('a') + j));
      cnt[j][i] = words[i].size() - (2 * tmp);
    }
  }
  int ans = 0;
  for (int i = 0; i < 5; ++i) {
    sort(cnt[i], cnt[i] + n);
    int total = 0;
    for (int j = 0; j < n; ++j) {
      total += cnt[i][j];
      if (total >= 0) break;
      ans = max(ans, j + 1);
    }
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
