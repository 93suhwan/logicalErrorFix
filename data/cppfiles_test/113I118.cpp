#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long long> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  long long sum = accumulate(v.begin(), v.end(), 0);
  int q;
  cin >> q;
  while (q--) {
    long long x, y;
    cin >> x >> y;
    int idx = lower_bound(v.begin(), v.end(), x) - v.begin();
    int idxx = upper_bound(v.begin(), v.end(), x) - v.begin();
    if (idxx == n) {
      idxx--;
    }
    if (idx == n) {
      idx--;
    }
    long long ans = LLONG_MAX;
    long long tt = 0;
    tt += (x - v[idx] > 0 ? x - v[idx] : 0);
    tt += (sum - v[idx] < y ? y - sum + v[idx] : 0);
    ans = min(ans, tt);
    tt = 0;
    tt += (x - v[idx - 1] > 0 ? x - v[idx - 1] : 0);
    tt += (sum - v[idx - 1] < y ? y - sum + v[idx - 1] : 0);
    ans = min(ans, tt);
    tt = 0;
    tt += (x - v[idxx] > 0 ? x - v[idxx] : 0);
    tt += (sum - v[idxx] < y ? y - sum + v[idxx] : 0);
    ans = min(ans, tt);
    tt = 0;
    tt += (x - v[idxx - 1] > 0 ? x - v[idxx - 1] : 0);
    tt += (sum - v[idxx - 1] < y ? y - sum + v[idxx - 1] : 0);
    ans = min(ans, tt);
    tt = 0;
    cout << ans << "\n";
  }
  return 0;
}
