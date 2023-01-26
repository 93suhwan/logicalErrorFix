#include <bits/stdc++.h>
using namespace std;
void solve(long long testcase) {
  long long n;
  cin >> n;
  long long idx = 3;
  for (long long i = 0; i < n; i++) {
    cout << idx << " ";
    idx += 2;
  }
  cout << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  long long x = 1;
  cin >> x;
  for (long long i = 1; i <= x; i++) solve(i);
  return 0;
}
