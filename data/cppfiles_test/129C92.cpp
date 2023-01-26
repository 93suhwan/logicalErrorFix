#include <bits/stdc++.h>
using namespace std;
void testcase() {
  long long n;
  cin >> n;
  set<long long> st;
  for (long long i = 1; i <= n; i++) st.insert(i);
  vector<long long> v;
  for (long long i = 0; i < n; i++) {
    long long k;
    cin >> k;
    if (st.find(k) != st.end())
      st.erase(k);
    else
      v.push_back(k);
  }
  sort(v.rbegin(), v.rend());
  bool ok = false;
  for (auto x : v) {
    auto it = st.end();
    it--;
    if ((*it) > (x - 1) / 2) {
      ok = true;
      break;
    }
    st.erase(it);
  }
  if (ok)
    cout << -1 << '\n';
  else
    cout << v.size() << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    testcase();
  }
  return 0;
}
