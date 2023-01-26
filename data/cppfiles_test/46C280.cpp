#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    reverse(v.begin() + 1, v.end());
    int now = v[1];
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      if (v[i] <= now) {
        continue;
      } else {
        ans++;
        now = v[i];
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
