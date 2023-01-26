#include <bits/stdc++.h>
using namespace std;
template <class A, class B>
ostream& operator<<(ostream& out, const pair<A, B>& a) {
  return out << "(" << a.first << ", " << a.second << ")";
}
template <class A>
ostream& operator<<(ostream& out, const vector<A>& v) {
  out << "[";
  for (int i = 0; i < int(int(v.size())); i++) {
    if (i) out << ", ";
    out << v[i];
  }
  return out << "]";
}
mt19937 rnd(time(NULL));
const int INF = int(1e9);
const long long INF64 = long long(1e18);
const int MOD = int(1e9) + 7;
const long double EPS = 1e-9;
const long double PI = acos(-1.0);
const int N = 200 * 1000 + 13;
int n, m;
pair<int, int> a[N];
bool read() {
  if (scanf("%d%d", &n, &m) != 2) return false;
  for (int i = 0; i < int(n); i++) scanf("%d%d", &a[i].first, &a[i].second);
  return true;
}
pair<int, int> b[N];
void solve() {
  long long l = 0, r = 0;
  for (int i = 0; i < int(n); i++) {
    int mn = max(0, a[i].first - m) - (a[i].second - max(0, m - a[i].first));
    int mx =
        -(max(0, a[i].second - m) - (a[i].first - max(0, m - a[i].second)));
    l += mn, r += mx;
  }
  long long ans;
  if (r <= 0)
    ans = r;
  else if (l >= 0)
    ans = l;
  else
    ans = r & 1;
  for (int i = 0; i < int(n); i++) {
    int mn = max(0, a[i].first - m) - (a[i].second - max(0, m - a[i].first));
    int mx =
        -(max(0, a[i].second - m) - (a[i].first - max(0, m - a[i].second)));
    long long nl = l - mn, nr = r - mx;
    long long first = 0;
    bool fl = false;
    for (long long tmp : {long long(mn), long long(mx), -nl + ans, -nr + ans}) {
      for (long long opt = tmp - 1; opt <= tmp + 1; ++opt) {
        if (opt < mn || opt > mx || (opt & 1) != (mx & 1)) continue;
        if (nl <= ans - opt && ans - opt <= nr) {
          fl = true;
          first = opt;
        }
      }
    }
    assert(fl);
    ans -= first;
    l = nl, r = nr;
    first -= a[i].first - a[i].second;
    assert((m + first) % 2 == 0);
    printf("%lld %lld\n", m - (m + first) / 2, (m + first) / 2);
  }
}
int main() {
  cerr.precision(15);
  cout.precision(15);
  cerr << fixed;
  cout << fixed;
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    read();
    solve();
  }
}
