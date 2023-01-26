#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 100;
const int inf = 1e9;
const long long mod = 998244353;
int n;
int a[N];
int hav[N];
void sol() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) hav[i] = 0;
  vector<int> can;
  int res = n;
  for (int i = 1; i <= n; i++) {
    int x = a[i];
    if (x >= 1 && x <= n) {
      if (!hav[x]) {
        hav[x] = 1;
        res--;
      } else
        can.push_back((x - 1) / 2);
    } else
      can.push_back((x - 1) / 2);
  }
  sort((can).begin(), (can).end());
  int nw = n;
  while (nw >= 1) {
    while (nw >= 1 && hav[nw]) --nw;
    if (nw == 0) break;
    if (can.back() < nw) return (void)(cout << -1 << '\n');
    can.pop_back();
    hav[nw] = 1;
  }
  cout << res << '\n';
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) sol();
}
