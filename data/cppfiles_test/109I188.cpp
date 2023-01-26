#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
void test_case() {
  long long n;
  cin >> n;
  vector<long long> a(n), b(n);
  for (long long i = (0); i < (n); ++i) {
    cin >> a[i];
  }
  for (long long i = (0); i < (n); ++i) {
    cin >> b[i];
  }
  if (a[0] < b[0]) {
    cout << "0\n";
  } else {
    for (long long i = 1; i < n; i++) {
      if (a[i] < b[0]) {
        cout << i << '\n';
        return;
      }
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  for (long long i = 1; i <= t; i++) {
    test_case();
  }
}
