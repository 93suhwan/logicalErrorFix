#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const unsigned gen_seed =
    std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);
int badrows = 0;
int badcols = 0;
int freecols, freerows;
class Line {
 public:
  Line(){};
  std::vector<int> t = std::vector<int>(2, 0);
  set<std::pair<long long, long long> > a;
  void set(long long pos, long long val) {
    auto it = a.lower_bound(make_pair(pos, 0));
    if (it != a.end() && it->first == pos) {
      t[(pos + it->second) % 2]--;
      a.erase(it);
    }
    t[(pos + val) % 2]++;
    a.insert(make_pair(pos, val));
  }
  void clear(long long pos) {
    auto it = a.lower_bound(make_pair(pos, 0));
    if (it != a.end() && it->first == pos) {
      t[(pos + it->second) % 2]--;
      a.erase(it);
    }
  }
  int bad() {
    if (t[0] > 0 && t[1] > 0)
      return 1;
    else
      return 0;
  }
  int free() {
    if (t[0] + t[1] == 0)
      return 1;
    else
      return 0;
  }
};
int main() {
  int n, m, q;
  scanf("%d %d %d", &n, &m, &q);
  vector<Line> rows(n);
  vector<Line> cols(m);
  Line mb;
  std::vector<long long> d2(1, 1);
  for (int i = 0; i < 1000500; i++) d2.push_back(d2.back() * 2 % mod);
  freerows = n;
  freecols = m;
  for (int idt = 0; idt < q; idt++) {
    int x, y, v;
    scanf("%d %d %d", &x, &y, &v);
    x--;
    y--;
    long long xy = long long(x) * (2 * m + 1) + y;
    freerows -= rows[x].free();
    badrows -= rows[x].bad();
    freecols -= cols[y].free();
    badcols -= cols[y].bad();
    if (v == -1) {
      rows[x].clear(y);
      cols[y].clear(x);
      mb.clear(xy);
    } else {
      rows[x].set(y, v);
      cols[y].set(x, v);
      mb.set(xy, v);
    }
    freerows += rows[x].free();
    badrows += rows[x].bad();
    freecols += cols[y].free();
    badcols += cols[y].bad();
    long long ans = 0;
    if (badcols == 0) ans += d2[freecols];
    if (badrows == 0) ans += d2[freerows];
    if (mb.bad() == 0) ans += mod - 1;
    if (mb.free()) ans += mod - 1;
    ans %= mod;
    printf("%lld\n", ans);
  }
}
