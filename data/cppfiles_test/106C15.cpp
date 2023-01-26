#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
void solve() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << 1 << endl;
    return;
  }
  for (int i = 0; i < (n); i++) {
    cout << i + 2 << " ";
  }
  cout << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
}
