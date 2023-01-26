#include <bits/stdc++.h>
using namespace std;
const unsigned int M = 1000000007;
long long binpow(long long a, long long b);
long long modmul(long long a, long long b, long long m);
void solve() {
  long long n, x, ans = 0;
  cin >> n;
  multiset<long long> st;
  for (long long i = 0; i < n; i++) {
    cin >> x;
    st.insert(x);
  }
  for (x = n; x > 0; x--) {
    auto it = st.find(x);
    if (it != st.end()) {
      st.erase(it);
      continue;
    }
    it--;
    if (*it < 2 * x + 1) {
      cout << "-1\n";
      return;
    }
    st.erase(it);
    ans++;
  }
  cout << ans << '\n';
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
long long binpow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % M;
    a = a * a % M;
    b >>= 1;
  }
  return res;
}
long long modmul(long long a, long long b, long long m) {
  return ((a % m) * (b % m)) % m;
}
