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
  vi s(n);
  s[0] = v[0].second;
  int last = 0;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (v[i].second >= 0 && v[i].first > last) {
      auto it = upper_bound(s.begin(), s.begin() + ans, v[i].second);
      if (it == s.begin() + ans)
        s[ans++] = v[i].second;
      else
        *it = v[i].second;
    }
    last = v[i].first;
  }
  cout << ans;
  return 0;
}
