#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long q;
  cin >> q;
  while (q--) {
    long long n;
    cin >> n;
    long long a = n / 3, b = n / 3;
    a += (n % 3 == 1);
    b += (n % 3 == 2);
    cout << a << ' ' << b;
    cout << '\n';
  }
}
