#include <bits/stdc++.h>
using namespace std;
void solve(long long int caseno) {
  long long int i, j, n, m = -1;
  cin >> n;
  vector<long long int> arr(n);
  for (i = 0; i < n; i++) {
    cin >> arr[i];
    m = max(m, arr[i]);
  }
  for (auto a : arr) {
    m = m & a;
  }
  cout << m << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t = 1;
  cin >> t;
  for (long long int i = 1; i <= t; i++) {
    solve(i);
  }
  return 0;
}
