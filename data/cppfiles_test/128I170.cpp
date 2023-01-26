#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n = 18;
  cin >> n;
  int a, b, c;
  for (int i = 2; i * i <= n; i++) {
    a = i;
    b = n - i - 1;
    c = 1;
    if (a + b + c == n) {
      break;
    }
  }
  cout << a << " " << b << " " << c << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
