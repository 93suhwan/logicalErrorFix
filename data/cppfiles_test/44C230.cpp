#include <bits/stdc++.h>
using namespace std;
template <class T>
void chmax(T& a, const T& b) {
  a = max(a, b);
}
template <class T>
void chmin(T& a, const T& b) {
  a = min(a, b);
}
using ll = long long;
using P = pair<int, int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int c, d;
    cin >> c >> d;
    int ans = c == d ? (c == 0 ? 0 : 1) : c % 2 == d % 2 ? 2 : -1;
    cout << ans << '\n';
  }
}
