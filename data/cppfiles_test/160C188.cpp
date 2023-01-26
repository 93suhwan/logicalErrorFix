#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m, ans = 0;
  pair<int, int> st, bad;
  cin >> n >> m >> st.first >> st.second >> bad.first >> bad.second;
  int dx = 1, dy = 1;
  while (st.first != bad.first and st.second != bad.second) {
    if (st.first == n) dx *= -1;
    if (st.second == m) dy *= -1;
    st.first += dx, st.second += dy;
    ans++;
  }
  cout << ans << endl;
}
int main() {
  int tc;
  cin >> tc;
  while (tc--) solve();
}
