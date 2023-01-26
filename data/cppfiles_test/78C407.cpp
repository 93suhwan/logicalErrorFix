#include <bits/stdc++.h>
using namespace std;
template <class T>
T gcd(T a, T b) {
  return b == 0 ? a : gcd(b, a % b);
}
const int INF = 0x3f3f3f3f;
void solve() {
  int a, b;
  cin >> a >> b;
  cout << b % max(a, b / 2 + 1) << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
