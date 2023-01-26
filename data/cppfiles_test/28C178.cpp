#include <bits/stdc++.h>
using namespace std;
long long n, t, a, b, c;
int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(false);
  cin >> t;
  while (t--) {
    cin >> a >> b >> c;
    long long s = a + 2 * b + 3 * c;
    if (s % 2 == 0)
      cout << 0 << "\n";
    else
      cout << 1 << "\n";
  }
}
