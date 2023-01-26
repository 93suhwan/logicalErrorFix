#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
const ll RANDOM =
    chrono::high_resolution_clock::now().time_since_epoch().count();
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
void file() {
  {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
  };
  if (fopen(""
            ".inp",
            "r")) {
    freopen(
        ""
        ".inp",
        "r", stdin);
    freopen(
        ""
        ".out",
        "w", stdout);
  }
}
void solve() {
  int n;
  cin >> n;
  cout << (n + 1) / 10 << '\n';
}
int main() {
  file();
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
