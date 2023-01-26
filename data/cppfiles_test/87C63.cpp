#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const long long mod = 1e9 + 7;
void soln() {
  long long n;
  cin >> n;
  long long array[n + 1];
  long long ans = 0;
  for (long long i = 1; i <= n; i++) {
    cin >> array[i];
    long long x = i - array[i];
    if (x < 0) ans = max(ans, -1LL * x);
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  long long testcase;
  testcase = 1;
  cin >> testcase;
  while (testcase--) {
    soln();
  }
  return 0;
}
