#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("-Ofast", "-funroll-all-loops", "-ffast-math")
#pragma GCC target("avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
const int inf = 0x3f3f3f3f;
const long long lnf = 0x7f7f7f7f7f7f7f7f;
const double eps = 1e-6;
const double pi = acos(-1.0);
const int mod = 998244353;
const int N = 1e6 + 10;
const int M = 1e7 + 10;
int t, n, q;
char s[N];
int sum[N];
vector<pair<int, int> > a;
int32_t main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    a.clear();
    cin >> n >> q >> (s + 1);
    for (int i = 1; i <= n; i++) {
      int op = (s[i] == '+' ? 1 : -1);
      if (i & 1)
        sum[i] = sum[i - 1] + op;
      else
        sum[i] = sum[i - 1] - op;
      if (i > 1) a.push_back({sum[i], i});
    }
    sort(a.begin(), a.end());
    while (q--) {
      int l, r;
      cin >> l >> r;
      int tmp1 = sum[r] - sum[l - 1];
      int tmp = abs(tmp1);
      tmp1 += sum[l - 1];
      if (tmp == 0)
        cout << 0 << '\n';
      else if (tmp & 1) {
        cout << 1 << '\n';
        int id =
            lower_bound(a.begin(), a.end(), make_pair(tmp1, l)) - a.begin();
        cout << a[id].second << '\n';
      } else {
        cout << 2 << '\n';
        int op = (s[r] == '+' ? 1 : -1);
        if (r & 1) op = -op;
        tmp1 += op;
        int id =
            lower_bound(a.begin(), a.end(), make_pair(tmp1, l)) - a.begin();
        cout << a[id].second - 1 << " " << r << '\n';
      }
    }
  }
  return 0;
}
