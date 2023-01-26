#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
string to_string(pair<A, B> p);
string to_string(const string &s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) res += static_cast<char>('0' + v[i]);
  return res;
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) res += ", ";
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
struct SegmentTree {
  int n;
  vector<int> cnt[2];
  explicit SegmentTree(int n) : n(n) {
    cnt[0].assign(n << 2 | 1, 0);
    cnt[1].assign(n << 2 | 1, 0);
  }
  void Update(int node, int l, int r, int x, int zero, int one) {
    if (x < l || x > r) return;
    if (l == r) {
      cnt[0][node] += zero;
      cnt[1][node] += one;
      return;
    }
    int m = l + r >> 1;
    Update(node << 1, l, m, x, zero, one);
    Update(node << 1 | 1, m + 1, r, x, zero, one);
    cnt[0][node] = cnt[0][node << 1] + cnt[0][node << 1 | 1];
    cnt[1][node] = cnt[1][node << 1] + cnt[1][node << 1 | 1];
  }
  int GetMin(int node, int l, int r, int zero, int one) {
    if (l == r) {
      return min(zero + cnt[0][node], one);
    }
    int m = l + r >> 1;
    int res = 0;
    auto cur_zero = zero + cnt[0][node << 1];
    auto cur_one = one + cnt[1][node << 1];
    res = max(res, min(cur_zero, cur_one));
    if (cur_zero > cur_one) {
      res = max(res, GetMin(node << 1, l, m, zero, cur_one));
    } else {
      res = max(res, GetMin(node << 1 | 1, m + 1, r, cur_zero, one));
    }
    return res;
  }
};
struct Point {
  int x, y, c;
};
string to_string(Point u) {
  return "{" + to_string(u.x) + ", " + to_string(u.y) + "," + to_string(u.c) +
         "}";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<Point> a(n);
  for (auto &u : a) {
    cin >> u.x >> u.y >> u.c;
    u.c--;
  }
  int res = 0;
  vector<int> id(3);
  iota(id.begin(), id.end(), 0);
  auto Normalize = [&](vector<int> &a) {
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
  };
  auto Solve = [&](vector<Point> b) {
    vector<int> valx, valy;
    for (auto &p : b) {
      valx.push_back(p.x);
      valy.push_back(p.y);
    }
    valx.push_back(*min_element(valx.begin(), valx.end()) - 1);
    valx.push_back(*max_element(valx.begin(), valx.end()) + 1);
    valy.push_back(*min_element(valy.begin(), valy.end()) - 1);
    valy.push_back(*max_element(valy.begin(), valy.end()) + 1);
    Normalize(valx);
    Normalize(valy);
    for (auto &p : b) {
      p.x = lower_bound(valx.begin(), valx.end(), p.x) - valx.begin();
      p.y = lower_bound(valy.begin(), valy.end(), p.y) - valy.begin();
    }
    sort(b.begin(), b.end(),
         [&](const Point &u, const Point &v) { return u.x < v.x; });
    int num = n / 3;
    int cur = 0;
    int sz = valy.size();
    SegmentTree t(sz);
    42;
    for (auto &x : valx) {
      while (cur < n && b[cur].x <= x) {
        if (b[cur].c == 0) {
          num--;
        } else if (b[cur].c == 1) {
          t.Update(1, 0, sz - 1, b[cur].y, 1, 0);
        } else if (b[cur].c == 2) {
          t.Update(1, 0, sz - 1, b[cur].y, 0, 1);
        } else {
          exit(1);
        }
        cur++;
      }
      42;
      res = max(res, min(num, t.GetMin(1, 0, sz - 1, 0, 0)));
    }
  };
  while (1) {
    for (int x = 0; x < 2; x++) {
      for (int y = 0; y < 2; y++) {
        for (int z = 0; z < 2; z++) {
          auto b = a;
          for (auto &p : b) {
            if (x) p.x = -p.x;
            if (y) p.y = -p.y;
            if (z) swap(p.x, p.y);
            p.c = id[p.c];
          }
          Solve(b);
        }
      }
    }
    if (!next_permutation(id.begin(), id.end())) break;
  }
  cout << res * 3 << '\n';
  return 0;
}
