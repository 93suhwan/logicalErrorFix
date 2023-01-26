#include <bits/stdc++.h>
const long long N = 2e5 + 5, MOD = 1e9 + 7, INF = 1e18;
using namespace std;
long long n, m, t;
set<int> graph[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    set<int> st;
    vector<long long> cnt(n + 1, 0);
    long long ans = 0, f = 1;
    for (int i = 1; i <= n; ++i) {
      cin >> cnt[i];
      if (!cnt[i]) st.insert(i);
      for (int j = 0; j < cnt[i]; ++j) {
        cin >> m;
        graph[m].insert(i);
      }
    }
    while (st.size()) {
      auto it = st.lower_bound(f);
      if (it == st.end()) {
        ans++;
        it = st.begin();
      }
      f = *it;
      for (auto child : graph[f]) {
        cnt[child]--;
        if (!cnt[child]) st.insert(child);
      }
      st.erase(f);
    }
    int ok = 1;
    for (int i = 1; i <= n; ++i)
      if (cnt[i]) ok = 0;
    cout << (ok ? ans + 1 : -1) << '\n';
    for (int i = 1; i <= n; ++i) graph[i].clear();
  }
}
