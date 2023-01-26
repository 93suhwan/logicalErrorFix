#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
long long int fact(long long int n) {
  for (long long int i = 2; i * i <= n; i++)
    if (n % i == 0) return 1;
  return 0;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int TESTCASE;
  cin >> TESTCASE;
  while (TESTCASE--) {
    long long int n;
    cin >> n;
    vector<long long int> a(n);
    for (long long int INPUT = 0; INPUT < n; INPUT++) cin >> a[INPUT];
    vector<long long int> b = a;
    for (long long int i = 1; i < n; i++) b[i] += b[i - 1];
    pair<long long int, long long int> mx = {0, 0};
    for (long long int i = 0; i < n; i++) {
      for (long long int j = i; j < n; j++) {
        long long int sum = b[j] - (i == 0 ? 0 : b[i - 1]);
        if (fact(sum))
          if (mx.second - mx.first < j - i) mx = {i, j};
      }
    }
    cout << mx.second - mx.first + 1 << "\n";
    for (long long int i = mx.first; i <= mx.second; i++) cout << a[i] << " ";
    cout << "\n";
  }
  return 0;
}
