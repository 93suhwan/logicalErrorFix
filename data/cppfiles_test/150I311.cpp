#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
int T, n;
vector<int> v;
map<int, bool> m;
void solve() {
  cin >> n;
  v.clear();
  m.clear();
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (!m[x]) v.push_back(x);
    m[x] = true;
  }
  int ans = 0;
  n = v.size();
  sort(v.begin(), v.end());
  if (v.back() % 3 == 0) {
    bool f = false;
    for (int i = 0; i < n; i++)
      if (v[i] % 3 != 0) f = true;
    ans = v.back() / 3 + f;
  } else if (v.back() % 3 == 1) {
    bool a = false, b = false;
    ans = v.back() / 3 + 1;
    for (int i = 0; i < n - 1; i++) {
      if (v[i] % 3 == 1) a = true;
      if (v[i] % 3 == 2) b = true;
    }
    ans += a & b;
  } else {
    bool f = false;
    for (int i = 0; i < n; i++)
      if (v[i] % 3 == 1) f = true;
    ans = v.back() / 3 + 1 + f;
  }
  cout << ans << "\n";
  return;
}
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  cin >> T;
  while (T--) solve();
  return 0;
}
