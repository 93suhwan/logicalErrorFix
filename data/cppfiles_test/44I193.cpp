#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long long INF = 1e18 + 7;
const int N = 1e5 + 5;
long double pi = acos(-1);
void input() {
  if (fopen("k13n_"
            ".inp",
            "r")) {
    freopen(
        "k13n_"
        ".inp",
        "r", stdin);
    freopen(
        "k13n_"
        ".out",
        "w", stdout);
  }
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int t, c, d, a, b;
int main() {
  input();
  cin >> t;
  while (t--) {
    cin >> c >> d;
    if (c == 0 && d == 0) {
      cout << 0 << '\n';
    }
    if (abs(c - d) & 1) {
      cout << -1 << '\n';
    }
    if (c == d) {
      cout << 1 << '\n';
    } else {
      cout << 2 << '\n';
    }
  }
  return 0;
}
