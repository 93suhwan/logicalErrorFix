#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<ll, ll>;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll minf = 0xc0c0c0c0c0c0c0c0;
struct Segtree {
  struct Node {
    ll val, lazy;
  };
  vector<Node> A;
  Segtree(ll node_size) : A(node_size * 4 + 5) {}
  void prop(ll nidx, ll st, ll en) {
    if (A[nidx].lazy == 0) {
      return;
    }
    A[nidx].val += (en - st + 1) * A[nidx].lazy;
    if (st != en) {
      A[nidx << 1].lazy += A[nidx].lazy;
      A[nidx << 1 | 1].lazy += A[nidx].lazy;
    }
    A[nidx].lazy = 0;
  }
  ll solve(ll nidx, ll st, ll en, ll le, ll ri) {
    prop(nidx, st, en);
    if (st > ri || en < le || le > ri) {
      return 0;
    }
    if (le <= st && en <= ri) {
      return A[nidx].val;
    }
    return solve(nidx << 1, st, (st + en) >> 1, le, ri) +
           solve(nidx << 1 | 1, ((st + en) >> 1) + 1, en, le, ri);
  }
  void update(ll nidx, ll st, ll en, ll le, ll ri, ll val) {
    prop(nidx, st, en);
    if (st > ri || en < le || le > ri) {
      return;
    }
    if (le <= st && en <= ri) {
      A[nidx].val += (en - st + 1) * val;
      if (st != en) {
        A[nidx << 1].lazy += val;
        A[nidx << 1 | 1].lazy += val;
      }
      return;
    }
    update(nidx << 1, st, (st + en) >> 1, le, ri, val);
    update(nidx << 1 | 1, ((st + en) >> 1) + 1, en, le, ri, val);
    A[nidx].val = A[nidx << 1].val + A[nidx << 1 | 1].val;
  }
  void update2(ll nidx, ll st, ll en, ll idx, ll val) {
    prop(nidx, st, en);
    ll mid = (st + en) / 2;
    if (st == en) {
      A[nidx].val = val;
      return;
    }
    if (idx <= mid) {
      update2(nidx * 2, st, mid, idx, val);
    } else {
      update2(nidx * 2 + 1, mid + 1, en, idx, val);
    }
    A[nidx].val = A[nidx << 1].val + A[nidx << 1 | 1].val;
  }
};
set<ll> se[1010];
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n, m, Q;
  cin >> n >> m >> Q;
  while (Q--) {
    ll x, y;
    cin >> x >> y;
    if (se[x].count(y)) {
      se[x].erase(y);
    } else {
      se[x].insert(y);
    }
    Segtree tree(m);
    function<ll(ll, ll)> getsum = [&](ll le, ll ri) {
      if (le > ri) {
        return 0LL;
      }
      if (le == ri) {
        return tree.solve(1, 1, m, le, le);
      }
      ll mid = (le + ri) / 2;
      ll ret = getsum(le, mid) + getsum(mid + 1, ri);
      ll rcnt = ri - mid;
      ret += tree.solve(1, 1, m, le, mid) * rcnt;
      return ret;
    };
    ll res = 0;
    for (ll i = 1; i <= n; i++) {
      tree.update(1, 1, m, 1, m, 1);
      for (auto j : se[i]) {
        tree.update2(1, 1, m, j, 0);
      }
      ll left = 1;
      for (auto j : se[i]) {
        if (left == j) {
          ++left;
          continue;
        }
        res += getsum(left, j - 1);
        left = j + 1;
      }
      res += getsum(left, m);
    }
    cout << res << '\n';
  }
  return 0;
}
