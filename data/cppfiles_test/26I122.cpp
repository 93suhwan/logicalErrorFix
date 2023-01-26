#include <bits/stdc++.h>
using namespace std;
long long int fact(long long int n) {
  if (n == 0)
    return 1;
  else {
    return n * fact(n - 1);
  }
}
void solve() {
  long long int n, f;
  cin >> n;
  f = fact(2 * n);
  cout << (f / 2) % 1000000000 << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  };
  return 0;
}
