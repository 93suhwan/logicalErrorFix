#include <bits/stdc++.h>
using namespace std;
void sol() {
  long long int a, b, sum = 0, nn = 0, p = 0;
  cin >> a >> b;
  p = a - 1;
  if (p % 4 == 0) {
    sum = p;
  } else if (p % 4 == 1) {
    sum = 1;
  } else if (p % 4 == 2) {
    sum = p + 1;
  } else {
    sum = 0;
  }
  nn = sum ^ a;
  if (nn == b) {
    cout << a + 2 << "\n";
    ;
  } else if (sum == b) {
    cout << a << "\n";
  } else {
    cout << a + 1 << "\n";
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    sol();
  }
  return 0;
}
