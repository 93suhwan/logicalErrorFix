#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using vi = vector<int>;
using vl = vector<ll>;
const int MOD = 1e9 + 7;
const int MX = 1e5 + 10;
using pi = pair<int, int>;
void setIO(string name = "") {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  if ((int)(name).size()) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
  }
}
int main() {
  setIO();
  int T;
  cin >> T;
  for (int tt = 1; tt <= T; tt++) {
    cerr << "CASE " << tt << '\n';
    int n;
    cin >> n;
    vi a(n);
    for (int i = (0); i < (n); ++i) cin >> a[i];
    vi v = a;
    sort(begin(v), end(v));
    vi l, r, d;
    int ans = 0;
    for (int i = (0); i < (n); ++i) {
      int L = i, R;
      for (int j = i; j < n; j++) {
        if (a[j] == v[i]) {
          R = j;
          break;
        }
      }
      if (R == L) continue;
      vi b = a;
      int sh = R - L;
      for (int j = L; j <= R; j++) {
        int id = j - sh;
        if (id < 0)
          id += R + 1;
        else if (id < L && id >= 0)
          id += R;
        b[id] = a[j];
      }
      a = b;
      if (sh > 0) {
        ans++;
        l.push_back(L);
        r.push_back(R);
        d.push_back(sh);
      }
    }
    cout << ans << '\n';
    for (int i = (0); i < (ans); ++i) {
      cout << l[i] + 1 << ' ' << r[i] + 1 << ' ' << d[i] << '\n';
    }
  }
  return 0;
}
