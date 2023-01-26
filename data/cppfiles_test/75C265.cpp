#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long i, j, n, maxx = -1;
    cin >> n;
    vector<pair<long long, long long>> v(n);
    for (i = 0; i < n; i++) {
      long long k, mm = 0;
      cin >> k;
      v[i].second = k;
      for (j = 0; j < k; j++) {
        int a;
        cin >> a;
        mm = max(mm, a - j + 1);
      }
      v[i].first = mm;
    }
    sort(v.begin(), v.end());
    long long ans = 0, pv = 0;
    for (i = 0; i < n; i++) {
      ans = max(ans, v[i].first - pv);
      pv += v[i].second;
    }
    cout << ans << endl;
  }
  return 0;
}
