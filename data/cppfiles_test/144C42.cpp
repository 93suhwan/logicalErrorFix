#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  set<pair<int, int> > st;
  for (int i = 1; i <= n; i++) {
    st.insert({0, i});
  }
  int big = n % m, small = m - big;
  int bc = (n / m) + (n % m != 0);
  int mc = n / m;
  for (int i = 1; i <= k; i++) {
    vector<bool> used(n + 1);
    for (int t = 1; t <= big; t++) {
      cout << bc << ' ';
      for (int j = 1; j <= bc; j++) {
        pair<int, int> cur = *(st.begin());
        st.erase(cur);
        cur.first++;
        used[cur.second] = 1;
        cout << cur.second << ' ';
        st.insert(cur);
      }
      cout << '\n';
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      if (!used[i]) {
        if (cnt == 0) cout << mc << ' ';
        cout << i << ' ';
        cnt++;
      }
      if (cnt == mc) {
        cout << '\n';
        cnt = 0;
      }
    }
  }
  cout << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
