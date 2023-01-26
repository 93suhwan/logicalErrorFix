#include <bits/stdc++.h>
using namespace std;
long long fun(long long n) {
  if (n % 4 == 0) return n;
  if (n % 4 == 1) return 1;
  if (n % 4 == 2) return n + 1;
  return 0;
}
void solve() {
  long long a, b, x = 0;
  cin >> a >> b;
  long long c = a;
  if (a == 1) {
    if (b == 1) {
      c += 2;
    } else {
      c++;
    }
    cout << c << "\n";
    return;
  }
  x = fun(a - 1);
  if (x != b) c++;
  cout << c << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
}
