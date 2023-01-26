#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
void solve() {
  long long n;
  cin >> n;
  vector<pair<long long, long long>> v;
  for (long long i = 0; i < n; i++) {
    long long x;
    cin >> x;
    v.push_back({x, i + 1});
  }
  sort((v).begin(), (v).end());
  stack<pair<long long, long long>> st;
  for (long long i = 0; i < n; i++) {
    st.push({v[i].first, v[i].second});
  }
  vector<pair<long long, long long>> ans;
  while (st.size() > 1) {
    auto p1 = st.top();
    st.pop();
    auto p2 = st.top();
    st.pop();
    if (p1.first > p2.first) {
      for (long long i = 0; i < p2.first; i++)
        ans.push_back({p1.second, p2.second});
      p1.first -= p2.first;
      st.push(p1);
    } else {
      for (long long i = 0; i < p1.first; i++)
        ans.push_back({p1.second, p2.second});
      p2.first -= p1.first;
      if (p2.first != 0) st.push(p2);
    }
  }
  cout << ans.size() << endl;
  for (long long i = 0; i < ans.size(); i++) {
    cout << ans[i].first << " " << ans[i].second << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
