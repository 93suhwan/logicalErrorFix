#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
inline ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
  return os << "(" << p.first << ", " << p.second << ")";
}
template <typename T, size_t N>
inline ostream &operator<<(ostream &os, const array<T, N> &a) {
  os << "[";
  int cnt = 0;
  for (auto &val : a) {
    if (cnt++) os << ", ";
    os << val;
  }
  os << "]";
  return os;
}
template <typename T>
inline ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "[";
  int cnt = 0;
  for (auto &val : v) {
    if (cnt++) os << ", ";
    os << val;
  }
  return os << "]";
}
template <typename T>
inline ostream &operator<<(ostream &os, const set<T> &v) {
  os << "{";
  int cnt = 0;
  for (auto &val : v) {
    if (cnt++) os << ", ";
    os << val;
  }
  return os << "}";
}
template <typename T>
inline ostream &operator<<(ostream &os, const unordered_set<T> &v) {
  os << "{";
  int cnt = 0;
  for (auto &val : v) {
    if (cnt++) os << ", ";
    os << val;
  }
  return os << "}";
}
template <typename T>
inline ostream &operator<<(ostream &os, const multiset<T> &v) {
  os << "{";
  int cnt = 0;
  for (auto &val : v) {
    if (cnt++) os << ", ";
    os << val;
  }
  return os << "}";
}
template <typename T1, typename T2>
inline ostream &operator<<(ostream &os, const map<T1, T2> &v) {
  os << "[";
  int cnt = 0;
  for (auto &val : v) {
    if (cnt++) os << ", ";
    os << val;
  }
  return os << "]";
}
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
  cerr << name << ": " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args) {
  const char *comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << ": " << arg1 << " |";
  __f(comma + 1, args...);
}
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<long long>;
using vvi = vector<vector<int>>;
using vs = vector<string>;
using vb = vector<bool>;
using vd = vector<double>;
using vvb = vector<vector<bool>>;
using vvc = vector<vector<char>>;
using vc = vector<char>;
using si = set<int>;
using mpii = map<int, int>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, 1, -1};
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <class T>
inline bool umin(T &a, const T b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
inline bool umax(T &a, const T b) {
  return a < b ? a = b, 1 : 0;
}
struct SegmentTree {
  const static int maxn = 10004 << 2;
  int L[maxn];
  int R[maxn];
  int tag[maxn];
  int mi[maxn];
  int ma[maxn];
  ll sum[maxn];
  inline int rangeSize(int p) { return R[p] - L[p] + 1; }
  void build(int p, int l, int r) {
    L[p] = l, R[p] = r, tag[p] = 0;
    if (l == r) {
      sum[p] = mi[p] = ma[p] = 0;
    } else {
      int mid = (l + r) >> 1;
      build((p << 1), l, mid);
      build(((p << 1) | 1), mid + 1, r);
      pull(p);
    }
  }
  void tagNode(int p, int newVal) {
    tag[p] += newVal;
    mi[p] += newVal;
    ma[p] += newVal;
    sum[p] += 1LL * rangeSize(p) * newVal;
  }
  void push(int p) {
    assert(L[p] != R[p]);
    if (tag[p] > 0) {
      tagNode((p << 1), tag[p]);
      tagNode(((p << 1) | 1), tag[p]);
    }
    tag[p] = 0;
  }
  void pull(int p) {
    assert(L[p] != R[p]);
    mi[p] = min(mi[(p << 1)], mi[((p << 1) | 1)]);
    ma[p] = max(ma[(p << 1)], ma[((p << 1) | 1)]);
    sum[p] = sum[(p << 1)] + sum[((p << 1) | 1)];
  }
  void rangeUpdate(int p, int l, int r, int newValue) {
    if (L[p] == R[p]) {
      mi[p] += newValue;
      ma[p] += newValue;
      sum[p] += newValue;
    } else if (L[p] == l && R[p] == r) {
      tagNode(p, newValue);
    } else {
      push(p);
      int mid = (L[p] + R[p]) >> 1;
      if (r <= mid)
        rangeUpdate((p << 1), l, r, newValue);
      else if (l > mid)
        rangeUpdate(((p << 1) | 1), l, r, newValue);
      else {
        rangeUpdate((p << 1), l, mid, newValue);
        rangeUpdate(((p << 1) | 1), mid + 1, r, newValue);
      }
      pull(p);
    }
  }
  int query(int p, int l, int r) {
    if (L[p] == R[p]) {
      return ma[p];
    } else if (L[p] == l && R[p] == r) {
      return ma[p];
    } else {
      push(p);
      int mid = (L[p] + R[p]) >> 1;
      if (r <= mid)
        return query((p << 1), l, r);
      else if (l > mid)
        return query(((p << 1) | 1), l, r);
      else {
        return max(query((p << 1), l, mid), query(((p << 1) | 1), mid + 1, r));
      }
    }
  }
} st;
int n, m;
void solve() {
  int cnt = n * m;
  vi pre(n, -1);
  vector<array<int, 3>> segments;
  for (int i = 0; i < (cnt); i++) {
    int color;
    cin >> color;
    color--;
    if (pre[color] != -1) {
      segments.push_back({pre[color], i, color});
    }
    pre[color] = i;
  }
  sort((segments).begin(), (segments).end(),
       [&](array<int, 3> &lh, array<int, 3> &rh) {
         int x = lh[1] - lh[0];
         int y = rh[1] - rh[0];
         if (x != y) return x < y;
         return lh[0] < rh[0];
       });
  int lim = (n % (m - 1) == 0 ? n / (m - 1) : n / (m - 1) + 1);
  vector<pii> ans(n, {-1, -1});
  st.build(1, 0, cnt);
  for (auto &seg : segments) {
    auto [u, v, color] = seg;
    if (ans[color].first != -1) continue;
    if (st.query(1, u, v) >= lim) continue;
    ans[color] = {u, v};
    st.rangeUpdate(1, u, v, 1);
  }
  for (auto [u, v] : ans) cout << u + 1 << " " << v + 1 << endl;
}
void solve(int _cas) { solve(); }
int main() {
  srand(time(NULL));
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL), cout.precision(12);
  while (cin >> n >> m) solve(1);
}
