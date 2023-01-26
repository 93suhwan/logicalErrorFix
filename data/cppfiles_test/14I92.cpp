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
  int k = 1;
  for (int i = n; i; i--) {
    if (a[i] != b[i]) {
      int p = 0;
      for (int j = 1; j <= n; j++) {
        if (a[j] == b[i]) {
          p = j;
          break;
        }
      }
      vc.push_back({p, i});
      for (; p < i; p++) a[p] = a[p + 1];
    }
  }
  cout << vc.size() << '\n';
  for (auto t : vc) cout << t.first << " " << t.first << " " << 1 << '\n';
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
