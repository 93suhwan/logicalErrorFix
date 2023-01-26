#include <bits/stdc++.h>
using namespace std;
void solve(long long tst);
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long tst;
  cin >> tst;
  for (int i = 1; i <= tst; i++) solve(tst);
}
void solve(long long tst) {
  long long n;
  cin >> n;
  set<pair<long long, long long>> st;
  for (long long i = 0, x; i < n; i++) {
    cin >> x;
    if (x) st.insert({x, i + 1});
  }
  vector<vector<long long>> ans;
  while (st.size() > 1) {
    auto sm = st.begin();
    auto lg = st.end();
    lg--;
    auto x = *sm, y = *lg;
    ans.push_back({x.second, y.second});
    st.erase(sm);
    x.first--;
    y.first--;
    st.erase(lg);
    if (x.first) st.insert(x);
    if (y.first) st.insert(y);
  }
  cout << ans.size() << '\n';
  for (auto& x : ans) cout << x[0] << ' ' << x[1] << '\n';
}
