#include <bits/stdc++.h>
using namespace std;
using cd = complex<double>;
mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
const long long N = 2e5 + 5;
long long ans[N];
struct pp {
  long long a, b, v;
} c[N];
bool cmp(pp i, pp j) { return i.b + i.a < j.b + j.a; }
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long q;
  cin >> q;
  while (q--) {
    long long n, m, sa = 0, sb = 0;
    cin >> n >> m;
    for (long long i = 1; i <= n; i++) {
      cin >> c[i].a >> c[i].b;
      c[i].v = i;
      sa += c[i].a;
      sb += c[i].b;
    }
    long long h = sa + n * m - sb, suma = 0, sumb = 0;
    h = max((long long)0, h);
    for (long long i = 1; i <= n; i++) {
      suma += min(c[i].a, m);
      sumb += min(c[i].b, m);
      c[i].a = min(c[i].a, m);
      c[i].b = min(c[i].b, m);
    }
    if (h % 2 == 0) {
      long long ga = h / 2, gb = n * m - ga;
      if (ga > suma)
        h = suma;
      else if (gb > sumb)
        h = n * m - sumb;
      else
        h = ga;
    } else {
      long long ga = 0, gb = 0;
      if (suma > sumb)
        ga = h / 2 + 1, gb = n * m - ga;
      else
        ga = h / 2, gb = n * m - ga;
      if (ga > suma)
        h = suma;
      else if (gb > sumb)
        h = n * m - sumb;
      else
        h = ga;
    }
    sort(c + 1, c + 1 + n, cmp);
    cout << abs((sa - h) - (sb - n * m + h)) << endl;
    for (long long i = 1; i <= n; i++) {
      if (h > c[i].a) {
        ans[c[i].v] = c[i].a;
        h -= c[i].a;
      } else {
        ans[c[i].v] = h;
        h = 0;
      }
    }
    for (long long i = 1; i <= n; i++) {
      cout << ans[i] << " " << m - ans[i] << endl;
    }
  }
}
