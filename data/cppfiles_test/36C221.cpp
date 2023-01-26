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
    long long int sum = 0;
    for (long long int i : a) sum += i;
    long long int odd = -1;
    for (long long int i = 0; i < n; i++) {
      if (a[i] % 2) odd = i;
    }
    if (fact(sum)) {
      cout << n << "\n";
      for (long long int i = 1; i <= n; i++) cout << i << " ";
      cout << "\n";
      continue;
    } else {
      cout << n - 1 << "\n";
      for (long long int i = 0; i < n; i++) {
        if (i == odd) continue;
        cout << i + 1 << " ";
      }
      cout << "\n";
    }
  }
  return 0;
}
