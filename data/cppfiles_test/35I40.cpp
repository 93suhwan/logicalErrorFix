#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-10, pi = 3.1415926535898;
const int mod = 1e9 + 7, maxn = 1e6 + 10;
int T, n, m, k, x, y, a[maxn], b[maxn];
char st[maxn];
struct P {
  int x, y;
  P(int X, int Y) : x(X), y(Y) {}
  bool operator<(const P& a) const {
    if (x == a.x) return y < a.y;
    return x < a.x;
  }
} pp(0, 0);
std::vector<P> v[maxn], p[maxn];
std::vector<int> tmp[maxn];
int main(int argc, char const* argv[]) {
  long long ans = 0;
  for (int i = 2; i < maxn; ++i) {
    if (v[i].empty()) {
      for (int j = i; j < maxn; j += i) {
        k = j;
        x = 0;
        while (k % i == 0) {
          k /= i;
          ++x;
        }
        v[j].emplace_back(i, x);
      }
    }
  }
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    b[i] = n;
  }
  scanf("%s", st + 1);
  for (int i = n; i >= 1; --i) {
    if (st[i] == '*') {
      for (P j : v[a[i]]) {
        p[j.x].emplace_back(i, j.y);
      }
    } else {
      for (P j : v[a[i]]) {
        p[j.x].emplace_back(i, -j.y);
      }
    }
  }
  for (int i = 2; i < maxn; ++i) {
    if (!p[i].empty()) {
      p[i].emplace_back(0, 0);
      int su = 0;
      stack<P> s;
      s.push(P(n + 1, 0));
      x = n + 1;
      for (auto j : p[i]) {
        if (s.top().x != n + 1) {
          tmp[j.x + 1].push_back(y);
          tmp[x + 1].push_back(-y);
        }
        if (!j.x and !j.y) {
          break;
        }
        su += j.y;
        if (j.y < 0) {
          s.push(P(j.x, su));
          y = j.x - 1;
          x = j.x;
          continue;
        }
        pp = s.top();
        while (s.top().x != n + 1 and su >= s.top().y) {
          pp = s.top();
          s.pop();
        }
        if (s.top().x == n + 1 and su >= 0) {
          pp = s.top();
        }
        y = pp.x - 1;
        x = j.x;
        if (s.top().x != pp.x) {
          s.push(pp);
        }
        s.push(P(j.x, su));
      }
    }
  }
  multiset<int> ms;
  ms.insert(n);
  for (int i = 1; i <= n; ++i) {
    for (int j : tmp[i]) {
      if (j < 0) {
        auto it = ms.find(-j);
        ms.erase(it);
      } else {
        ms.insert(j);
      }
    }
    b[i] = min(b[i], *ms.begin());
  }
  for (int i = 1; i <= n; ++i) {
    ans += b[i] + 1 - i;
    printf("%d %d\n", i, b[i]);
  }
  printf("%lld\n", ans);
  return 0;
}
