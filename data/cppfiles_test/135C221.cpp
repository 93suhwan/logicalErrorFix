#include <bits/stdc++.h>
using namespace std;
void solution() {
  long long n;
  long long k;
  cin >> n >> k;
  vector<long long> v(n);
  for (long long i = 0; i < n; i++) cin >> v[i];
  long long sum = 0;
  sort(v.begin(), v.end());
  for (long long i = 0; i < (k); i++) {
    sum += (v[n - k - 1 - i] / v[n - 1 - i]);
  }
  for (long long i = 0; i < n - 2 * k; i++) sum += v[i];
  cout << sum << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) solution();
  return 0;
}
