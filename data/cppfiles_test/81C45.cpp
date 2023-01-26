#include <bits/stdc++.h>
using namespace std;
std::mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
inline int sj(int n) {
  unsigned long long x = rnd();
  x = x << 32 | rnd();
  return x % n + 1;
}
const int p = 998244353;
inline void inc(int &x, const int y) {
  if ((x += y) >= p) x -= p;
}
inline void dec(int &x, const int y) {
  if ((x -= y) < 0) x += p;
}
inline int ksm(int x, int y) {
  int r = 1;
  while (y) {
    if (y & 1) r = (long long)r * x % p;
    x = (long long)x * x % p;
    y >>= 1;
  }
  return r;
}
priority_queue<int> ONLYYFORRCOPYY;
priority_queue<int, vector<int>, greater<int>> ONLYYFORRCOPYY__;
const int N = 1e6 + 2, M = 4e6 + 2;
struct Q {
  int a, s;
  bool operator<(const Q &o) const {
    return max(a, s) < max(o.a, o.s) ||
           max(a, s) == max(o.a, o.s) && (s < o.s || s == o.s && a < o.a);
  }
};
Q a[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setiosflags(ios::fixed) << setprecision(15);
  int n, d, i, ans = 0;
  cin >> n >> d;
  for (i = 1; i <= n; i++) cin >> a[i].s >> a[i].a;
  sort(a + 1, a + n + 1);
  for (i = 1; i <= n; i++)
    if (d <= a[i].s) d = max(d, a[i].a), ++ans;
  cout << ans << endl;
}
