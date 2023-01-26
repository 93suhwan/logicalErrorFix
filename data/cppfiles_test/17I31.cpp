#include <bits/stdc++.h>
using namespace std;
template <typename T>
void setmax(T& x, T y) {
  x = max(x, y);
}
template <typename T>
void setmin(T& x, T y) {
  x = min(x, y);
}
template <typename T>
void print(const T& a, ostream& out) {
  for (auto i : a) out << i << ' ';
  out << endl;
}
const double PI = acos(-1.0);
const long long INF = 1e9 + 47;
const long long LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int mod = 1e9 + 7, N = 1 << 17;
int r[N][5];
int best[100];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    memset(best, -1, sizeof(best));
    for (int i = (0); i < (n); ++i) {
      for (int j = (0); j < (5); ++j) cin >> r[i][j];
      for (int mask = (0); mask < (1 << 5); ++mask) {
        if (__builtin_popcount(mask) != 3) continue;
        if (best[mask] == -1) {
          best[mask] = i;
          continue;
        }
        bool ok = 1;
        for (int j = (0); j < (5); ++j)
          if (mask & (1 << j)) ok &= (r[i][j] < r[best[mask]][j]);
        if (ok) best[mask] = i;
      }
    }
    int ans = -1;
    for (int mask = (0); mask < (1 << 5); ++mask) {
      if (__builtin_popcount(mask) != 3) continue;
      if (best[mask] == -1) continue;
      bool ok = 1;
      for (int i = (0); i < (n); ++i) {
        int cnt = 0;
        for (int j = (0); j < (5); ++j) cnt += r[best[mask]][j] <= r[i][j];
        ok &= (cnt > 2);
      }
      if (ok) ans = best[mask] + 1;
    }
    cout << ans << "\n";
  }
  cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
  return 0;
}
