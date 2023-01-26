#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
long long i, j;
void solve() {
  long long n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  vector<string> model = {"abc", "acb", "bac", "bca", "cab", "cba"};
  long long cnt[6][n + 1];
  for (i = 0; i < 6; i++) cnt[i][0] = 0;
  for (i = 0; i < n + 1; i++) {
    for (j = 0; j < 6; j++) {
      long long prev = i > 0 ? cnt[j][i - 1] : 0;
      cnt[j][i] = prev + (s[i] != model[j][i % 3]);
    }
  }
  while (m--) {
    long long x, y;
    cin >> x >> y;
    --x;
    --y;
    long long ans = INT_MAX;
    for (i = 0; i < 6; i++) {
      long long prev = x > 0 ? cnt[i][x - 1] : 0;
      ans = min(ans, (cnt[i][y] - prev));
    }
    cout << ans << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  return 0;
}
