#include <bits/stdc++.h>
using namespace std;
const int P = 13331;
const int N = 2e5 + 10, M = 2 * N, MOD = 998244353;
int n;
int a[N], b[N];
void solve() {
  cin >> n;
  vector<pair<int, int> > vc;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  sort(b + 1, b + 1 + n);
  for (int i = 1; i <= n; i++) {
    int p = i;
    for (int j = i; j <= n; j++) {
      if (a[j] == b[i]) p = j;
      if (p != i) {
        vc.push_back({i, j});
        int t = a[p];
        for (int k = p; k > i; k--) a[k] = a[k - 1];
        a[i] = t;
        break;
      }
    }
  }
  cout << vc.size() << '\n';
  for (auto t : vc) cout << t.first << " " << t.second << " " << 1 << '\n';
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
