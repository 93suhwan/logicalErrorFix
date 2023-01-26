#include <bits/stdc++.h>
using namespace std;
const int P = 13331;
const int N = 100, M = 2 * N, MOD = 998244353;
int n, m, k;
int a[N];
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  vector<pair<int, int> > vc;
  for (int i = 1; i <= n; i++) {
    int p = i;
    for (int j = i; j <= n; j++) {
      if (a[j] < a[i]) p = j;
    }
    if (p != i) {
      int tmp = a[p];
      for (int j = p; j > i; j--) a[j] = a[j - 1];
      a[i] = tmp;
      vc.push_back({i, p});
    }
  }
  cout << vc.size() << '\n';
  for (int i = 0; i < vc.size(); i++)
    cout << vc[i].first << " " << vc[i].second << " " << 1 << '\n';
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
