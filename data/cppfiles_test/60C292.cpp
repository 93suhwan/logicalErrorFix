#include <bits/stdc++.h>
using namespace std;
long long chk(long long *b, long long n) {
  long long mx = -1;
  for (int i = 0; i < n; i++) mx = max(mx, b[i]);
  return mx;
}
void solve() {
  long long n, mx = 1000000007, c;
  cin >> n;
  long long a[n], b[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      for (int k = i, s = j; k <= j; k++, s--) b[k] &= b[s];
      c = chk(b, n);
      mx = min(mx, c);
    }
  }
  cout << mx << endl;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  int n;
  cin >> n;
  while (n--) {
    solve();
  }
  return 0;
}
