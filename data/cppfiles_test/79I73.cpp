#include <bits/stdc++.h>
using namespace std;
pair<long long, long long> NEUT = {1e9, -1};
struct STree {
  vector<pair<long long, long long>> t;
  int n;
  STree(int n) : t(2 * n + 5, NEUT), n(n) {}
  void upd(int p, pair<long long, long long> value) {
    for (t[p += n] = value; p > 1; p >>= 1) t[p >> 1] = min(t[p], t[p ^ 1]);
  }
  pair<long long, long long> query(int l, int r) {
    pair<long long, long long> res = NEUT;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) res = min(res, t[l++]);
      if (r & 1) res = min(res, t[--r]);
    }
    return res;
  }
};
STree st(300005);
vector<long long> oc[300005];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  vector<long long> a(n), b(n);
  for (int i = 0, ggdem = n; i < ggdem; ++i) cin >> a[i];
  for (int i = 0, ggdem = n; i < ggdem; ++i) cin >> b[i];
  for (int i = 0, ggdem = n; i < ggdem; ++i) {
    oc[i + 1 + b[i]].push_back(i + 1);
  }
  st.upd(0, {0, 0});
  vector<long long> p(n + 1), res(n + 1);
  p[0] = -1;
  for (int i = 0, ggdem = n; i < ggdem; ++i) {
    auto q = st.query(i + 1 - a[i], i + 1);
    res[i + 1] = q.first + 1;
    p[i + 1] = q.second;
    for (auto j : oc[i + 1]) {
      st.upd(j, {res[i + 1], j});
    }
  }
  if (res[n] <= n) {
    cout << res[n] << "\n";
    long long va = n;
    va = p[va];
    while (va != -1) {
      cout << va << " ";
      if (va > 0) va += b[va - 1];
      va = p[va];
    }
    cout << "\n";
  } else
    cout << "-1\n";
  return 0;
}
