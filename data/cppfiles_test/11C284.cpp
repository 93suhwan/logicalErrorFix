#include <bits/stdc++.h>
using namespace std;
const int mxn = (int)2e5 + 5;
void solve() {
  int n;
  cin >> n;
  vector<array<int, 6>> a(n);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (auto x : s) a[i][x - 'a']++;
    a[i][5] = s.length();
    if (0) {
      cerr << i << ": ";
      for (auto x : a[i]) cerr << x << " ";
      cerr << "\n";
    }
  }
  if (0) cerr << "done\n";
  int ans = 0;
  for (int i = 0; i < 5; i++) {
    vector<int> need;
    for (int j = 0; j < n; j++) need.push_back(2 * a[j][i] - a[j][5]);
    sort(need.begin(), need.end());
    reverse(need.begin(), need.end());
    int cnt = 0;
    int res = 0;
    do {
      if (cnt == n) break;
      res += need[cnt++];
    } while (res > 0);
    if (res <= 0) cnt--;
    ans = max(ans, cnt);
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
