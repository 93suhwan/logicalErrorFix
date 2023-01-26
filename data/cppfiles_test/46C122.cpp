#include <bits/stdc++.h>
using namespace std;
mt19937_64 rang(
    chrono::high_resolution_clock::now().time_since_epoch().count());
long long rng(long long lim) {
  uniform_int_distribution<long long> uid(0, lim - 1);
  return uid(rang);
}
bool comparison(const pair<long long, long long> &a,
                const pair<long long, long long> &b) {
  return a.second < b.second;
}
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  srand(chrono::high_resolution_clock::now().time_since_epoch().count());
  long long t = 1;
  cin >> t;
  while (t--) {
    long long n, ans = 0;
    cin >> n;
    vector<long long> ar(n);
    for (long long i = 0; i < n; i++) {
      cin >> ar[i];
      ans = max(ans, ar[i]);
    }
    long long q = 0, cur = ar[n - 1];
    n -= 2;
    while (cur != ans) {
      if (ar[n] > cur) {
        cur = ar[n];
        q++;
      }
      n--;
    }
    ans = q;
    cout << ans << "\n";
  }
}
