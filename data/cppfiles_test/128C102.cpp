#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int a, b, c = 1;
  n -= c;
  if (n % 2) {
    a = n / 2;
    b = n / 2 + 1;
  } else {
    if ((n / 2) % 2) {
      a = n / 2 - 2, b = n / 2 + 2;
    } else {
      a = n / 2 - 1, b = n / 2 + 1;
    }
  }
  cout << a << " " << b << " " << c << "\n";
}
int main() {
  { ios_base::sync_with_stdio(false); }
  { cin.tie(NULL); }
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
