#include <bits/stdc++.h>
using namespace std;
long long fun(long long n, long long k) {
  string s = to_string(n);
  long long sz = s.size();
  vector<long long> mini(sz);
  long long minimum = s[0] - '0';
  set<char> st;
  vector<long long> f(sz);
  for (long long i = 0; i < sz; i++) {
    mini[i] = min(minimum, (long long)(s[i] - '0'));
    st.insert(s[i]);
    f[i] = st.size();
  }
  if (st.size() <= k) return n;
  long long x = 10000000000007;
  long long c = 0;
  for (long long i = sz - 2; i >= 0; i--) {
    c++;
    if (f[i] == k) {
      set<long long> digits;
      for (long long j = 0; j <= i; j++) {
        st.insert(s[j] - '0');
      }
      long long d = s[i + 1] - '0';
      if (digits.lower_bound(d) != digits.end()) {
        d = *(digits.lower_bound(d));
        for (long long j = i + 1; j < sz; j++) {
          s[j] = d + '0';
        }
      } else {
        long long z = pow(10, c - 1);
        n = n / z;
        n++;
        n *= z;
        long long p = fun(n, k);
        return p;
      }
    }
  }
  return -1;
}
void solve(long long cc) {
  long long n, k;
  cin >> n >> k;
  long long x = fun(n, k);
  string s1 = to_string(x);
  string s2 = to_string(n);
  cout << x;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t = 1;
  cin >> t;
  long long c = 1;
  while (t--) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ;
    solve(c);
    c++;
    cout << endl;
  }
  return 0;
}
