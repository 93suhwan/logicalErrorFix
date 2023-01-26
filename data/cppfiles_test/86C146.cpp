#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U, typename R>
inline R amin(T x, U y) {
  if (y < x) return y;
  return x;
}
template <typename T, typename U, typename R>
inline R amax(T x, U y) {
  if (x < y) return y;
  return x;
}
template <typename T, typename U, typename R>
inline R binpow(T a, U n) {
  a %= 1000000007;
  R res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % 1000000007;
    a = a * a % 1000000007;
    n >>= 1;
  }
  return res;
}
void precompute() {}
void solve() {
  int n;
  cin >> n;
  string s1, s2;
  cin >> s1;
  cin >> s2;
  vector<int> mex(n, 0);
  for (int i = 0; i < n; i++) {
    if (s1[i] != s2[i])
      mex[i] = 2;
    else if (s1[i] == '0')
      mex[i] = 1;
    else
      mex[i] = 0;
  }
  int ans = 0, curr_mex = 0;
  for (int i = 0; i < n; i++) {
    if (curr_mex == 0 && mex[i] == 2 || (i == 0))
      curr_mex += mex[i];
    else if (curr_mex == 0 && mex[i] == 1)
      curr_mex += 2;
    else if (curr_mex == 1 && mex[i] == 0)
      curr_mex += 1;
    else if (curr_mex >= mex[i] || (curr_mex == 1 && mex[i] == 2)) {
      ans += curr_mex;
      curr_mex = mex[i];
    }
  }
  ans += curr_mex;
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  precompute();
  while (t--) {
    solve();
  }
}
