#include <bits/stdc++.h>
using namespace std;
void solve(long long testcase) {
  long long n;
  cin >> n;
  long long a[n], sum = 0;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  if (sum % n == 0)
    cout << "0" << '\n';
  else
    cout << "1" << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  long long x = 1;
  cin >> x;
  for (long long i = 1; i <= x; i++) solve(i);
  return 0;
}
