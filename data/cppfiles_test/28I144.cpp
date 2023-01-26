#include <bits/stdc++.h>
using namespace std;
void fastio() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
bool cmp(int a, int b) { return a > b; }
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
void solve() {
  int a[3];
  cin >> a[0] >> a[1] >> a[2];
  sort(a, a + 3);
  cout << max(a[2] - a[1], a[1] - a[0]);
}
int main() {
  fastio();
  int t;
  cin >> t;
  while (t--) {
    solve();
    cout << endl;
  }
  return 0;
}
