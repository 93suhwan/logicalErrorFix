#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long n, k, a, ans = 1e18 + 1, y;
    cin >> n >> k;
    long long s[n + 10];
    vector<long long> v;
    for (int i = 0; i < n; i++) cin >> a, v.push_back(a);
    sort(v.begin(), v.end());
    s[0] = 0;
    for (int i = 1; i < n; i++) s[i] = s[i - 1] + v[i];
    if (s[n - 1] + v[0] <= k) {
      cout << 0 << endl;
      continue;
    }
    for (int i = 1; i < n; i++) {
      y = v[0] * (n - i + 1) + s[i - 1] - k;
      if (y % (n - i + 1))
        y /= (n - i + 1), y++;
      else
        y /= (n - i + 1);
      ans = min(ans, y + (n - i));
    }
    y = k - s[n - 1];
    y = v[0] - y;
    ans = min(y, ans);
    cout << ans << endl;
  }
}
