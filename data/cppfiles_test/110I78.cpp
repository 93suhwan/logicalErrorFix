#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

// Template {{{
#define REP(n) for (int _=0; _<(n); _++)
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
 
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

namespace std {
  template<class Fun>
  class y_combinator_result {
    Fun fun_;
  public:
    template<class T>
    explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
   
    template<class ...Args>
    decltype(auto) operator()(Args &&...args) {
      return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
  };
   
  template<class Fun>
  decltype(auto) y_combinator(Fun &&fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
  }
} // namespace std

#define DEBUG(x) cerr << #x << ": " << x << '\n'
template<typename A, typename B> 
ostream& operator<<(ostream &os, const pair<A, B> &p) { 
  return os << '(' << p.first << ", " << p.second << ')'; 
}
template<typename T_container, 
  typename T = typename enable_if<!is_same<T_container, string>::value, 
  typename T_container::value_type>::type> 
ostream& operator<<(ostream &os, const T_container &v) { 
  os << '['; string sep; 
  for (const T &x : v) 
    os << sep << x, sep = ", "; 
  return os << ']'; 
}
// }}}

struct Point {
  int x, y, c;
  bool operator<(const Point& rhs) const {
    if (y != rhs.y) return y < rhs.y;
    else return c < rhs.c;
  }
};

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n; cin >> n;
  vector<Point> pts(n);
  for (auto& p: pts) {
    cin >> p.x >> p.y >> p.c;
    p.c--;
  }

  auto compress_points = [&]() -> int {
    set<int> s;
    for (auto& p: pts) {
      s.insert(p.x);
      s.insert(p.y);
    }
    map<int,int> compress;
    int pt = 0;
    for (int x: s) {
      compress[x] = pt++;
    }
    for (auto& p: pts) {
      p.x = compress[p.x];
      p.y = compress[p.y];
    }
    return pt;
  };
  int pt = compress_points();

  auto check_partition = [&](const vector<Point>& ps, int k) -> bool {
    // Take first k of color 0
    // For the remaining color 1/2 points, go left to right and take first k of color 1
    assert(sz(ps) == n);
    vector<int> cnt1(pt, 0), cnt2(pt, 0);
    for (auto p: ps) {
      if (p.c == 1) cnt1[p.x]++;
      else if (p.c == 2) cnt2[p.x]++;
    }
    for (int i = 0, c0 = 0; c0 < k && i < n; i++) {
      if (ps[i].c == 0) c0++;
      else if (ps[i].c == 1) cnt1[ps[i].x]--;
      else if (ps[i].c == 2) cnt2[ps[i].x]--;
    }
    int i = 0, c1 = 0;
    for (; i < pt; i++) {
      c1 += cnt1[i];
      if (c1 >= k) break;
    }
    int c2 = accumulate(cnt2.begin()+i, cnt2.end(), 0);
    return c2 >= k;
  };

  auto check_partition_2 = [&](const vector<Point>& ps, int k) -> bool {
    //go in increasing y, take first 0/1/2
    int cnt[3] = {0, 0, 0};
    int mode = 0;
    for (auto p: ps) {
      if (mode > 2) break;
      if (p.c == mode) cnt[mode]++;
      if (cnt[mode] >= k) mode++;
    }
    return mode > 2;
  };

  int ans = 0;
  REP(4) {
    auto ps = pts;
    vector<int> colors = {0, 1, 2};
    do {
      F0R(i, n) {
        ps[i].c = colors[pts[i].c];
      }
      sort(all(pts)); // Sort according to comparator
      int lo = 0, hi = n/3+1;
      while (lo + 1 < hi) {
        int mid = (lo+hi)/2;
        bool poss = check_partition(ps, mid) || check_partition_2(ps, mid);
        (poss ? lo : hi) = mid;
      }
      ckmax(ans, lo);
    } while (next_permutation(all(colors)));

    // rotate
    for (auto& p: pts) {
      tie(p.x, p.y) = make_tuple(pt-1-p.y, p.x);
    }
  }
  cout << 3*ans << '\n';
}
