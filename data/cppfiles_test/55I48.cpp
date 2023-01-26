#include <bits/stdc++.h>
using namespace std;
template <class L, class R>
ostream &operator<<(ostream &os, map<L, R> P) {
  for (auto const &vv : P) os << "(" << vv.first << "," << vv.second << ")";
  return os;
}
template <class T>
ostream &operator<<(ostream &os, set<T> V) {
  os << "[";
  for (auto const &vv : V) os << vv << ",";
  os << "]";
  return os;
}
template <class T>
ostream &operator<<(ostream &os, vector<T> V) {
  os << "[";
  for (auto const &vv : V) os << vv << ",";
  os << "]";
  return os;
}
template <class L, class R>
ostream &operator<<(ostream &os, pair<L, R> P) {
  os << "(" << P.first << "," << P.second << ")";
  return os;
}
inline int fstoi(const string &str) {
  auto it = str.begin();
  bool neg = 0;
  int num = 0;
  if (*it == '-')
    neg = 1;
  else
    num = *it - '0';
  ++it;
  while (it < str.end()) num = num * 10 + (*it++ - '0');
  if (neg) num *= -1;
  return num;
}
inline void getch(char &x) {
  while (x = getchar_unlocked(), x < 33) {
    ;
  }
}
inline void getstr(string &str) {
  str.clear();
  char cur;
  while (cur = getchar_unlocked(), cur < 33) {
    ;
  }
  while (cur > 32) {
    str += cur;
    cur = getchar_unlocked();
  }
}
template <typename T>
inline bool sc(T &num) {
  bool neg = 0;
  int c;
  num = 0;
  while (c = getchar_unlocked(), c < 33) {
    if (c == EOF) return false;
  }
  if (c == '-') {
    neg = 1;
    c = getchar_unlocked();
  }
  for (; c > 47; c = getchar_unlocked()) num = num * 10 + c - 48;
  if (neg) num *= -1;
  return true;
}
template <typename T, typename... Args>
inline void sc(T &num, Args &...args) {
  bool neg = 0;
  int c;
  num = 0;
  while (c = getchar_unlocked(), c < 33) {
    ;
  }
  if (c == '-') {
    neg = 1;
    c = getchar_unlocked();
  }
  for (; c > 47; c = getchar_unlocked()) num = num * 10 + c - 48;
  if (neg) num *= -1;
  sc(args...);
}
struct Segtree {
  int mx[1000001 << 2];
  int ilemx[1000001 << 2];
  int mn[1000001 << 2];
  int ilemn[1000001 << 2];
  int t[1000001 << 2];
  int mx2[1000001 << 2];
  int mn2[1000001 << 2];
  int mxelazy[1000001 << 2];
  int mnelazy[1000001 << 2];
  void updatecr(int v) {
    t[v] = t[v << 1] + t[v << 1 | 1];
    if (mx[v << 1] > mx[v << 1 | 1]) {
      mx[v] = mx[v << 1];
      mx2[v] = max(mx[v << 1 | 1] != mx[v] ? mx[v << 1 | 1] : mx2[v << 1 | 1],
                   mx2[v << 1]);
      ilemx[v] =
          ilemx[v << 1] + (mx[v << 1 | 1] == mx[v] ? ilemx[v << 1 | 1] : 0);
    } else {
      mx[v] = mx[v << 1 | 1];
      mx2[v] =
          max(mx[v << 1] != mx[v] ? mx[v << 1] : mx2[v << 1], mx2[v << 1 | 1]);
      ilemx[v] = ilemx[v << 1 | 1] + (mx[v << 1] == mx[v] ? ilemx[v << 1] : 0);
    }
    if (mn[v << 1] < mn[v << 1 | 1]) {
      mn[v] = mn[v << 1];
      mn2[v] = min(mn[v << 1 | 1] != mn[v] ? mn[v << 1 | 1] : mn2[v << 1 | 1],
                   mn2[v << 1]);
      ilemn[v] =
          ilemn[v << 1] + (mn[v << 1 | 1] == mn[v] ? ilemn[v << 1 | 1] : 0);
    } else {
      mn[v] = mn[v << 1 | 1];
      mn2[v] =
          min(mn[v << 1] != mn[v] ? mn[v << 1] : mn2[v << 1], mn2[v << 1 | 1]);
      ilemn[v] = ilemn[v << 1 | 1] + (mn[v << 1] == mn[v] ? ilemn[v << 1] : 0);
    }
  }
  void build(int v, int tl, int tr, int a[]) {
    if (tl == tr) {
      t[v] = a[tl];
      mx[v] = mn[v] = a[tl];
      ilemx[v] = ilemn[v] = 1;
      mx2[v] = -0x7f7f7f7f;
      mn2[v] = 0x7f7f7f7f;
      return;
    }
    int tm = (tl + tr) / 2;
    build(v << 1, tl, tm, a);
    build(v << 1 | 1, tm + 1, tr, a);
    updatecr(v);
    mxelazy[v] = -0x7f7f7f7f;
    mnelazy[v] = 0x7f7f7f7f;
  }
  void push(int v, int tl, int tr) {
    int tm = (tl + tr) / 2;
    if (mnelazy[v] != 0x7f7f7f7f) {
      mnenodeupd(v << 1, tl, tm, mnelazy[v]);
      mnenodeupd(v << 1 | 1, tm + 1, tr, mnelazy[v]);
      mnelazy[v] = 0x7f7f7f7f;
    }
    if (mxelazy[v] != -0x7f7f7f7f) {
      mxenodeupd(v << 1, tl, tm, mxelazy[v]);
      mxenodeupd(v << 1 | 1, tm + 1, tr, mxelazy[v]);
      mxelazy[v] = -0x7f7f7f7f;
    }
  }
  int query(int v, int tl, int tr, int l, int r) {
    if (l > r) return (int)1e6;
    if (l == tl && r == tr) {
      return mn[v];
    }
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    return min(query(v << 1, tl, tm, l, min(tm, r)),
               query(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r));
  }
  void mnenodeupd(int v, int tl, int tr, int val) {
    if (mx[v] <= val || mx2[v] >= val) return;
    t[v] += ilemx[v] * (val - mx[v]);
    mx[v] = val;
    if (val < mn[v]) {
      mn[v] = val;
      ilemn[v] = ilemx[v];
    }
    if (mn[v] != val) mn2[v] = min(mn2[v], val);
    if (tl != tr) {
      int tm = (tl + tr) / 2;
      mnelazy[v] = min(mnelazy[v], val);
      if (mxelazy[v] > mnelazy[v]) {
        mxelazy[v] = mnelazy[v];
      }
    }
  }
  void modifymne(int v, int tl, int tr, int l, int r, int val) {
    if (l > r || mx[v] <= val) return;
    if (l == tl && r == tr && mx2[v] < val) {
      mnenodeupd(v, tl, tr, val);
      return;
    }
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    modifymne(v << 1, tl, tm, l, min(tm, r), val);
    modifymne(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r, val);
    updatecr(v);
  }
  void mxenodeupd(int v, int tl, int tr, int val) {
    if (mn[v] >= val || mn2[v] <= val) return;
    t[v] += ilemn[v] * (val - mn[v]);
    mn[v] = val;
    if (val > mx[v]) {
      mx[v] = val;
      ilemx[v] = ilemn[v];
    }
    if (mx[v] != val) mx2[v] = max(mx2[v], val);
    if (tl != tr) {
      int tm = (tl + tr) / 2;
      mxelazy[v] = max(mxelazy[v], val);
      if (mnelazy[v] < mxelazy[v]) mnelazy[v] = mxelazy[v];
    }
  }
  void modifymxe(int v, int tl, int tr, int l, int r, int val) {
    if (l > r || mn[v] >= val) return;
    if (l == tl && r == tr && mn2[v] > val) {
      mxenodeupd(v, tl, tr, val);
      return;
    }
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    modifymxe(v << 1, tl, tm, l, min(tm, r), val);
    modifymxe(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r, val);
    updatecr(v);
  }
};
struct sth {
  int l, r;
  int val;
};
inline bool operator<(const sth &f, const sth &s) { return f.l < s.l; }
class linkustree {
 public:
  set<sth> s;
  void init(int l, int r, int val) { s = {{l, r, val}}; }
  linkustree(int l, int r, int val) { init(l, r, val); }
  linkustree() { s = {{-1, 1000001, -1}}; }
  void insert(int l, int r, int val) {
    set<sth>::iterator it = prev(s.upper_bound({l, 0, 0}));
    if (it->r >= r) {
      if (it->val != val) {
        int origl = it->l, origr = it->r, origval = it->val;
        ++it;
        s.erase(prev(it));
        if (origval <= l - 1) s.insert({origl, l - 1, origval});
        s.insert({l, r, val});
        if (r + 1 <= origr) s.insert({r + 1, origr, origval});
      }
      return;
    }
    if (it->val == val) {
      int origl = it->l;
      ++it;
      s.erase(prev(it));
      s.insert({origl, r, val});
    } else {
      int origl = it->l, origval = it->val;
      ++it;
      s.erase(prev(it));
      if (origl <= l - 1) s.insert({origl, l - 1, origval});
      s.insert({l, r, val});
    }
    while (it != s.end() && it->l <= r) {
      if (it->r > r) {
        if (it->val == val) {
          int origr = it->r;
          ++it;
          s.erase(prev(it));
          int actuall = prev(it)->l;
          s.erase(prev(it));
          s.insert({actuall, origr, val});
        } else {
          int origr = it->r, origval = it->val;
          ++it;
          s.erase(prev(it));
          if (r + 1 <= origr) s.insert({r + 1, origr, origval});
        }
      } else {
        if (it->val != val) {
        }
        ++it;
        s.erase(prev(it));
      }
    }
  }
};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  sc(n, m);
  std::vector<int> vec;
  int segs[m][3];
  for (auto &i : segs) {
    for (auto &i : (i)) sc(i);
    --i[0];
    vec.push_back(i[1]);
    vec.push_back(i[2]);
  }
  sort(begin(vec), end(vec));
  vec.erase(unique(begin(vec), end(vec)), vec.end());
  int nn = vec.size();
  static Segtree t;
  int arr[nn];
  for (int i = (0); i < int((nn)); ++i) arr[i] = 0;
  t.build(1, 0, nn - 1, arr);
  vector<std::pair<int, int> > rows[n];
  for (auto &i : segs) {
    i[1] = lower_bound(begin(vec), end(vec), i[1]) - vec.begin();
    i[2] = lower_bound(begin(vec), end(vec), i[2]) - vec.begin();
    rows[i[0]].push_back({i[1], i[2]});
  }
  int res = n;
  ;
  linkustree l[2 * n + 2];
  int pr[n];
  ;
  int resid = -1;
  for (int i = (0); i < int((n)); ++i) {
    int cr = n;
    for (auto &x : rows[i]) {
      cr = min(cr, i + t.query(1, 0, nn - 1, x.first, x.second));
    }
    int whpr = -1;
    int sthidpr = cr - i + n;
    ;
    ;
    for (auto &x : l[sthidpr].s) {
      cout << x.l << ' ' << x.r << ' ' << x.val << '\n';
    };
    for (auto &x : rows[i]) {
      auto it = prev(l[sthidpr].s.lower_bound({x.first, 0, 0}));
      while (it != l[sthidpr].s.end() && it->l <= x.second) {
        if (it->val != -1) {
          if (it->r >= x.first) {
            whpr = it->val;
            break;
          }
        }
        ++it;
      }
      if (whpr != -1) break;
    }
    pr[i] = whpr;
    int put = cr + (n - i - 1);
    if (put < res) {
      res = put;
      resid = i;
    }
    int sthid = cr - i - 1 + n;
    ;
    for (auto &x : rows[i]) {
      t.modifymne(1, 0, nn - 1, x.first, x.second, cr - i - 1);
      l[sthid].insert(x.first, x.second, i);
    }
  }
  for (int i = (0); i < int((n)); ++i)
    ;
  ;
  cout << res << '\n';
  std::vector<int> resvec;
  while (resid != -1) {
    resvec.push_back(resid);
    resid = pr[resid];
  };
}
