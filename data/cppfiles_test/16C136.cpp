#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  long long int a[n];
  multiset<pair<long long int, long long int>> st;
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i]) {
      st.insert({a[i], i});
    }
  }
  vector<pair<long long int, long long int>> ans;
  while (st.size() > 1) {
    long long int il = (*st.begin()).second;
    long long int l = (*st.begin()).first;
    auto it = st.end();
    it--;
    long long int ir = (*it).second;
    long long int r = (*it).first;
    ans.push_back({il + 1, ir + 1});
    l--;
    r--;
    st.erase(it);
    st.erase(st.begin());
    if (l > 0) {
      st.insert({l, il});
    }
    if (r > 0) {
      st.insert({r, ir});
    }
  }
  cout << ans.size() << "\n";
  for (auto it : ans) {
    cout << it.first << " " << it.second << "\n";
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t, q;
  q = 1;
  cin >> q;
  for (t = 1; t <= q; t++) {
    solve();
  }
}
