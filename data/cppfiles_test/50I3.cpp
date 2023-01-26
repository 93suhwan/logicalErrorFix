#include <bits/stdc++.h>
using namespace std;
template <typename T>
using matrix = vector<vector<T>>;
const long long INFL = (1LL << 62) - 1;
const int INF = (1 << 30) - 1;
const double EPS = 1e-7;
const int MOD = 998244353;
const int RANDOM =
    chrono::high_resolution_clock::now().time_since_epoch().count();
const int MAXN = 1e6 + 1;
struct seg {
  int sum, mult, add, e, d;
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<seg> tree;
  function<int()> create = [&] {
    int ret = tree.size();
    tree.push_back({0, 1, 0, 0, 0});
    return ret;
  };
  create();
  function<void(long long, long long, long long)> refresh =
      [&](long long id, long long l, long long r) {
        if (tree[id].mult == 1 && tree[id].add == 0) return;
        int e = tree[id].e, d = tree[id].d;
        if (l != r) {
          tree[e].mult *= tree[id].mult;
          tree[e].add *= tree[id].mult;
          tree[e].add = ((long long)tree[e].add + tree[id].add + MOD) % MOD;
          tree[d].mult *= tree[id].mult;
          tree[d].add *= tree[id].mult;
          tree[d].add = ((long long)tree[d].add + tree[id].add + MOD) % MOD;
        }
        tree[id].sum *= tree[id].mult;
        tree[id].sum =
            (tree[id].sum + (long long)(r - l + 1) * tree[id].add + MOD) % MOD;
        tree[id].mult = 1;
        tree[id].add = 0;
      };
  function<void(long long, long long, long long, long long, long long,
                long long, long long)>
      update = [&](long long id, long long l, long long r, long long ql,
                   long long qr, long long t, long long val) {
        int e = tree[id].e, d = tree[id].d, m = (l + r) >> 1;
        if (l != r && e == 0) {
          e = create();
          d = create();
          tree[id].e = e, tree[id].d = d;
        }
        refresh(id, l, r);
        if (l > qr || r < ql) return;
        if (ql <= l && r <= qr) {
          if (t) {
            tree[id].mult *= val;
            tree[id].add *= val;
          } else {
            tree[id].add += val;
          }
          refresh(id, l, r);
          return;
        }
        update(e, l, m, ql, qr, t, val);
        update(d, m + 1, r, ql, qr, t, val);
        tree[id].sum = (tree[e].sum + tree[d].sum + MOD) % MOD;
      };
  long long last = 1;
  for (int i = 0; i < n; i++) {
    int in;
    cin >> in;
    if (in != 1e9) update(0, 1, 1e9, in + 1, 1e9, 1, 0);
    update(0, 1, 1e9, 1, 1e9, 1, -1);
    update(0, 1, 1e9, 1, in, 0, last);
    last = tree[0].sum;
  }
  cout << last << '\n';
  return 0;
}
