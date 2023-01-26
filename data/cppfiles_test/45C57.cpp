#include <bits/stdc++.h>
using namespace std;
const long long N = 1000006, INF = 1e18, P = 998244353;
long long q = 1, n, m, x, y, z, l, r, k, a[N], b[N], f[N], ans1, o, u, ans2;
vector<pair<int, int> > v[N], V;
string s, t;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  cin >> q;
  while (q--) {
    o = 0;
    cin >> n;
    b[0] = b[1] = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      a[i] &= 1;
      b[a[i]]++;
    }
    if (abs(b[0] - b[1]) > 1)
      cout << "-1\n";
    else {
      o = 1;
      ans1 = ans2 = 0;
      u = 2;
      if (n % 2 == 1) {
        if (b[1] < b[0])
          ans1 = INF;
        else
          ans2 = INF;
      }
      for (int i = 1; i <= n; i++) {
        if (a[i] == 1) {
          ans1 += abs(i - o);
          o += 2;
          ans2 += abs(i - u);
          u += 2;
        }
      }
      cout << min(ans1, ans2) << '\n';
    }
  }
}
