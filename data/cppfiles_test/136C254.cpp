#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<long long> v(n);
  long long sum = 0;
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
    sum += v[i];
  }
  long long x = (n * (n + 1)) / 2;
  if (sum % x != 0) {
    cout << "NO"
         << "\n";
    return;
  }
  sum /= x;
  long long temp = n;
  long long i = n - 1;
  vector<long long> ans;
  while (temp--) {
    long long a = v[i % n] - v[(i + 1) % n];
    if ((a + sum) % n != 0) {
      cout << "NO"
           << "\n";
      return;
    }
    long long b = (a + sum) / n;
    if (b < 1) {
      cout << "NO"
           << "\n";
      return;
    }
    ans.push_back(b);
    i++;
  }
  cout << "YES"
       << "\n";
  for (long long i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  cout << "\n";
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
