#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
struct FT {
  vector<long long> s;
  FT(int n) : s(n) {}
  void upd(int pos, long long dif) {
    for (; pos < (int)(s).size(); pos |= pos + 1) s[pos] += dif;
  }
  long long qry(int pos) {
    long long res = 0;
    for (; pos > 0; pos &= pos - 1) res += s[pos - 1];
    return res;
  }
  int lower_bound(long long sum) {
    if (sum <= 0) return -1;
    int pos = 0;
    for (int pw = 1 << 25; pw; pw >>= 1) {
      if (pos + pw <= (int)(s).size() && s[pos + pw - 1] < sum)
        pos += pw, sum -= s[pos - 1];
    }
    return pos;
  }
};
int n, a[N];
bool vis[N];
void solve() {
  cin >> n;
  fill(vis, vis + n, 0);
  bool ok = false;
  for (int i = 0; i < (n); ++i) {
    cin >> a[i];
    --a[i];
    if (vis[a[i]]) {
      ok = true;
    } else {
      vis[a[i]] = true;
    }
  }
  FT ft(n);
  long long cnt = 0;
  for (int i = 0; i < (n); ++i) {
    cnt += ft.qry(n) - ft.qry(a[i] + 1);
    ft.upd(a[i], 1);
  }
  cout << (cnt % 2 == 0 || ok ? "YES\n" : "NO\n");
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
