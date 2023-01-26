#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<long long> v(n);
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
  }
  sort((v).begin(), (v).end());
  long long sum = 0;
  long long mn = 1e7;
  for (long long i = 0; i < n; i++) {
    sum += v[i];
  }
  if (sum % n == 0) {
    cout << 0 << "\n";
  } else
    cout << 1 << "\n";
}
int32_t main() {
  cin.tie(0);
  cout.tie(NULL);
  ios_base::sync_with_stdio(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
