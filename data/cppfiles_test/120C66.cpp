#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
  return os << '(' << p.first << ", " << p.second << ')';
}
template <typename T_container, typename T = typename enable_if<
                                    !is_same<T_container, string>::value,
                                    typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v) {
  os << '{';
  string sep;
  for (const T &x : v) os << sep << x, sep = ", ";
  return os << '}';
}
void dbg_out() { cerr << '\n'; }
template <typename Up, typename... Down>
void dbg_out(Up U, Down... D) {
  cerr << ' ' << U;
  dbg_out(D...);
}
const int N = 2e5 + 10;
int pref[N][30];
bool check_bit(int x, int pos) { return (x & (1 << pos)); }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  for (int i = 1; i < N; i++) {
    for (int j = 0; j < 30; j++) {
      if (check_bit(i, j)) {
        pref[i][j] = (pref[i - 1][j] + 1);
      } else
        pref[i][j] = pref[i - 1][j];
    }
  }
  int tt;
  cin >> tt;
  while (tt--) {
    int l, r;
    cin >> l >> r;
    int arr[30] = {0};
    for (int i = 0; i < 30; i++) {
      arr[i] = pref[r][i] - pref[l - 1][i];
    }
    int tot = r - l + 1;
    int ans = INT_MAX;
    for (int i = 0; i < 30; i++) {
      ans = min(tot - arr[i], ans);
    }
    cout << ans << '\n';
  }
  return 0;
}
