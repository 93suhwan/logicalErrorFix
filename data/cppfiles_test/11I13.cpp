#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ii = pair<int, int>;
using vii = vector<ii>;
using vvii = vector<vii>;
const int MOD = 1000000007;
const int MX = 100001;
int main() {
  int n;
  cin >> n;
  vii v(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    v[i] = ii(x, i + 1 - x);
  }
  sort(v.begin(), v.end());
  vi vv;
  int l = 0;
  for (int i = 0; i < n; i++) {
    if (v[i].first != l && v[i].second >= 0) {
      vv.push_back(v[i].second);
      l = v[i].first;
    }
  }
  int sz = (int)vv.size();
  if (sz > 0) {
    vi s(sz, 0);
    s[0] = vv[0];
    int ans = 1;
    for (int i = 1; i < sz; i++) {
      auto b = s.begin(), e = s.begin() + ans;
      auto it = upper_bound(b, e, vv[i]);
      if (it == s.begin() + ans)
        s[ans++] = vv[i];
      else
        *it = vv[i];
    }
    cout << ans;
  } else
    cout << 0;
  return 0;
}
