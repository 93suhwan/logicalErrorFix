#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long cl(long double a) {
  if (a > (long long)a) {
    return (long long)a + 1;
  } else {
    return (long long)a;
  }
}
long long flr(long double a) {
  if (a < 0.0) {
    return (long long)a - 1;
  }
  return (long long)a;
}
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
long long pw(long long n, long long k) {
  if (k == 0) return 1;
  long long t = pw(n, k / 2);
  long long ans = (t * t) % mod;
  if (k % 2)
    return (ans * n) % mod;
  else
    return ans;
}
long long n, m, k;
void solve() {
  cin >> n;
  cin >> m;
  cin >> k;
  long long l = 1;
  for (long long i = 0; i < k; i++) {
    vector<long long> res[n + 1];
    set<long long> st;
    for (long long i = 0; i < n; i++) st.insert(i + 1);
    long long k = 1;
    for (long long j = 0; j < n % m; j++) {
      for (long long f = 0; f < n / m + 1; f++) {
        st.erase(l);
        res[k].push_back(l);
        l++;
        if (l == n + 1) l = 1;
      }
      k++;
    }
    for (long long j = k; j <= m; j++) {
      for (long long l = 0; l < n / m; l++) {
        res[j].push_back(*st.begin());
        st.erase(st.begin());
      }
    }
    for (long long j = 1; j <= m; j++) {
      cout << res[j].size() << " ";
      for (auto x : res[j]) cout << x << " ";
      cout << "\n";
    }
    cout << "\n";
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  t = 1;
  cin >> t;
  while (t--) solve();
}
