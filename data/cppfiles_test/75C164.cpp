#include <bits/stdc++.h>
using namespace std;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
long long gcd(long long a, long long b) {
  for (; b; a %= b, swap(a, b))
    ;
  return a;
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<pair<int, int> > v;
    for (int i = 0; i < n; i++) {
      int m;
      cin >> m;
      int sub = -1, mx = 0;
      for (int j = 0; j < m; j++) {
        int x;
        cin >> x;
        x -= sub;
        mx = max(mx, x);
        sub++;
      }
      v.push_back({mx, m});
    }
    sort(v.begin(), v.end());
    int ans = v[0].first;
    int res = ans + v[0].second;
    for (int i = 1; i < n; i++) {
      if (res < v[i].first) {
        ans += v[i].first - res;
        res = v[i].first;
      }
      res += v[i].second;
    }
    cout << ans << "\n";
  }
}
