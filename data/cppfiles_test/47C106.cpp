#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> u, v;
  for (int i = 0; i < n; ++i) {
    int p;
    cin >> p;
    if (p > 0)
      u.push_back(p);
    else
      v.push_back(-p);
  }
  sort(u.begin(), u.end());
  sort(v.begin(), v.end());
  long long ans = 0;
  for (int i = (int)u.size() - 1; i >= 0; i -= k) {
    ans += u[i];
  }
  for (int i = (int)v.size() - 1; i >= 0; i -= k) {
    ans += v[i];
  }
  ans <<= 1;
  int mx = 0;
  if (!u.empty()) mx = max(mx, u.back());
  if (!v.empty()) mx = max(mx, v.back());
  ans -= mx;
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
