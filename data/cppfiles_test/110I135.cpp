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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Point {
  int x, y, c, oc;
};

int solve(const vector<Point> pts, int n, int X, int Y) {
  int pt = Y;

  vector<int> cnt1(pt, 0), cnt2(pt, 0);
  auto check_partition = [&](const vector<vector<Point>>& ms, int k) -> bool {
    fill(all(cnt1), 0); fill(all(cnt2), 0);
    for (int y = 0; y < pt; y++) {
      for (const auto& p: ms[y]) {
        if (p.c == 1) cnt1[p.x]++;
        else if (p.c == 2) cnt2[p.x]++;
      }
    }
    int c0 = 0;
    for (int y = 0; y < pt; y++) {
      for (const auto& p: ms[y]) {
        if (p.c == 0) c0++;
        else if (p.c == 1) cnt1[p.x]--;
        else if (p.c == 2) cnt2[p.x]--;
      }
      if (c0 >= k) break;
    }
    int i = 0, c1 = 0;
    for (; i < pt; i++) {
      c1 += cnt1[i];
      if (c1 >= k) break;
    }
    int c2 = 0;
    for (int j = i+1; j < pt; j++) c2 += cnt2[j];
    return c2 >= k;
  };

  auto check_partition_2 = [&](const vector<vector<Point>>& ms, int k) -> bool {
    //go in increasing y, take first 0/1/2
    int cnt[3] = {0, 0, 0};
    int mode = 0;
    for (int y = 0; y < pt; y++) {
      if (mode > 2) break;
      for (const auto& p: ms[y]) {
        if (p.c == mode) cnt[mode]++;
      }
      if (cnt[mode] >= k) mode++;
    }
    return mode > 2;
  };

  vector<vector<Point>> ms(pt);
  for (const auto& p: pts) ms[p.y].push_back(p);

  int ans = 0;
  vector<int> colors = {0, 1, 2};
  do {
    for (int y = 0; y < pt; y++) {
      for (auto& p: ms[y]) {
        p.c = colors[p.oc];
      }
    }
    int lo = 0, hi = n/3+1;
    while (lo + 1 < hi) {
      int mid = (lo+hi)/2;
      bool poss = check_partition(ms, mid) || check_partition_2(ms, mid);
      //bool poss = check_partition_2(ms, mid);
      //bool poss = false;
      (poss ? lo : hi) = mid;
    }
    ckmax(ans, lo);
  } while (next_permutation(all(colors)));
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n; cin >> n;
  vector<Point> pts(n);
  for (auto& p: pts) {
    cin >> p.x >> p.y >> p.c;
    p.c--;
    p.oc = p.c;
  }

  //int n = 99999;
  //vector<Point> pts;
  //F0R(i, 3) {
  //  REP(n/3) {
  //      int x = rng() % 2000000000 - 1000000000;
  //      int y = rng() % 2000000000 - 1000000000;
  //      pts.push_back({x, y, i, i});
  //  }
  //}

  auto compress_points = [&]() -> void {
    vector<int> vx, vy;
    for (auto& p: pts) {
      vx.push_back(p.x);
      vy.push_back(p.y);
    }
    sort(all(vx)); vx.erase(unique(all(vx)),vx.end());
    sort(all(vy)); vy.erase(unique(all(vy)),vy.end());
    map<int,int> compressX, compressY;
    int ptX = 0;
    for (int x: vx) {
      compressX[x] = ptX++;
    }
    int ptY = 0;
    for (int y: vy) {
      compressY[y] = ptY++;
    }
    for (auto& p: pts) {
      p.x = compressX[p.x];
      p.y = compressY[p.y];
    }
  };
  compress_points();

  /*
  F0R(i, 3) {
    for (auto p: pts) {
      if (p.c == i) {
        printf("(%d, %d),", p.x, p.y);
      }
    }
    cout << endl;
  }
  */

  int ans = 0;
  REP(2) {
    int X = 0, Y = 0;
    for (auto p: pts) {
      ckmax(X, p.x+1);
      ckmax(Y, p.y+1);
    }
    REP(2) {
      ckmax(ans, solve(pts, n, X, Y));

      // flip horizontally
      for (auto& p: pts) {
        p.x = X-1-p.x;
      }
    }
    //transpose x and y
    for (auto& p: pts) {
      swap(p.x, p.y);
    }
  }
  cout << 3*ans << '\n';
}
