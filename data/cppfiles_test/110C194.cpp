#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<vector<int>> vc(n);
  vector<int> cnt(n);
  set<int> st;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    cnt[i] = x;
    if (x == 0) {
      st.insert(i);
    }
    for (int j = 0; j < x; ++j) {
      int y;
      cin >> y;
      vc[y - 1].push_back(i);
    }
  }
  int last = 0, ans = 1;
  for (int i = 0; i < n; ++i) {
    if (st.empty()) {
      cout << "-1\n";
      return;
    }
    auto it = st.lower_bound(last);
    if (it == end(st)) {
      ++ans;
      it = begin(st);
    }
    int j = *it;
    st.erase(it);
    for (const int& cur : vc[j]) {
      --cnt[cur];
      if (cnt[cur] == 0) {
        st.insert(cur);
      }
    }
    last = j;
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
