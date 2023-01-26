#include <bits/stdc++.h>
using namespace std;
const long long N = 200005;
const long long M = 1000000007;
long long pow1(long long a, long long b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = (res * a) % M;
    }
    a = (a * a) % M;
    b >>= 1;
  }
  return res % M;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long T;
  T = 1;
  cin >> T;
  while (T--) {
    long long n;
    cin >> n;
    vector<long long> v1(n), v2(n);
    for (long long i = 0; i < n; i++) cin >> v1[i];
    for (long long i = 0; i < n; i++) cin >> v2[i];
    vector<long long> pref1(n, v1[0]);
    vector<long long> pref2(n, v2[0]);
    for (long long i = 1; i < n; i++) {
      pref1[i] = v1[i] + pref1[i - 1];
      pref2[i] = v2[i] + pref2[i - 1];
    }
    long long ans = 9e17;
    for (long long i = 0; i < n; i++) {
      if (i == 0) {
        ans = min(ans, pref1[n - 1] - v1[0]);
      } else if (i == n - 1) {
        ans = min(ans, pref2[n - 2]);
      } else {
        long long res = max(pref2[i - 1], pref1[n - 1] - pref1[i]);
        ans = min(ans, res);
      }
    }
    cout << ans << "\n";
  }
}
