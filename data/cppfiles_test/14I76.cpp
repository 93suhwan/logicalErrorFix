#include <bits/stdc++.h>
const int len = 1e9 + 7;
using namespace std;
void precision(int a) { cout << setprecision(a) << fixed; }
void rotate(vector<long long> &a, long long d) {
  reverse(a.begin(), a.begin() + d);
  reverse(a.begin() + d + 1, a.end());
  reverse(a.begin(), a.end());
}
void solve() {
  long long n, k = 0;
  cin >> n;
  vector<long long> a(n), b, s;
  for (long long i = 0; i < n; i++) cin >> a[i];
  b = a;
  s = a;
  if (is_sorted(a.begin(), a.end())) {
    cout << 0 << "\n";
    return;
  }
  sort(s.begin(), s.end());
  for (long long i = 0; i <= n - 1; i++) {
    if (b[i] != s[i]) {
      for (long long j = i + 1; j <= n - 1; j++) {
        if (b[j] == s[i]) {
          rotate(b, n - j);
          k++;
        }
      }
    }
  }
  cout << k << "\n";
  for (long long i = 0; i <= n - 1; i++) {
    if (a[i] != s[i]) {
      for (long long j = i + 1; j <= n - 1; j++) {
        if (a[j] == s[i]) {
          cout << i + 1 << " " << j + 1 << " " << 1 << "\n";
        }
      }
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  precision(1);
  long long t;
  cin >> t;
  while (t--) solve();
  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
