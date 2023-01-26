#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e9 + 7;
int n, a[100100], f[(1LL << (9)) + 7];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  memset(f, 0x3f, sizeof f);
  f[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int mask = 0; mask < (1LL << (9)); mask++)
      if (0 < f[mask] && f[mask] < a[i])
        f[mask ^ a[i]] =
            f[mask ^ a[i]] >= INF ? a[i] : min(f[mask ^ a[i]], a[i]);
  }
  vector<int> res;
  for (int i = 0; i < (1LL << (9)); i++)
    if (f[i] < INF) res.push_back(i);
  cout << (int)res.size() << "\n";
  for (auto p : res) cout << p << " ";
}
