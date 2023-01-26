#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,sse3,sse4,popcnt,abm,mmx")
#pragma comment(linker, "/STACK:64777216")
using namespace std;
const int INF = int(1e9);
const long long INF64 = long long(1e18);
const long double PI = acosl(long double(-1));
const long double EPS = 1e-9;
template <typename T>
inline T sqr(const T& first) {
  return first * first;
}
template <typename T>
inline T abs(const T& first) {
  return first > 0 ? first : -first;
}
inline bool inside(int first, int second, int n, int m) {
  return first >= 1 && first <= n && second >= 1 && second <= m;
}
inline int rnd() { return abs(rand() ^ (rand() << 15)); }
inline int rnd(int n) {
  assert(n > 0);
  return rnd() % n;
}
inline int rnd(int lf, int rg) { return lf + rnd(rg - lf + 1); }
inline long long rndLL() { return rnd() * 1LL * rnd() + rnd(); }
const int dx[4] = {-1, 0, +1, 0};
const int dy[4] = {0, +1, 0, -1};
const int dx8[8] = {-1, -1, 0, +1, +1, +1, 0, -1};
const int dy8[8] = {0, +1, +1, +1, 0, -1, -1, -1};
const int N = int(2e5) + 555;
int n;
long long a[N];
void gen() {}
bool read() {
  if (!(cin >> n)) return false;
  for (int i = 1; i <= int(n); i++) assert(cin >> a[i]);
  return true;
}
long long inter(long long a1, long long b1, long long a2, long long b2) {
  long long lf = max(a1, a2);
  long long rg = min(b1, b2);
  return max(0LL, rg - lf + 1);
}
void solve() {
  long long ans = 0;
  for (int i = 1; i + 1 <= n; i += 2) {
    ans += min(a[i], a[i + 1]);
  }
  for (int i = 1; i + 3 <= n; i += 2) {
    long long bal = 0;
    long long mn = a[i + 1];
    bal += a[i + 2];
    if (mn > a[i]) continue;
    for (int j = i + 3; j <= n; j += 2) {
      ans += inter(bal, bal + (a[i] - mn), 1, a[j]);
      bal -= a[j];
      if (bal < 0) {
        mn += -bal;
        bal = 0;
      }
      if (mn > a[i]) break;
      bal += a[j + 1];
    }
  }
  cout << ans << endl;
}
long double gett() { return long double(clock()) / CLOCKS_PER_SEC; }
int main() {
  cout << setprecision(15) << fixed;
  cerr << setprecision(15) << fixed;
  int T = 1;
  srand(int(time(NULL)));
  for (int i = 0; i < int(T); i++) {
    assert(read());
    solve();
  }
  return 0;
}
