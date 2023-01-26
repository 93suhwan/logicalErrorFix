#include <bits/stdc++.h>
using namespace std;
void solve();
long long int f(long long int n) {
  for (long long int i = 2; i <= n + 1; i++) {
    if (n % i != 0) return i;
  }
  return 2;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t_;
  cin >> t_;
  for (int t__ = 0; t__ < t_; t__++) {
    solve();
  }
  return 0;
}
void solve() {
  long long int n;
  cin >> n;
  vector<long long int> arr(n);
  for (int i = 0; i < n; i++) cin >> arr[i];
  bool b = true;
  for (long long int i = 0; i < n; i++) {
    if (f(arr[i]) > (i + 2)) {
      b = false;
      break;
    }
  }
  if (b)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
