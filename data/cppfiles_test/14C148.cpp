#include <bits/stdc++.h>
using namespace std;
const int P = 13331;
const int N = 100, M = 2 * N, MOD = 998244353;
int n, m, k;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) cin >> a[i];
  vector<pair<int, int> > res;
  for (int i = n; i > 1; --i) {
    int k = 1;
    for (int j = 2; j <= i; ++j) {
      if (a[j] > a[k]) k = j;
    }
    if (k == i) continue;
    res.push_back({k, i});
    int t = a[k];
    for (int j = k; j < i; ++j) {
      a[j] = a[j + 1];
    }
    a[i] = t;
  }
  printf("%d\n", (int)res.size());
  for (auto it : res) {
    printf("%d %d 1\n", it.first, it.second);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
