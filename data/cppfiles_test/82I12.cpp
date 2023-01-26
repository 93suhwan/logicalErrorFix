#include <bits/stdc++.h>
using namespace std;
template <typename T>
void __read(T &a) {
  cin >> a;
}
template <typename T, typename... Args>
void __read(T &a, Args &...args) {
  cin >> a;
  __read(args...);
}
constexpr long long M7 = 1000000007;
constexpr long long M9 = 1000000009;
constexpr long long MFFT = 998244353;
constexpr double PI = 3.14159265358979323846;
template <class T>
void outv(const T &a, char d = ' ', bool nl = false) {
  for (auto &x : a) cout << x << d;
  if (nl) cout << '\n';
}
static mt19937_64 rnd(static_cast<unsigned>(
    chrono::steady_clock::now().time_since_epoch().count()));
auto __fast_io__ = (ios_base::sync_with_stdio(false), cin.tie(nullptr));
struct segtree {
  struct node {
    long long mn = 0;
    long long sm = 0;
    long long add = 0;
    node(long long val = 0) : mn(val), sm(val), add(0){};
    template <class T>
    void apply(int32_t l, int32_t r, const T &ext) {
      if (ext == 0) return;
      mn = ext;
      sm = ext * (r - l + 1);
      add = ext;
    }
  };
  vector<node> tree;
  long long sz;
  inline node unite(const node &a, const node &b) {
    node res;
    res.mn = min(a.mn, b.mn);
    res.sm = a.sm + b.sm;
    return res;
  }
  inline void push(int32_t pos, int32_t rpos, int32_t l, int32_t r) {
    int32_t mid = (l + r) / 2;
    tree[pos + 1].apply(l, mid, tree[pos].add);
    tree[rpos].apply(mid + 1, r, tree[pos].add);
    tree[pos].add = 0;
  }
  inline void up(int32_t pos, int32_t rpos) {
    tree[pos] = unite(tree[pos + 1], tree[rpos]);
  }
  void build(int32_t pos, int32_t l, int32_t r) {
    if (l != r) {
      int32_t mid = (l + r) / 2;
      int32_t rpos = pos + (mid - l + 1) * 2;
      build(pos + 1, l, mid);
      build(rpos, mid + 1, r);
      up(pos, rpos);
    }
  }
  template <class TIter>
  void build(int32_t pos, int32_t l, int32_t r, TIter &iter) {
    if (l == r) {
      tree[pos] = node(*iter);
      iter++;
    } else {
      int32_t mid = (l + r) / 2;
      int32_t rpos = pos + (mid - l + 1) * 2;
      build(pos + 1, l, mid, iter);
      build(rpos, mid + 1, r, iter);
      up(pos, rpos);
    }
  }
  segtree(long long sz) {
    this->sz = sz;
    tree.resize(2 * sz - 1);
    build(0, 0, sz - 1);
  }
  template <class TIter>
  segtree(TIter begin, TIter end) {
    sz = distance(begin, end);
    tree.resize(2 * sz - 1);
    build(0, 0, sz - 1, begin);
  }
  node get(int32_t pos, int32_t l, int32_t r, int32_t ind) {
    if (l == r) {
      return tree[pos];
    }
    int32_t mid = (l + r) / 2;
    int32_t rpos = pos + (mid - l + 1) * 2;
    push(pos, rpos, l, r);
    if (ind <= mid) {
      return get(pos + 1, l, mid, ind);
    }
    return get(rpos, mid + 1, r, ind);
  }
  node get(int32_t pos, int32_t l, int32_t r, int32_t ql, int32_t qr) {
    if (l >= ql && r <= qr) {
      return tree[pos];
    }
    int32_t mid = (l + r) / 2;
    int32_t rpos = pos + (mid - l + 1) * 2;
    push(pos, rpos, l, r);
    if (qr <= mid) {
      return get(pos + 1, l, mid, ql, qr);
    } else if (ql > mid) {
      return get(rpos, mid + 1, r, ql, qr);
    }
    return unite(get(pos + 1, l, mid, ql, qr), get(rpos, mid + 1, r, ql, qr));
  }
  node get(int32_t ind) {
    assert(0 <= ind && ind < sz);
    return get(0, 0, sz - 1, ind);
  }
  node get(int32_t l, int32_t r) {
    assert(0 <= l && l <= r && r < sz);
    return get(0, 0, sz - 1, l, r);
  }
  void getNodes(int32_t pos, int32_t l, int32_t r, int32_t ql, int32_t qr,
                vector<tuple<int32_t, int32_t, node *>> &res) {
    if (l >= ql && r <= qr) {
      res.emplace_back(l, r, &tree[pos]);
      return;
    }
    int32_t mid = (l + r) / 2;
    int32_t rpos = pos + (mid - l + 1) * 2;
    push(pos, rpos, l, r);
    if (ql <= mid) {
      getNodes(pos + 1, l, mid, ql, qr, res);
    }
    if (qr > mid) {
      getNodes(rpos, mid + 1, r, ql, qr, res);
    }
  }
  vector<tuple<int32_t, int32_t, node *>> getNodes(int32_t l, int32_t r) {
    assert(0 <= l && l <= r && r < sz);
    vector<tuple<int32_t, int32_t, node *>> res;
    getNodes(0, 0, sz - 1, l, r, res);
    return res;
  }
  template <class T>
  void set(int32_t pos, int32_t l, int32_t r, int32_t ind, const T &val) {
    if (l == r) {
      tree[pos] = node(val);
      return;
    }
    int32_t mid = (l + r) / 2;
    int32_t rpos = pos + (mid - l + 1) * 2;
    push(pos, rpos, l, r);
    if (ind <= mid) {
      set(pos + 1, l, mid, ind, val);
    } else {
      set(rpos, mid + 1, r, ind, val);
    }
    up(pos, rpos);
  }
  template <class T>
  void set(int32_t ind, const T &val) {
    assert(0 <= ind && ind < sz);
    set(0, 0, sz - 1, ind, val);
  }
  template <class T>
  void modify(int32_t pos, int32_t l, int32_t r, int32_t ql, int32_t qr,
              const T &ext) {
    if (l >= ql && r <= qr) {
      tree[pos].apply(l, r, ext);
      return;
    }
    int32_t mid = (l + r) / 2;
    int32_t rpos = pos + (mid - l + 1) * 2;
    push(pos, rpos, l, r);
    if (ql <= mid) {
      modify(pos + 1, l, mid, ql, qr, ext);
    }
    if (qr > mid) {
      modify(rpos, mid + 1, r, ql, qr, ext);
    }
    up(pos, rpos);
  }
  template <class T>
  void modify(int32_t l, int32_t r, const T &ext) {
    assert(0 <= l && l <= r && r < sz);
    modify(0, 0, sz - 1, l, r, ext);
  }
  template <class TFunc>
  int32_t findFirst(int32_t pos, int32_t l, int32_t r, const TFunc &f) {
    if (l == r) {
      return l;
    }
    int32_t mid = (l + r) / 2;
    int32_t rpos = pos + (mid - l + 1) * 2;
    push(pos, rpos, l, r);
    if (f(tree[pos + 1])) {
      return findFirst(pos + 1, l, mid, f);
    }
    return findFirst(rpos, mid + 1, r, f);
  }
  template <class TFunc>
  int32_t findFirst(int32_t pos, int32_t l, int32_t r, int32_t ql, int32_t qr,
                    const TFunc &f) {
    if (l >= ql && r <= qr) {
      if (f(tree[pos])) {
        return findFirst(pos, l, r, f);
      }
      return -1;
    }
    int32_t mid = (l + r) / 2;
    int32_t rpos = pos + (mid - l + 1) * 2;
    push(pos, rpos, l, r);
    int32_t res = -1;
    if (ql <= mid) {
      res = findFirst(pos + 1, l, mid, ql, qr, f);
    }
    if (res == -1 && qr > mid) {
      res = findFirst(rpos, mid + 1, r, ql, qr, f);
    }
    return res;
  }
  template <class TFunc>
  int32_t findFirst(int32_t l, int32_t r, const TFunc &f) {
    assert(0 <= l && l <= r && r < sz);
    return findFirst(0, 0, sz - 1, l, r, f);
  }
  template <class TFunc>
  int32_t findLast(int32_t pos, int32_t l, int32_t r, const TFunc &f) {
    if (l == r) {
      return l;
    }
    int32_t mid = (l + r) / 2;
    int32_t rpos = pos + (mid - l + 1) * 2;
    push(pos, rpos, l, r);
    if (f(tree[rpos])) {
      return findLast(rpos, mid + 1, r, f);
    }
    return findLast(pos + 1, l, mid, f);
  }
  template <class TFunc>
  int32_t findLast(int32_t pos, int32_t l, int32_t r, int32_t ql, int32_t qr,
                   const TFunc &f) {
    if (l >= ql && r <= qr) {
      if (f(tree[pos])) {
        return findLast(pos, l, r, f);
      }
      return sz;
    }
    int32_t mid = (l + r) / 2;
    int32_t rpos = pos + (mid - l + 1) * 2;
    push(pos, rpos, l, r);
    int32_t res = sz;
    if (qr > mid) {
      res = findLast(rpos, mid + 1, r, ql, qr, f);
    }
    if (res == sz && ql <= mid) {
      res = findLast(pos + 1, l, mid, ql, qr, f);
    }
    return res;
  }
  template <class TFunc>
  int32_t findLast(int32_t l, int32_t r, const TFunc &f) {
    assert(0 <= l && l <= r && r < sz);
    return findLast(0, 0, sz - 1, l, r, f);
  }
  void dbg(int32_t pos, int32_t l, int32_t r) {
    if (l == r) {
      return;
    }
    int32_t mid = (l + r) / 2;
    int32_t rpos = pos + (mid - l + 1) * 2;
    push(pos, rpos, l, r);
    dbg(pos + 1, l, mid);
    dbg(rpos, mid + 1, r);
  }
};
int32_t main() {
  long long n, q, k;
  __read(n, q, k);
  vector<long long> a(n);
  for (auto &v : (a)) cin >> v;
  ;
  vector<pair<long long, long long>> qr(q);
  for (auto &[l, r] : qr) {
    cin >> l >> r;
    l--, r--;
  }
  deque<long long> dq;
  vector<long long> b(n);
  for (long long i = 0; i < n; ++i) {
    while (!dq.empty() && a[dq.back()] >= a[i]) dq.pop_back();
    dq.push_back(i);
    if (dq.front() == i - k) dq.pop_front();
    b[i] = a[dq.front()];
  }
  vector<vector<pair<long long, long long>>> c(k);
  for (long long i = 0; i < q; ++i) {
    auto &[l, r] = qr[i];
    c[l % k].emplace_back(l, i);
  }
  segtree st(n + k);
  vector<long long> ans(q);
  for (long long kk = 0; kk < k; ++kk) {
    st.modify(0, n + k - 1, M7);
    long long rem = (n - kk - 1) % k;
    sort(c[rem].begin(), c[rem].end());
    long long ptr = static_cast<long long>(c[rem].size()) - 1;
    for (long long i = n - kk - 1; i >= 0; i -= k) {
      while (ptr >= 0 && c[rem][ptr].first == i) {
        long long ind = c[rem][ptr].second;
        auto &[l, r] = qr[ind];
        long long sz = (r - l + k) / k;
        if (sz > 1) {
          ans[ind] = st.get(l + 1, l + (sz - 1) * k).sm;
          ans[ind] /= k;
        }
        ans[ind] += a[l];
        ptr--;
      }
      long long pos = st.findFirst(
          i, n + k - 1, [&](const segtree::node &v) { return v.mn < b[i]; });
      st.modify(max(0ll, i - k + 1), (pos == -1 ? n - kk : pos) - 1, b[i]);
    }
  }
  for (long long i = 0; i < q; ++i) cout << ans[i] << '\n';
  return 0;
}
