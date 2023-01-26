#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n];
    for (auto &x : a) cin >> x;
    ;
    set<pair<long long, long long>> st;
    vector<pair<long long, long long>> res;
    for (long long i = 0; i < n; ++i) st.insert({a[i], i + 1});
    while (st.size() > 1) {
      auto it1 = st.end();
      auto it2 = st.begin();
      it1--;
      pair<long long, long long> pmax = *it1;
      pair<long long, long long> pmin = *it2;
      st.erase(it1);
      st.erase(it2);
      long long freq1 = pmax.first, val1 = pmax.second;
      long long freq2 = pmin.first, val2 = pmin.second;
      if (freq1 > 0 && freq2 > 0) {
        res.push_back({val2, val1});
        freq1--, freq2--;
        if (freq1 > 0) st.insert({freq1, val1});
        if (freq2 > 0) st.insert({freq2, val2});
      } else if (freq1 > 0)
        st.insert({freq1, val1});
      else
        st.insert({freq2, val2});
    }
    cout << res.size() << "\n";
    for (pair<long long, long long> x : res)
      cout << x.first << " " << x.second << "\n";
  }
  return 0;
}
