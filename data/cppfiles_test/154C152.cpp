#include <bits/stdc++.h>
using namespace std;
void solve(int test_case) {
  int a, b, c;
  cin >> a >> b >> c;
  if (a + b == c || b + c == a || a + c == b) {
    cout << "YES\n";
  } else {
    if (a == b && c % 2 == 0) {
      cout << "YES\n";
    } else if (b == c && a % 2 == 0) {
      cout << "YES\n";
    } else if (a == c && b % 2 == 0) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
int main() {
  int t, test_case = 0;
  cin >> t;
  while (t--) solve(test_case++);
}
