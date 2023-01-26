#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, a, b;
    cin >> n;
    a = n / 3 + 1;
    b = n / 3;
    if (n % 3 == 0) a = b = n / 3;
    if (a + b * 2 != n) swap(a, b);
    cout << a << ' ' << b << "\n";
  }
  return 0;
}
