#include <bits/stdc++.h>
using namespace std;
template <typename T>
void vout(T x) {
  cout << x << endl;
  exit(0);
}
const int inf = 1e9 + 1;
const long long INF = 1e18 + 1e2;
const int mod = 1e9 + 7;
bool ok(int n) { return n % 10 != 3 && n % 3 != 0; }
void solve() {
  int k;
  cin >> k;
  int res = -1;
  for (int candidate = 1;; candidate++) {
    if (ok(candidate)) k--;
    if (k == 0) {
      cout << candidate << endl;
      return;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int q = 1;
  cin >> q;
  while (q--) {
    solve();
  }
  return 0;
}
