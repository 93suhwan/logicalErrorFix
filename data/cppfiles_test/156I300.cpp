#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long n, k, a, ans, y;
    cin >> n >> k;
    long long s[n + 10];
    vector<long long> v;
    for (int i = 0; i < n; i++) cin >> a, v.push_back(a);
    sort(v.begin(), v.end());
    s[0] = 0;
    for (int i = 1; i < n; i++) s[i] = s[i - 1] + v[i];
    s[n] = s[n - 1] + v[0];
    if (s[n] <= k) {
      cout << 0 << endl;
      continue;
    }
    ans = s[n] - k;
    for (int i = 1; i < n; i++) {
      y = v[0] * (n - i + 1) + s[i - 1] - k;
      if (y % (n - i + 1))
        y /= (n - i + 1), y++;
      else
        y /= (n - i + 1);
      ans = min(ans, y + (n - i));
    }
    cout << ans << endl;
  }
}
