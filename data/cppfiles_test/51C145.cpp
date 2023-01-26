#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (a == 0) {
    return b;
  }
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
void solve() {
  long long n;
  cin >> n;
  cout << (1 - n) << " " << n;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
}
