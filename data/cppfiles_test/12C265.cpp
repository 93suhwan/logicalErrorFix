#include <bits/stdc++.h>
using namespace std;
void input() {
  if (fopen("BACHO.inp", "r")) {
    freopen("BACHO.inp", "r", stdin);
    freopen("BACHO.out", "w", stdout);
  } else if (fopen("BACHO.in", "r")) {
    freopen("BACHO.in", "r", stdin);
    freopen("BACHO.out", "w", stdout);
  } else if (fopen("tenbai"
                   ".inp",
                   "r")) {
    freopen(
        "tenbai"
        ".inp",
        "r", stdin);
    freopen(
        "tenbai"
        ".out",
        "w", stdout);
  } else if (fopen("tenbai"
                   ".in",
                   "r")) {
    freopen(
        "tenbai"
        ".in",
        "r", stdin);
    freopen(
        "tenbai"
        ".out",
        "w", stdout);
  }
}
void fastio() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}
const int maxn = 2e5 + 5, mod = 1e9 + 7, oo = 1061109567, maxv = 1e9 + 5;
const double pi = atan2(0, -1);
int t, n, m, k;
bool check(int n, int m, int k) {
  if (k > n * (m / 2)) return false;
  if (n % 2 == 0) {
    if (k % 2 == 1) return false;
  }
  if (n % 2 == 1) {
    if (k < m / 2) return false;
    k -= m / 2;
    if (k % 2 == 1) return false;
  }
  return true;
}
int32_t main() {
  input();
  fastio();
  cin >> t;
  while (t--) {
    cin >> n >> m >> k;
    if (check(n, m, k))
      cout << "YES"
           << "\n";
    else
      cout << "NO"
           << "\n";
  }
  return 0;
}
