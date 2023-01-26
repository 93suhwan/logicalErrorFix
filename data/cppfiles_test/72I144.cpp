#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:2000000000")
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using ui32 = unsigned int;
constexpr ll INFLL = 1e18;
class Solver {
 public:
  int response(int x, int y) {
    int x1 = 8;
    int y1 = 133;
    int x2 = 20;
    int y2 = 10000;
    if (!(x < x1 || x > x2 || y < y1 || y > y2)) {
      ;
      assert(x < x1 || x > x2 || y < y1 || y > y2);
    };
    return min(abs(x - x1), abs(x - x2)) + min(abs(y - y1), abs(y - y2));
  }
  int ask(int x, int y) {
    if (cache_.find({x, y}) != cache_.end()) {
      return cache_[{x, y}];
    }
    ++it_;
    if (!(it_ <= 40)) {
      ;
      assert(it_ <= 40);
    };
    cout << "? " << x << " " << y << endl;
    int res = 0;
    cin >> res;
    if (!(res != -1)) {
      ;
      assert(res != -1);
    };
    cache_[{x, y}] = res;
    return res;
  }
  void main() {
    int n = 1e9;
    int d1 = ask(1, 1);
    int d2 = ask(1, n);
    int d3 = ask(n, n);
    int l = 0, r = n + 1;
    while (r > l + 1) {
      int m = (l + r) / 2;
      int res = ask(1, m);
      if (res > d1) {
        r = m;
      } else {
        l = m;
      }
    }
    r = (r + 1) / 2;
    int hor_dist = ask(1, r);
    int vert_dist = ask(hor_dist + 1, 1);
    int hor_len = n - hor_dist - ask(n, r);
    int ver_len = n - vert_dist - ask(hor_dist + 1, n);
    cout << "! " << hor_dist + 1 << " " << vert_dist + 1 << " "
         << hor_dist + hor_len << " " << vert_dist + ver_len << endl;
  }
  int it_;
  map<pair<int, int>, int> cache_;
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  while (t--) {
    Solver{}.main();
  }
  return 0;
}
