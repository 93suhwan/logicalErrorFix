#include <bits/stdc++.h>
using namespace std;
struct segtree {
  struct node {
    int s1 = 0, s2 = 0;
    void upd(int l, int r, int v1, int v2) {
      s1 += v1;
      s2 += v2;
    }
  };
  node merge(const node &x, const node &y) {
    node ret;
    ret.s1 = x.s1 + y.s1;
    ret.s2 = x.s2 + y.s2;
    return ret;
  }
  void build(int l, int r, int rt) {
    if (l == r) {
      return;
    }
    int m = (l + r) / 2;
    build(l, m, rt << 1);
    build(m + 1, r, rt << 1 | 1);
    a[rt] = merge(a[rt << 1], a[rt << 1 | 1]);
  }
  template <typename T>
  void build(int l, int r, int rt, const vector<T> &v) {
    if (l == r) {
      return;
    }
    int m = (l + r) / 2;
    build(l, m, rt << 1, v);
    build(m + 1, r, rt << 1 | 1, v);
    a[rt] = merge(a[rt << 1], a[rt << 1 | 1]);
  }
  segtree(int n) : n(n), a(n << 2) { build(0, n - 1, 1); }
  template <typename T>
  segtree(const vector<T> &v) : n(v.size()), a(v.size() << 2) {
    build(0, n - 1, 1, v);
  }
  int n;
  vector<node> a;
  template <typename... V>
  void update(int L, int R, int l, int r, int rt, const V &...v) {
    if (L <= l && r <= R) {
      a[rt].upd(l, r, v...);
      return;
    }
    int m = (l + r) / 2;
    if (L <= m) update(L, R, l, m, rt << 1, v...);
    if (m < R) update(L, R, m + 1, r, rt << 1 | 1, v...);
    a[rt] = merge(a[rt << 1], a[rt << 1 | 1]);
  }
  template <typename... V>
  void upd(int L, int R, const V &...v) {
    update(L, R, 0, n - 1, 1, v...);
  }
  int query(int l, int r, int rt, int sl, int sr) {
    if (l == r) return max(a[rt].s1 + sl, a[rt].s2 + sr);
    node ret;
    int m = (l + r) / 2;
    if (sl + a[rt << 1].s1 < sr + a[rt << 1 | 1].s2)
      return query(m + 1, r, rt << 1 | 1, sl + a[rt << 1].s1, sr);
    return query(l, m, rt << 1, sl, sr + a[rt << 1 | 1].s2);
  }
  int query2(int l, int r, int rt, int sl, int sr) {
    if (l == r) return max(a[rt].s2 + sl, a[rt].s1 + sr);
    node ret;
    int m = (l + r) / 2;
    if (sl + a[rt << 1].s2 < sr + a[rt << 1 | 1].s1)
      return query(m + 1, r, rt << 1 | 1, sl + a[rt << 1].s2, sr);
    return query(l, m, rt << 1, sl, sr + a[rt << 1 | 1].s1);
  }
  int qry() { return max(query(0, n - 1, 1, 0, 0), query2(0, n - 1, 1, 0, 0)); }
};
struct node {
  int x, y, c;
  bool operator<(const node &n) const { return x < n.x; }
};
int solve1(vector<node> a, int m) {
  int ret = 0, n = a.size();
  sort(a.begin(), a.end());
  for (int c1 = 1; c1 <= 3; ++c1) {
    int c2 = c1 % 3 + 1, c3 = c2 % 3 + 1;
    segtree st(m);
    for (auto [x, y, z] : a) {
      st.upd(y, y, z == c2, z == c3);
    }
    int cnt1 = 0;
    for (int i = 0, j; i < n; i = j) {
      j = i;
      while (j < n && a[j].x == a[i].x) {
        if (a[j].c == c1) {
          cnt1++;
        } else {
          st.upd(a[j].x, a[j].x, -(a[j].c == c2), -(a[j].c == c3));
        }
        ++j;
      }
      ret = max(ret, min(cnt1, st.qry()));
    }
  }
  reverse(a.begin(), a.end());
  for (int c1 = 1; c1 <= 3; ++c1) {
    int c2 = c1 % 3 + 1, c3 = c2 % 3 + 1;
    segtree st(m);
    for (auto [x, y, z] : a) {
      st.upd(y, y, z == c2, z == c3);
    }
    int cnt1 = 0;
    for (int i = 0, j; i < n; i = j) {
      j = i;
      while (j < n && a[j].x == a[i].x) {
        if (a[j].c == c1) {
          cnt1++;
        } else {
          st.upd(a[j].x, a[j].x, -(a[j].c == c2), -(a[j].c == c3));
        }
        ++j;
      }
      ret = max(ret, min(cnt1, st.qry()));
    }
  }
  return ret;
}
int solve2(vector<node> a) {
  sort(a.begin(), a.end());
  int n = a.size(), ret = 0;
  for (int c1 = 1; c1 <= 3; ++c1) {
    for (int c2 = c1 % 3 + 1, c3 = c2 % 3 + 1, f = 0; f < 2;
         c2 = c2 % 3 + 1, c3 = c3 % 3 + 1, ++f) {
      int cnt1 = 0, cnt21 = 0, cnt22 = 0, cnt31 = n / 3, cnt32 = n / 2;
      int k1 = 0, k2 = 0;
      for (int i = 0, j; i < n; i = j) {
        j = i;
        while (j < n && a[j].x == a[i].x) {
          if (a[j].c == c1)
            cnt1++;
          else if (a[j].c == c2)
            cnt21--, cnt22--;
          ++j;
        }
        if (!cnt1) continue;
        while (k1 < n && cnt21 < cnt1) {
          if (a[k1].c == c2)
            ++cnt21;
          else if (a[k1].c == c3)
            --cnt31;
          ++k1;
        }
        while (k1 < n && a[k1].x == a[k1 - 1].x) {
          if (a[k1].c == c2)
            ++cnt21;
          else if (a[k1].c == c3)
            --cnt31;
          ++k1;
        }
        while (k2 < n && cnt22 <= cnt1) {
          if (a[k2].c == c2)
            ++cnt22;
          else if (a[k2].c == c3)
            --cnt32;
          ++k2;
        }
        while (k2 < n && a[k2].x == a[k2 - 1].x) {
          if (a[k2].c == c2)
            ++cnt22;
          else if (a[k2].c == c3)
            --cnt32;
          ++k2;
        }
        ret = max(ret, min({cnt1, cnt21, cnt31}));
        ret = max(ret, min({cnt1, cnt22, cnt32}));
        if (!cnt31 && !cnt32) break;
      }
    }
  }
  return ret;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<node> a(n);
  vector<int> xx, yy;
  for (auto &[x, y, z] : a) {
    cin >> x >> y >> z;
    xx.push_back(x);
    yy.push_back(y);
  }
  sort(xx.begin(), xx.end());
  xx.resize(unique(xx.begin(), xx.end()) - xx.begin());
  sort(yy.begin(), yy.end());
  yy.resize(unique(yy.begin(), yy.end()) - yy.begin());
  for (auto &[x, y, z] : a) {
    x = lower_bound(xx.begin(), xx.end(), x) - xx.begin();
    y = lower_bound(yy.begin(), yy.end(), y) - yy.begin();
  }
  int ans = 0;
  ans = max(ans, solve1(a, yy.size()));
  ans = max(ans, solve2(a));
  for (auto &[x, y, z] : a) {
    swap(x, y);
  }
  ans = max(ans, solve1(a, xx.size()));
  ans = max(ans, solve2(a));
  cout << ans * 3 << '\n';
}
