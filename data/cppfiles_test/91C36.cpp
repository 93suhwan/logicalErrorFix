#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
using namespace std;
const long long mod = 998244353;
inline long long pw(long long x, long long y) {
  long long r = 1;
  while (y) {
    if (y & 1) r = r * x % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return r;
}
template <class T1, class T2>
inline const pair<T1, T2> operator+(const pair<T1, T2> &x,
                                    const pair<T1, T2> &y) {
  pair<T1, T2> z;
  z.first = x.first + y.first;
  z.second = x.second + y.second;
  return z;
}
template <class T1, class T2>
inline const pair<T1, T2> operator-(const pair<T1, T2> &x,
                                    const pair<T1, T2> &y) {
  pair<T1, T2> z;
  z.first = x.first - y.first;
  z.second = x.second - y.second;
  return z;
}
int n, a[100010];
vector<pair<int, int> > b, c;
long long ans;
inline pair<int, int> calc(int x, int y) {
  if (x <= y) return make_pair(x, 0);
  int z = (x - 1) / y + 1;
  return make_pair(x / z, z - 1);
}
void add(int x, int y) {
  if (!b.empty() && b.back().first == x) {
    b.back().second += y;
  } else {
    b.emplace_back(make_pair(x, y));
  }
}
void work() {
  cin >> n;
  ans = 0;
  for (register int i = 1; i <= n; i++) cin >> a[i];
  b.clear();
  c.clear();
  for (register int x = n; x >= 1; x--) {
    b.clear();
    pair<int, int> res;
    for (pair<int, int> i : c) {
      res = calc(a[x], i.first);
      add(res.first, i.second);
      {
        ans = ((ans + (long long)i.second * res.second % mod * x) % mod + mod) %
              mod;
      };
    }
    add(a[x], 1);
    c = b;
  }
  cout << ans << endl;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) work();
  return 0;
}
