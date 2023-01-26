#include <bits/stdc++.h>
using namespace std;
template <typename T>
void umax(T &a, const T b) {
  if (a < b) a = b;
}
template <typename T>
void umin(T &a, const T b) {
  if (a > b) a = b;
}
void darkkcyan_orz() {
  long long s, n, k;
  cin >> s >> n >> k;
  if (s == k) {
    cout << ("YES") << '\n';
    return;
  }
  long long ans = s / (2 * k) * k;
  long long rm = s % (2 * k);
  ans += min(rm + 1, k);
  cout << (n + 1 <= ans ? "NO" : "YES") << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.exceptions(cin.failbit);
  cin.tie(0);
  cout << "";
  int T = 1;
  cin >> T;
  for (int tc = 0; tc < T; ++tc) {
    darkkcyan_orz();
  }
}
