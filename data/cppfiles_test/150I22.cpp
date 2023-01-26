#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
int T, n;
vector<int> v;
void solve() {
  cin >> n;
  v.clear();
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    v.push_back(x);
  }
  int ans = 0;
  sort(v.begin(), v.end());
  if (v.back() % 3 == 0) {
    bool f = false;
    for (int i = 0; i < n; i++)
      if (v[i] % 3 != 0) f = true;
    ans = v.back() / 3 + f;
  } else if (v.back() % 3 == 1) {
    ans = v.back() / 3 + 1;
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
