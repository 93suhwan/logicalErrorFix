#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
int compXOR(int n) {
  if (n % 4 == 0) return n;
  if (n % 4 == 1) return 1;
  if (n % 4 == 2) return n + 1;
  return 0;
}
int XOR(int x, int y) { return (x | y) & (~x | ~y); }
void solve() {
  int a, b;
  cin >> a >> b;
  int X = compXOR(a - 1);
  int ans = a;
  if (X == b)
    ans = a;
  else {
    if (X == 0 && b <= a)
      ans += 2;
    else if (X == 0 && b > a)
      ans++;
    else if (XOR(X, b) != 0)
      ans++;
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
