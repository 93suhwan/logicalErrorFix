#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
void disp(long long first, string s = "\n") { cout << first << s; }
pair<long long, long long> upd(pair<long long, long long> a,
                               pair<long long, long long> b) {
  return make_pair(min(a.first, b.first), max(a.second, b.second));
}
struct Seg {
  int l, r, m;
  long long mn, mx;
  Seg *ch[2];
  Seg(int _l, int _r, vector<long long> &a) : l(_l), r(_r), m(l + r >> 1) {
    if (r - l > 1) {
      ch[0] = new Seg(l, m, a);
      ch[1] = new Seg(m, r, a);
      pull();
    } else {
      mx = mn = a[l];
    }
  }
  void pull() {
    mn = min(ch[0]->mn, ch[1]->mn);
    mx = max(ch[0]->mx, ch[1]->mx);
  }
  pair<long long, long long> query(int ql, int qr) {
    if (ql <= l && r <= qr) return make_pair(mn, mx);
    pair<long long, long long> ans = make_pair(2e15, -2e15);
    if (ql < m) ans = upd(ans, ch[0]->query(ql, qr));
    if (m < qr) ans = upd(ans, ch[1]->query(ql, qr));
    return ans;
  }
};
void solve() {
  int n, q;
  cin >> n >> q;
  vector<long long> A(n);
  for (auto &it : A) cin >> it;
  vector<long long> pre = {0};
  for (auto it : A) {
    long long first;
    cin >> first;
    pre.push_back(pre.back() + it - first);
  }
  Seg root(0, n, pre);
  while (q--) {
    int ql, qr;
    cin >> ql >> qr, ql--;
    if (pre[ql] != pre[qr])
      disp(-1);
    else {
      pair<long long, long long> res = root.query(ql, qr);
      if (res.second > pre[ql])
        disp(-1);
      else
        disp(pre[ql] - res.first);
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
