#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long long int P2LIM = (long long int)2e18;
void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> ar(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    int mx = 0;
    for (int j = 0; j < x; j++) {
      int c;
      cin >> c;
      mx = max(mx, c - j);
    }
    ar[i] = {mx, x};
  }
  int ans = 0;
  int id = 0;
  sort(ar.begin(), ar.end());
  for (auto &it : ar) {
    ans = max(ans, it.first - id);
    id += it.second;
  }
  ans++;
  std::cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
