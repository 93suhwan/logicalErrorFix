#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long long MOD = 998244353;
long long add(long long x, long long y) {
  x += y;
  if (x >= MOD) {
    x -= MOD;
  }
  return x;
}
long long sub(long long x, long long y) {
  x -= y;
  if (x < 0) {
    x += MOD;
  }
  return x;
}
long long mul(long long a, long long b) { return 1LL * a * b % MOD; }
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<long long> ans(n + 1), pref(n + 1);
  ans[0] = pref[0] = 1;
  vector<long long> st;
  for (long long i = 1; i <= n; i++) {
    while (!st.empty() && a[st.back()] >= a[i - 1]) {
      st.pop_back();
    }
    long long kek = -1;
    if (!st.empty()) kek = st.back();
    st.push_back(i - 1);
    long long tmp = pref[i - 1];
    if (kek != -1) tmp = sub(tmp, pref[kek]);
    ans[i] = mul(a[i - 1], sub(0, tmp));
    if (kek != -1) {
      ans[i] = add(ans[i], ans[kek + 1]);
    }
    pref[i] = add(pref[i - 1], ans[i]);
  }
  if (n % 2) {
    ans[n] = sub(0, ans[n]);
  }
  cout << ans[n] << "\n";
}
