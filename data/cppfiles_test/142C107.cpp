#include <bits/stdc++.h>
using namespace std;
bool good(long long m, vector<vector<int>> p, int x) {
  int y = p[0].size();
  long long c = 0;
  vector<bool> k(y);
  bool f = 0;
  for (int i = 0; i < int(x); i++) {
    c = 0;
    for (int j = 0; j < int(y); j++) {
      if (p[i][j] >= m) {
        k[j] = 1;
        c++;
      }
    }
    if (c > 1) f = 1;
  }
  if (!f && y > 1) return false;
  bool ans = 1;
  for (auto x : k) {
    ans &= x;
  }
  return ans;
}
void solve() {
  int m, n;
  cin >> m >> n;
  vector<vector<int>> p(m);
  for (int i = 0; i < int(m); i++) {
    for (int j = 0; j < int(n); j++) {
      int x;
      cin >> x;
      p[i].push_back(x);
    }
  }
  long long l = -1;
  long long r = 1000000005;
  long long ans = 0;
  while (r - l > 1) {
    long long mid = l + (r - l) / 2;
    if (good(mid, p, m)) {
      l = mid;
      ans = l;
    } else
      r = mid;
  }
  cout << ans << endl;
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
