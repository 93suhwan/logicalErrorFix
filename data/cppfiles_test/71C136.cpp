#include <bits/stdc++.h>
using namespace std;
long long n, k;
string s;
long long fun(long long idx, long long nn, set<long long> &st, long long f) {
  if (st.size() > k) return 1e15;
  if (nn >= n) return nn;
  long long ans = 1e15;
  if (f) {
    if (st.size() < k) {
      ans = fun(idx + 1, nn * 10, st, 1);
    } else {
      ans = fun(idx + 1, nn * 10 + *st.begin(), st, 1);
    }
  } else {
    long long l, r;
    if (idx >= s.size()) {
      l = 0, r = 9;
    } else {
      l = s[idx] - '0';
      r = 9;
    }
    long long i = l;
    for (; l <= r; ++l) {
      long long cur;
      if (st.count(l)) {
        cur = fun(idx + 1, nn * 10 + l, st, f || l > i);
      } else {
        st.insert(l);
        cur = fun(idx + 1, nn * 10 + l, st, f || l > i);
        st.erase(l);
      }
      ans = min(ans, cur);
    }
  }
  return ans;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    s = to_string(n);
    set<long long> tt;
    cout << fun(0, 0, tt, 0) << endl;
  }
  return 0;
}
