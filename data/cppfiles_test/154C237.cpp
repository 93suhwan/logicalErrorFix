#include <bits/stdc++.h>
using namespace std;
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << H;
  debug_out(T...);
}
constexpr int MAXN = 1e5 + 12;
constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9 + 1;
constexpr int LOG = 2e1 + 4;
constexpr int SQ = 32e1 + 10;
constexpr int ALP = 1e5;
int tc, x, y, z;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> tc;
  while (tc--) {
    cin >> x >> y >> z;
    bool ok = false;
    if (x == y && z % 2 == 0) {
      ok = true;
    }
    if (x == z && y % 2 == 0) {
      ok = true;
    }
    if (y == z && x % 2 == 0) {
      ok = true;
    }
    if (z - x == y) {
      ok = true;
    }
    if (z - y == x) {
      ok = true;
    }
    if (x - z == y) {
      ok = true;
    }
    if (x - y == z) {
      ok = true;
    }
    if (y - x == z) {
      ok = true;
    }
    if (y - z == x) {
      ok = true;
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
  return 0;
}
