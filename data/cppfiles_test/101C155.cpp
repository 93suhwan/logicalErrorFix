#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt,fma")
#pragma GCC optimize("unroll-loops")
const long long int MAXN = 2e5 + 5;
const long long int mod = 1000000007;
const long long int N = 200005;
void solve() {
  map<pair<int, int>, vector<int>> mpX, mpY;
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> xec(n), yec(m);
  map<int, int> haveX, haveY;
  for (int i = 0; i < n; i++) {
    cin >> xec[i], haveX[xec[i]] += 1;
  }
  for (int i = 0; i < m; i++) {
    cin >> yec[i], haveY[yec[i]] += 1;
  }
  for (int i = 0; i < k; i++) {
    int x, y;
    cin >> x >> y;
    if (haveX[x] && haveY[y]) continue;
    if (haveX[x]) {
      int idx = lower_bound(yec.begin(), yec.end(), y) - yec.begin();
      mpX[{yec[idx - 1], yec[idx]}].push_back(x);
    }
    if (haveY[y]) {
      int idx = lower_bound(xec.begin(), xec.end(), x) - xec.begin();
      mpY[{xec[idx - 1], xec[idx]}].push_back(y);
    }
  }
  long long int ans = 0;
  for (auto [a, b] : mpX) {
    sort(b.begin(), b.end());
    map<int, int> mpTemp;
    int total = b.size();
    for (auto x : b) {
      mpTemp[x] += 1;
    }
    for (auto [c, d] : mpTemp) {
      ans += (long long int)d * (long long int)(total - d);
    }
  }
  for (auto [a, b] : mpY) {
    sort(b.begin(), b.end());
    map<int, int> mpTemp;
    int total = b.size();
    for (auto y : b) {
      mpTemp[y] += 1;
    }
    for (auto [c, d] : mpTemp) {
      ans += (long long int)d * (long long int)(total - d);
    }
  }
  cout << ans / 2ll << "\n";
  return;
}
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
