#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void test_case() {
  long long n;
  cin >> n;
  if (n < 10)
    cout << n - 1 << "\n";
  else if (n < 100)
    cout << (n % 10) * 2 << "\n";
  else {
    long long a = sqrt(n);
    if (a * a == n)
      cout << a - 1;
    else
      cout << a;
    cout << "\n";
  }
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    test_case();
  }
}
